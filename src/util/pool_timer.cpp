//  Copyright (c) 2016 Bibek Wagle
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <hpx/config.hpp>
#include <hpx/exception.hpp>
#include <hpx/runtime.hpp>
#include <hpx/runtime/applier/applier.hpp>
#include <hpx/runtime/shutdown_function.hpp>
#include <hpx/util/assert.hpp>
#include <hpx/util/bind.hpp>
#include <hpx/util/chrono_traits.hpp>
#include <hpx/util/function.hpp>
#include <hpx/util/io_service_pool.hpp>
#include <hpx/util/pool_timer.hpp>
#include <hpx/util/steady_clock.hpp>
#include <hpx/util/unlock_guard.hpp>
#include <hpx/lcos/local/spinlock.hpp>

#include <boost/asio/deadline_timer.hpp>

#include <chrono>
#include <memory>
#include <mutex>
#include <string>

namespace hpx { namespace util { namespace detail
{
    ///////////////////////////////////////////////////////////////////////////
    class pool_timer
      : public std::enable_shared_from_this<pool_timer>
    {
    private:
        friend class util::pool_timer;

        typedef lcos::local::spinlock mutex_type;

    public:
        pool_timer();
        pool_timer(util::function_nonser<bool()> const& f,
            util::function_nonser<void()> const& on_term,
            util::steady_time_point const& abs_time,
            std::string const& description,
            bool pre_shutdown);

        ~pool_timer();

        bool start(bool evaluate);
        bool stop();

        bool is_started() const { return is_started_; }
        bool is_terminated() const { return is_terminated_; }
        void timer_handler();

        void terminate();             // handle system shutdown
        bool stop_locked();

    private:
        typedef boost::asio::basic_deadline_timer<
            util::steady_clock,
            util::chrono_traits<util::steady_clock>
        > deadline_timer;

        mutable mutex_type mtx_;
        util::function_nonser<bool()> f_; ///< function to call
        util::function_nonser<void()> on_term_; ///< function to call on termination
        util::steady_clock::time_point abs_time_;    ///< time interval
        std::string description_;     ///< description of this interval timer

        bool pre_shutdown_;           ///< execute termination during pre-shutdown
        bool is_started_;             ///< timer has been started (is running)
        bool first_start_;
        ///^ flag to distinguish first invocation of start()
        bool is_terminated_;          ///< The timer has been terminated
        bool is_stopped_;
        deadline_timer* timer_;
    };

    ///////////////////////////////////////////////////////////////////////////
    pool_timer::pool_timer()
      : pre_shutdown_(), is_started_(false), first_start_(true),
        is_terminated_(false), is_stopped_(false),
        timer_(new deadline_timer(
            hpx::get_runtime().get_thread_pool("timer_pool")->get_io_service())
        )
    {}

    pool_timer::pool_timer(util::function_nonser<bool()> const& f,
            util::function_nonser<void()> const& on_term,
            util::steady_time_point const& abs_time,
            std::string const& description,
            bool pre_shutdown)
      : f_(f), on_term_(on_term),
        abs_time_(abs_time.value()), description_(description),
        pre_shutdown_(pre_shutdown), is_started_(false), first_start_(true),
        is_terminated_(false), is_stopped_(false),
        timer_(new deadline_timer(
            hpx::get_runtime().get_thread_pool("timer_pool")->get_io_service())
        )
    {}

    void pool_timer::timer_handler()
    {
        if(!is_stopped_ || !is_terminated_)
        {
            is_started_ = false;
            f_();
        }
    }

    bool pool_timer::start(bool evaluate_)
    {
        std::unique_lock<mutex_type> l(mtx_);
        if (is_terminated_)
            return false;

        if (!is_started_) {
            if (first_start_) {
                first_start_ = false;

                util::unlock_guard<std::unique_lock<mutex_type> > ul(l);
                if (pre_shutdown_)
                {
                    register_pre_shutdown_function(
                        util::bind(&pool_timer::terminate,
                            this->shared_from_this()));
                }
                else
                {
                    register_shutdown_function(
                        util::bind(&pool_timer::terminate,
                            this->shared_from_this()));
                }
            }

            is_stopped_ = false;
            is_started_ = true;

            HPX_ASSERT(timer_ != nullptr);
            timer_->expires_at(abs_time_);
            timer_->async_wait(util::bind(&pool_timer::timer_handler,
                this->shared_from_this()));

            return true;
        }
        return false;
    }

    bool pool_timer::stop()
    {
        std::lock_guard<mutex_type> l(mtx_);
        return stop_locked();
    }

    bool pool_timer::stop_locked()
    {
        if (!is_terminated_ && is_started_ && !is_stopped_) {
            is_started_ = false;
            is_stopped_ = true;

            HPX_ASSERT(timer_ != nullptr);
            timer_->cancel();
            return true;
        }
        return false;
    }

    void pool_timer::terminate()
    {
        std::unique_lock<mutex_type> l(mtx_);
        if (!is_terminated_) {
            is_terminated_ = true;
            stop_locked();

            if (on_term_) {
                l.unlock();
                on_term_();
            }
        }
        delete timer_;
        timer_ = nullptr;
    }

    pool_timer::~pool_timer()
    {
        try {
            terminate();
        }
        catch(...) {
            ;   // there is nothing we can do here
        }
    }
}}}

namespace hpx { namespace util
{
    pool_timer::pool_timer() {}

    pool_timer::pool_timer(util::function_nonser<bool()> const& f,
            util::function_nonser<void()> const& on_term,
            hpx::util::steady_time_point const& abs_time,
            std::string const& description,
            bool pre_shutdown)
      : timer_(std::make_shared<detail::pool_timer>(
            f, on_term, abs_time.value(), description, pre_shutdown))
    {}

    pool_timer::pool_timer(util::function_nonser<bool()> const& f,
            util::function_nonser<void()> const& on_term,
            hpx::util::steady_duration const& rel_time,
            std::string const& description,
            bool pre_shutdown)
      : timer_(std::make_shared<detail::pool_timer>(
            f, on_term, rel_time.from_now(), description, pre_shutdown))
    {}

    pool_timer::~pool_timer()
    {
        timer_->terminate();
    }

    bool pool_timer::start(bool evaluate)
    {
        return timer_->start(evaluate);
    }

    bool pool_timer::stop()
    {
        return timer_->stop();
    }

    bool pool_timer::is_started() const
    {
        return timer_->is_started();
    }

    bool pool_timer::is_terminated() const
    {
        return timer_->is_terminated();
    }
}}
