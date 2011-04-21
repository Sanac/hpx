//  Copyright (c) 2007-2011 Hartmut Kaiser
//  Copyright (c) 2011 Bryce Lelbach
// 
//  Distributed under the Boost Software License, Version 1.0. (See accompanying 
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(HPX_583D0662_CA9D_4241_805C_93F92D727E6E)
#define HPX_583D0662_CA9D_4241_805C_93F92D727E6E

#include <map>
#include <memory>

#include <hpx/util/block_profiler.hpp>
#include <hpx/runtime/threads/thread.hpp>
#include <hpx/runtime/threads/policies/queue_helpers.hpp>

#include <boost/thread/condition.hpp>
#include <boost/bind.hpp>
#include <boost/atomic.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/lockfree/deque.hpp>
#include <boost/lockfree/fifo.hpp>
#include <boost/ptr_container/ptr_map.hpp>

// TODO: add branch prediction and function heat

///////////////////////////////////////////////////////////////////////////////
namespace hpx { namespace threads { namespace policies
{
    
typedef boost::lockfree::deque<thread*> work_item_deque_type;

template <typename Queue, typename Value>
inline void enqueue(Queue& workqueue, Value val)
{ workqueue.push_left(val); }

template <typename Queue, typename Value>
inline bool dequeue(Queue& workqueue, Value val)
{ return workqueue.pop_left(val); }

template <typename Queue, typename Value>
inline bool steal(Queue& workqueue, Value val)
{ return workqueue.pop_right(val); }

///////////////////////////////////////////////////////////////////////////
struct thread_deque
{
  private:
    // we use a simple mutex to protect the data members for now
    typedef boost::mutex mutex_type;

    // Add this number of threads to the work items queue each time the 
    // function \a add_new() is called if the queue is empty.
    enum { 
        min_add_new_count = 100, 
        max_add_new_count = 100,
        max_delete_count = 100
    };

    // this is the type of the queues of new or pending threads
    typedef work_item_deque_type work_items_type;

    // this is the type of a map holding all threads (except depleted ones)
    typedef boost::ptr_map<
        thread_id_type, thread, std::less<thread_id_type>, heap_clone_allocator
    > thread_map_type;

    // this is the type of the queue of new tasks not yet converted to
    // threads
    typedef boost::tuple<thread_init_data, thread_state_enum> task_description;

    typedef boost::lockfree::deque<task_description const*> task_items_type;

    typedef boost::lockfree::fifo<thread_id_type> thread_id_queue_type;

  protected:
    // add new threads if there is some amount of work available
    std::size_t add_new(long add_count)
    {
        if (0 == add_count)
            return 0;

        std::size_t added = 0;
        task_description const* task = 0;

        while (add_count-- && dequeue(new_tasks_, &task)) 
        {
            --new_tasks_count_;

            // measure thread creation time
            util::block_profiler_wrapper<add_new_tag> bp(add_new_logger_);

            // create the new thread
            thread_state_enum state = boost::get<1>(*task);
            std::auto_ptr<threads::thread> thrd(
                new (memory_pool_) threads::thread(
                    boost::get<0>(*task), memory_pool_, state));

            delete task;

            // add the new entry to the map of all threads
            thread_id_type id = thrd->get_thread_id();
            std::pair<thread_map_type::iterator, bool> p =
                thread_map_.insert(id, thrd.get());

            if (!p.second) {
                HPX_THROW_EXCEPTION(hpx::no_success, 
                    "threadmanager::add_new", 
                    "Couldn't add new thread to the map of threads");
                return 0;
            }

            // transfer ownership to map
            threads::thread* t = thrd.release();

            // only insert the thread into the work-items queue if it is in 
            // pending state
            if (state == pending) {
                // pushing the new thread into the pending queue of the
                // specified thread_queue
                ++added;
                enqueue(work_items_, t);
                ++work_items_count_;
            }
        }

        if (added) 
            LTM_(info) << "add_new: added " << added << " tasks to queues";

        return added;
    }
    
    // steal new threads if there is some amount of work available
    std::size_t steal_new(long add_count, thread_deque* addfrom)
    {
        if (0 == add_count)
            return 0;

        std::size_t added = 0;
        task_description const* task = 0;

        while (add_count-- && steal(addfrom->new_tasks_, &task)) 
        {
            --addfrom->new_tasks_count_;

            // measure thread creation time
            util::block_profiler_wrapper<add_new_tag> bp(add_new_logger_);

            // create the new thread
            thread_state_enum state = boost::get<1>(*task);
            std::auto_ptr<threads::thread> thrd(
                new (memory_pool_) threads::thread(
                    boost::get<0>(*task), memory_pool_, state));

            delete task;

            // add the new entry to the map of all threads
            thread_id_type id = thrd->get_thread_id();
            std::pair<thread_map_type::iterator, bool> p =
                thread_map_.insert(id, thrd.get());

            if (!p.second) {
                HPX_THROW_EXCEPTION(hpx::no_success, 
                    "threadmanager::add_new", 
                    "Couldn't add new thread to the map of threads");
                return 0;
            }

            // transfer ownership to map
            threads::thread* t = thrd.release();

            // only insert the thread into the work-items queue if it is in 
            // pending state
            if (state == pending) {
                // pushing the new thread into the pending queue of the
                // specified thread_queue
                ++added;
                enqueue(work_items_, t);
                ++work_items_count_;
            }
        }

        if (added) 
            LTM_(info) << "add_new: added " << added << " tasks to queues";

        return added;
    }
    
    long compute_count(thread_deque* addfrom_ = 0)
    {
        thread_deque* addfrom = addfrom_ ? addfrom_ : this;

        // create new threads from pending tasks (if appropriate)
        long add_count = -1; // default is no constraint

        // if we are desperate (no work in the queues), add some even if the 
        // map holds more than max_count
        if (max_count_) {
            std::size_t count = thread_map_.size();
            if (max_count_ >= count + min_add_new_count) {
                add_count = max_count_ - count;
                if (add_count < min_add_new_count)
                    add_count = min_add_new_count;
                if (add_count > max_add_new_count)
                    add_count = max_add_new_count;
            }
            else if (work_items_.empty()) {
                add_count = min_add_new_count;    // add this number of threads
                max_count_ += min_add_new_count;  // increase max_count
            }
            else {
                LTM_(debug) << "entered";
                add_count = 0;
            }
        }

        return add_count;
    }

  public:
    // This function makes sure all threads which are marked for deletion
    // (state is terminated) are properly destroyed
    bool cleanup_terminated()
    {
        {
            // delete only this many threads
            long delete_count = max_delete_count; 
            thread_id_type todelete;
            while (delete_count && terminated_items_.dequeue(&todelete)) 
            {
                if (thread_map_.erase(todelete))
                    --delete_count;
            }
        }
        return thread_map_.empty();
    }

    // The maximum number of active threads this thread manager should
    // create. This number will be a constraint only as long as the work
    // items queue is not empty. Otherwise the number of active threads 
    // will be incremented in steps equal to the \a min_add_new_count
    // specified above.
    enum { max_thread_count = 1000 };

    thread_deque(std::size_t max_count = max_thread_count)
      : work_items_(),
        work_items_count_(0),
        terminated_items_(), 
        max_count_((0 == max_count) ? max_thread_count : max_count),
        new_tasks_count_(0),
        add_new_logger_("thread_deque::add_new")
    {}

    void set_max_count(std::size_t max_count = max_thread_count)
    { max_count_ = (0 == max_count) ? max_thread_count : max_count; }

    // This returns the current length of the queues (work items and new items)
    boost::int64_t get_queue_lengths() const
    { return work_items_count_ + new_tasks_count_; }

    // create a new thread and schedule it if the initial state is equal to 
    // pending
    thread_id_type create_thread(thread_init_data& data, 
        thread_state_enum initial_state, bool run_now, error_code& ec)
    {
        if (run_now) {
            mutex_type::scoped_lock lk(mtx_);

            std::auto_ptr<threads::thread> thrd (
                new (memory_pool_) threads::thread(
                    data, memory_pool_, initial_state));

            // add a new entry in the map for this thread
            thread_id_type id = thrd->get_thread_id();
            std::pair<thread_map_type::iterator, bool> p =
                thread_map_.insert(id, thrd.get());

            if (!p.second) {
                HPX_THROWS_IF(ec, hpx::no_success, 
                    "threadmanager::register_thread", 
                    "Couldn't add new thread to the map of threads");
                return invalid_thread_id;
            }

            // push the new thread in the pending queue thread
            if (initial_state == pending) 
                schedule_thread(thrd.get());

            thrd.release(); // release ownership to the map

            // return the thread_id of the newly created thread
            return id;
        }

        // do not execute the work, but register a task description for 
        // later thread creation
        ++new_tasks_count_;
        enqueue(new_tasks_, new task_description(data, initial_state));
        return invalid_thread_id; // thread has not been created yet
    }

    bool get_next_thread(threads::thread** thrd)
    {
        if (dequeue(work_items_, thrd)) {
            --work_items_count_;
            return true;
        }
        return false;
    }

    bool steal_next_thread(threads::thread** thrd)
    {
        if (steal(work_items_, thrd)) {
            --work_items_count_;
            return true;
        }
        return false;
    }

    // Schedule the passed thread
    void schedule_thread(threads::thread* thrd)
    {
        enqueue(work_items_, thrd);
        ++work_items_count_;
    }

    // Destroy the passed thread as it has been terminated
    bool destroy_thread(threads::thread* thrd)
    {
        if (thrd->is_created_from(&memory_pool_)) {
            thread_id_type id = thrd->get_thread_id();
            terminated_items_.enqueue(id);
            return true;
        }
        return false;
    }

    // Return the number of existing threads, regardless of their state
    boost::uint64_t get_thread_count() const
    { return thread_map_.size(); }

    // return the number of existing threads with given state
    boost::uint64_t get_thread_count(thread_state_enum state) const
    {
        if (state == unknown)
            return thread_map_.size();

        boost::uint64_t num_threads = 0;
        thread_map_type::const_iterator end = thread_map_.end();
        for (thread_map_type::const_iterator it = thread_map_.begin();
              it != end; ++it)
        {
            if ((*it).second->get_state() == state)
                ++num_threads;
        }
        return num_threads;
    }

    ///////////////////////////////////////////////////////////////////////////
    void abort_all_suspended_threads(std::size_t /*num_thread*/)
    {
        thread_map_type::iterator end =  thread_map_.end();
        for (thread_map_type::iterator it = thread_map_.begin();
              it != end; ++it)
        {
            if ((*it).second->get_state() == suspended) {
                (*it).second->set_state(pending);
                (*it).second->set_state_ex(wait_abort);
                schedule_thread((*it).second);
            }
        }
    }

    bool add_new_or_terminate(std::size_t num_thread, bool running, 
                              std::size_t& added)
    {
        if (0 == work_items_count_) {
            detail::try_lock_wrapper<mutex_type> lk(mtx_);
            if (!lk)
                return false;

            // this thread acquired the lock, do maintenance and finally
            // call wait() if no work is available
//            LTM_(info) << "tfunc(" << num_thread << "): queues empty"
//                       << ", threads left: " << thread_map_.size();

            std::size_t addednew = add_new(compute_count());
            added += addednew;

            // stop running after all PX threads have been terminated
            if (!(added != 0) && !running) {
                // Before exiting each of the OS threads deletes the 
                // remaining terminated PX threads 
                if (cleanup_terminated())
                    return true; 

                LTM_(info) << "tfunc(" << num_thread 
                           << "): threadmap not empty";
            }

            else {
                cleanup_terminated();
                return false;
            }
        }

        return false;
    }
    
    bool steal_new_or_terminate(std::size_t num_thread, bool running, 
                                std::size_t& added, thread_deque* addfrom)
    {
        if (0 == work_items_count_) {
            detail::try_lock_wrapper<mutex_type> lk(mtx_);
            if (!lk)
                return false;

            // this thread acquired the lock, do maintenance and finally
            // call wait() if no work is available
//            LTM_(info) << "tfunc(" << num_thread << "): queues empty"
//                       << ", threads left: " << thread_map_.size();

            std::size_t addednew = steal_new(compute_count(addfrom), addfrom);
            added += addednew;

            // stop running after all PX threads have been terminated
            if (!(added != 0) && !running) {
                // Before exiting each of the OS threads deletes the 
                // remaining terminated PX threads 
                if (cleanup_terminated())
                    return true; 

                LTM_(info) << "tfunc(" << num_thread 
                           << "): threadmap not empty";
            }

            else {
                cleanup_terminated();
                return false;
            }
        }

        return false;
    }

    // no-op for local scheduling
    void do_some_work() { }

    ///////////////////////////////////////////////////////////////////////
    bool dump_suspended_threads(std::size_t num_thread
      , std::size_t& idle_loop_count, bool running)
    {
        mutex_type::scoped_lock lk(mtx_);
        return detail::dump_suspended_threads(num_thread, thread_map_
          , idle_loop_count, running);
    }

    ///////////////////////////////////////////////////////////////////////
    void on_start_thread(std::size_t num_thread) {}
    void on_stop_thread(std::size_t num_thread)
    {
        if (0 == num_thread) {
            // print queue statistics
            log_fifo_statistics(work_items_, "thread_deque");
            log_fifo_statistics(terminated_items_, "thread_deque");
            log_fifo_statistics(new_tasks_, "thread_deque");
        }
    }
    void on_error(std::size_t num_thread, boost::exception_ptr const& e) {}

private:
    friend class local_queue_scheduler;

    mutable mutex_type mtx_;            ///< mutex protecting the members
    boost::condition cond_;             ///< used to trigger some action

    thread_map_type thread_map_;        ///< mapping of thread id's to PX-threads
    work_items_type work_items_;        ///< list of active work items
    boost::atomic<long> work_items_count_;    ///< count of active work items
    thread_id_queue_type terminated_items_;   ///< list of terminated threads

    std::size_t max_count_;             ///< maximum number of existing PX-threads
    task_items_type new_tasks_;         ///< list of new tasks to run
    boost::atomic<long> new_tasks_count_;     ///< count of new tasks to run

    threads::thread_pool memory_pool_;  ///< OS thread local memory pools for
                                        ///< PX-threads 

    util::block_profiler<add_new_tag> add_new_logger_;
};

}}}

#endif // HPX_583D0662_CA9D_4241_805C_93F92D727E6E

