//  Copyright (c) 2007-2011 Hartmut Kaiser
// 
//  Distributed under the Boost Software License, Version 1.0. (See accompanying 
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PP_IS_ITERATING

#if !defined(HPX_RUNTIME_ACTIONS_PLAIN_ACTION_IMPLEMENTATIONS_NOV_14_2008_0811PM)
#define HPX_RUNTIME_ACTIONS_PLAIN_ACTION_IMPLEMENTATIONS_NOV_14_2008_0811PM

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/repeat.hpp>
#include <boost/preprocessor/iterate.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>

#define BOOST_PP_ITERATION_PARAMS_1                                           \
    (3, (1, HPX_ACTION_ARGUMENT_LIMIT,                                        \
    "hpx/runtime/actions/plain_action_implementations.hpp"))                  \
    /**/

#include BOOST_PP_ITERATE()

#endif

///////////////////////////////////////////////////////////////////////////////
//  Preprocessor vertical repetition code
///////////////////////////////////////////////////////////////////////////////
#else // defined(BOOST_PP_IS_ITERATING)

#define N BOOST_PP_ITERATION()
#define HPX_ACTION_ARGUMENT(z, n, data) BOOST_PP_COMMA_IF(n) data.get<n>()
#define HPX_ACTION_DIRECT_ARGUMENT(z, n, data)                                \
        BOOST_PP_COMMA_IF(n) boost::fusion::at_c<n>(data)                     \
    /**/
#define HPX_REMOVE_QUALIFIERS(z, n, data)                                     \
        BOOST_PP_COMMA_IF(n)                                                  \
        typename detail::remove_qualifiers<BOOST_PP_CAT(T, n)>::type          \
    /**/

    ///////////////////////////////////////////////////////////////////////////
    //  N parameter version, with result
    template <
        typename Result, 
        BOOST_PP_ENUM_PARAMS(N, typename T),
        Result (*F)(BOOST_PP_ENUM_PARAMS(N, T)), typename Derived, 
        threads::thread_priority Priority = threads::thread_priority_default
    >
    class BOOST_PP_CAT(plain_base_result_action, N)
      : public action<
            components::server::plain_function<Derived>, 
            BOOST_PP_CAT(function_result_action_arg, N), 
            boost::fusion::vector<BOOST_PP_REPEAT(N, HPX_REMOVE_QUALIFIERS, _)>,
            Derived, Priority>
    {
    private:
        typedef boost::fusion::vector<BOOST_PP_REPEAT(N, HPX_REMOVE_QUALIFIERS, _)> arguments_type;
        typedef action<
            components::server::plain_function<Derived>, 
            BOOST_PP_CAT(function_result_action_arg, N), 
            arguments_type, Derived, Priority> base_type;

    public:
        BOOST_PP_CAT(plain_base_result_action, N)(
                threads::thread_priority priority = Priority)
          : base_type(priority)
        {}

        // construct an action from its arguments
        template <BOOST_PP_ENUM_PARAMS(N, typename Arg)>
        BOOST_PP_CAT(plain_base_result_action, N)(
                BOOST_PP_ENUM_BINARY_PARAMS(N, Arg, const& arg)) 
          : base_type(BOOST_PP_ENUM_PARAMS(N, arg)) 
        {}

        template <BOOST_PP_ENUM_PARAMS(N, typename Arg)>
        BOOST_PP_CAT(plain_base_result_action, N)(
                threads::thread_priority priority,
                BOOST_PP_ENUM_BINARY_PARAMS(N, Arg, const& arg)) 
          : base_type(priority, BOOST_PP_ENUM_PARAMS(N, arg)) 
        {}

    private:
        /// The \a thread_function will be registered as the thread
        /// function of a thread. It encapsulates the execution of the 
        /// original function (given by \a func).
        template <BOOST_PP_ENUM_PARAMS(N, typename Arg)>
        static threads::thread_state_enum thread_function(
            BOOST_PP_ENUM_BINARY_PARAMS(N, Arg, const& arg))
        {
            try {
                LTM_(debug) << "Executing plain action("
                            << detail::get_action_name<Derived>()
                            << ").";
                F(BOOST_PP_ENUM_PARAMS(N, arg));      // call the function, ignoring the return value
            }
            catch (hpx::exception const& e) {
                LTM_(error) 
                    << "Unhandled exception while executing plain action("
                    << detail::get_action_name<Derived>()
                    << "): " << e.what();
            }
            return threads::terminated;
        }

    public:
        typedef boost::mpl::false_ direct_execution;
        typedef Result result_type;

        // This static construct_thread_function allows to construct 
        // a proper thread function for a thread without having to 
        // instantiate the base_result_actionN type. This is used by the applier in 
        // case no continuation has been supplied.
        template <BOOST_PP_ENUM_PARAMS(N, typename Arg)>
        static boost::function<threads::thread_function_type> 
        construct_thread_function(naming::address::address_type lva, 
            BOOST_PP_ENUM_BINARY_PARAMS(N, Arg, const& arg)) 
        {
            // we need to assign the address of the thread function to a 
            // variable to  help the compiler to deduce the function type
            threads::thread_state_enum (*f)(BOOST_PP_ENUM_BINARY_PARAMS(N, Arg, const& arg)) =
                &BOOST_PP_CAT(plain_base_result_action, N)::
                    template thread_function<BOOST_PP_ENUM_PARAMS(N, Arg)>;

            return boost::bind(f, BOOST_PP_ENUM_PARAMS(N, arg));
        }

        // This static construct_thread_function allows to construct 
        // a proper thread function for a thread without having to 
        // instantiate the base_result_actionN type. This is used by the applier in 
        // case a continuation has been supplied
        template <BOOST_PP_ENUM_PARAMS(N, typename Arg)>
        static boost::function<threads::thread_function_type> 
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, 
            BOOST_PP_ENUM_BINARY_PARAMS(N, Arg, const& arg)) 
        {
            return base_type::construct_continuation_thread_function(
                boost::bind(F, BOOST_PP_ENUM_PARAMS(N, arg)), cont);
        }

        /// serialization support
        static void register_base()
        {
            using namespace boost::serialization;
            void_cast_register<BOOST_PP_CAT(plain_base_result_action, N), base_type>();
            base_type::register_base();
        }

    private:
        // This get_thread_function will be invoked to retrieve the thread 
        // function for an action which has to be invoked without continuations.
        boost::function<threads::thread_function_type>
        get_thread_function(naming::address::address_type lva) const
        {
            return construct_thread_function(lva, 
                BOOST_PP_REPEAT(N, HPX_ACTION_ARGUMENT, (*this)));
        }

        // This get_thread_function will be invoked to retrieve the thread 
        // function for an action which has to be invoked with continuations.
        boost::function<threads::thread_function_type>
        get_thread_function(continuation_type& cont,
            naming::address::address_type lva) const
        {
            return construct_thread_function(cont, lva, 
                BOOST_PP_REPEAT(N, HPX_ACTION_ARGUMENT, (*this)));
        }

        // 
        boost::function<threads::thread_function_type>
        get_thread_function(naming::address::address_type lva,
            arguments_type const& arg) const
        {
            return construct_thread_function(lva, 
                BOOST_PP_REPEAT(N, HPX_ACTION_DIRECT_ARGUMENT, arg));
        }

        boost::function<threads::thread_function_type>
        get_thread_function(continuation_type& cont,
            naming::address::address_type lva, arguments_type const& arg) const
        {
            return construct_thread_function(cont, lva, 
                BOOST_PP_REPEAT(N, HPX_ACTION_DIRECT_ARGUMENT, arg));
        }

    private:
        // serialization support
        friend class boost::serialization::access;

        template<class Archive>
        void serialize(Archive& ar, const unsigned int /*version*/)
        {
            ar & boost::serialization::base_object<base_type>(*this);
        }
    };

    ///////////////////////////////////////////////////////////////////////////
    //  N parameter version, direct execution with result
    template <
        typename Result, BOOST_PP_ENUM_PARAMS(N, typename T), 
        Result (*F)(BOOST_PP_ENUM_PARAMS(N, T)),
        threads::thread_priority Priority = threads::thread_priority_default>
    class BOOST_PP_CAT(plain_result_action, N)
      : public BOOST_PP_CAT(plain_base_result_action, N)<Result, 
          BOOST_PP_ENUM_PARAMS(N, T), F, 
          BOOST_PP_CAT(plain_result_action, N)<
              Result, BOOST_PP_ENUM_PARAMS(N, T), F, Priority>, Priority>
    {
    private:
        typedef BOOST_PP_CAT(plain_base_result_action, N)<
            Result, BOOST_PP_ENUM_PARAMS(N, T), F, 
            BOOST_PP_CAT(plain_result_action, N), Priority> base_type;

    public:
        BOOST_PP_CAT(plain_result_action, N)(
                threads::thread_priority priority = Priority)
          : base_type(priority)
        {}

        // construct an action from its arguments
        template <BOOST_PP_ENUM_PARAMS(N, typename Arg)>
        BOOST_PP_CAT(plain_result_action, N)(
                BOOST_PP_ENUM_BINARY_PARAMS(N, Arg, const& arg)) 
          : base_type(BOOST_PP_ENUM_PARAMS(N, arg)) 
        {}

        template <BOOST_PP_ENUM_PARAMS(N, typename Arg)>
        BOOST_PP_CAT(plain_result_action, N)(
                threads::thread_priority priority,
                BOOST_PP_ENUM_BINARY_PARAMS(N, Arg, const& arg)) 
          : base_type(priority, BOOST_PP_ENUM_PARAMS(N, arg)) 
        {}

        /// The function \a get_action_name returns the name of this action
        /// (mainly used for debugging and logging purposes).
        char const* get_action_name() const
        {
            return detail::get_action_name<BOOST_PP_CAT(plain_result_action, N)>();
        }

        /// serialization support
        static void register_base()
        {
            using namespace boost::serialization;
            void_cast_register<BOOST_PP_CAT(plain_result_action, N), base_type>();
            base_type::register_base();
        }

    private:
        // serialization support
        friend class boost::serialization::access;

        template<class Archive>
        void serialize(Archive& ar, const unsigned int /*version*/)
        {
            ar & boost::serialization::base_object<base_type>(*this);
        }

    private:
        threads::thread_init_data& 
        get_thread_init_data(naming::address::address_type lva,
            threads::thread_init_data& data)
        {
            data.lva = lva;
            data.func = this->construct_thread_function(lva,
                BOOST_PP_REPEAT(N, HPX_ACTION_ARGUMENT, (*this)));
            data.description = detail::get_action_name<BOOST_PP_CAT(plain_result_action, N)>();
            data.parent_id = reinterpret_cast<threads::thread_id_type>(this->parent_id_);
            data.parent_phase = this->parent_phase_;
            data.parent_prefix = this->parent_locality_;
            data.priority = this->priority_;
            return data;
        }

        threads::thread_init_data& 
        get_thread_init_data(continuation_type& cont,
            naming::address::address_type lva, 
            threads::thread_init_data& data)
        {
            data.lva = lva;
            data.func = this->construct_thread_function(cont, lva,
                BOOST_PP_REPEAT(N, HPX_ACTION_ARGUMENT, (*this)));
            data.description = detail::get_action_name<BOOST_PP_CAT(plain_result_action, N)>();
            data.parent_id = reinterpret_cast<threads::thread_id_type>(this->parent_id_);
            data.parent_phase = this->parent_phase_;
            data.parent_prefix = this->parent_locality_;
            data.priority = this->priority_;
            return data;
        }
    };

    ///////////////////////////////////////////////////////////////////////////
    //  N parameter version, direct execution with result
    template <
        typename Result, BOOST_PP_ENUM_PARAMS(N, typename T), 
        Result (*F)(BOOST_PP_ENUM_PARAMS(N, T))>
    class BOOST_PP_CAT(plain_direct_result_action, N)
      : public BOOST_PP_CAT(plain_base_result_action, N)<Result, 
          BOOST_PP_ENUM_PARAMS(N, T), F, 
          BOOST_PP_CAT(plain_direct_result_action, N)<
              Result, BOOST_PP_ENUM_PARAMS(N, T), F> >
    {
    private:
        typedef BOOST_PP_CAT(plain_base_result_action, N)<
            Result, BOOST_PP_ENUM_PARAMS(N, T), F,
            BOOST_PP_CAT(plain_direct_result_action, N) > base_type;

    public:
        BOOST_PP_CAT(plain_direct_result_action, N)()
        {}

        // construct an action from its arguments
        template <BOOST_PP_ENUM_PARAMS(N, typename Arg)>
        BOOST_PP_CAT(plain_direct_result_action, N)(
                BOOST_PP_ENUM_BINARY_PARAMS(N, Arg, const& arg)) 
          : base_type(BOOST_PP_ENUM_PARAMS(N, arg)) 
        {}

        template <BOOST_PP_ENUM_PARAMS(N, typename Arg)>
        BOOST_PP_CAT(plain_direct_result_action, N)(
                threads::thread_priority, 
                BOOST_PP_ENUM_BINARY_PARAMS(N, Arg, const& arg)) 
          : base_type(BOOST_PP_ENUM_PARAMS(N, arg)) 
        {}

    public:
        typedef boost::mpl::true_ direct_execution;

        ///
        template <BOOST_PP_ENUM_PARAMS(N, typename Arg)>
        static Result execute_function(
            naming::address::address_type lva,
            BOOST_PP_ENUM_BINARY_PARAMS(N, Arg, const& arg))
        {
            // DTS: removed because it is logging too many 
            // console_logging_actions
            //LTM_(debug) << "Executing direct action "
            //            << detail::get_action_name<
            //                  BOOST_PP_CAT(plain_direct_result_action, N)>()
            //            << ".";
            return F(BOOST_PP_ENUM_PARAMS(N, arg));
        }

        /// serialization support
        static void register_base()
        {
            using namespace boost::serialization;
            void_cast_register<BOOST_PP_CAT(plain_direct_result_action, N), base_type>();
            base_type::register_base();
        }

    private:
        // serialization support
        friend class boost::serialization::access;

        template<class Archive>
        void serialize(Archive& ar, const unsigned int /*version*/)
        {
            ar & boost::serialization::base_object<base_type>(*this);
        }

    private:
        /// The function \a get_action_name returns the name of this action
        /// (mainly used for debugging and logging purposes).
        char const* get_action_name() const
        {
            return detail::get_action_name<BOOST_PP_CAT(plain_direct_result_action, N)>();
        }

        /// The function \a get_action_type returns whether this action needs
        /// to be executed in a new thread or directly.
        base_action::action_type get_action_type() const 
        {
            return base_action::direct_action;
        }

    private:
        threads::thread_init_data& 
        get_thread_init_data(naming::address::address_type lva,
            threads::thread_init_data& data)
        {
            data.lva = lva;
            data.func = this->construct_thread_function(lva,
                BOOST_PP_REPEAT(N, HPX_ACTION_ARGUMENT, (*this)));
            data.description = detail::get_action_name<BOOST_PP_CAT(plain_direct_result_action, N)>();
            data.parent_id = reinterpret_cast<threads::thread_id_type>(this->parent_id_);
            data.parent_phase = this->parent_phase_;
            data.parent_prefix = this->parent_locality_;
            data.priority = this->priority_;
            return data;
        }

        threads::thread_init_data& 
        get_thread_init_data(continuation_type& cont,
            naming::address::address_type lva, 
            threads::thread_init_data& data)
        {
            data.lva = lva;
            data.func = this->construct_thread_function(cont, lva,
                BOOST_PP_REPEAT(N, HPX_ACTION_ARGUMENT, (*this)));
            data.description = detail::get_action_name<BOOST_PP_CAT(plain_direct_result_action, N)>();
            data.parent_id = reinterpret_cast<threads::thread_id_type>(this->parent_id_);
            data.parent_phase = this->parent_phase_;
            data.parent_prefix = this->parent_locality_;
            data.priority = this->priority_;
            return data;
        }
    };

    ///////////////////////////////////////////////////////////////////////////
    //  N parameter version, no result type
    template <
        BOOST_PP_ENUM_PARAMS(N, typename T),
        void (*F)(BOOST_PP_ENUM_PARAMS(N, T)), typename Derived,
        threads::thread_priority Priority = threads::thread_priority_default>
    class BOOST_PP_CAT(plain_base_action, N)
      : public action<
            components::server::plain_function<Derived>,
            BOOST_PP_CAT(function_action_arg, N), 
            boost::fusion::vector<BOOST_PP_REPEAT(N, HPX_REMOVE_QUALIFIERS, _)>,
            Derived, Priority>
    {
    private:
        typedef 
            boost::fusion::vector<BOOST_PP_REPEAT(N, HPX_REMOVE_QUALIFIERS, _)> 
        arguments_type;
        typedef action<
            components::server::plain_function<Derived>, 
            BOOST_PP_CAT(function_action_arg, N), 
            arguments_type, Derived, Priority> base_type;

    public:
        BOOST_PP_CAT(plain_base_action, N)(threads::thread_priority priority = Priority)
          : base_type(priority)
        {}

        // construct an action from its arguments
        template <BOOST_PP_ENUM_PARAMS(N, typename Arg)>
        BOOST_PP_CAT(plain_base_action, N)(
                BOOST_PP_ENUM_BINARY_PARAMS(N, Arg, const& arg)) 
          : base_type(BOOST_PP_ENUM_PARAMS(N, arg)) 
        {}

        template <BOOST_PP_ENUM_PARAMS(N, typename Arg)>
        BOOST_PP_CAT(plain_base_action, N)(
                threads::thread_priority priority,
                BOOST_PP_ENUM_BINARY_PARAMS(N, Arg, const& arg)) 
          : base_type(priority, BOOST_PP_ENUM_PARAMS(N, arg)) 
        {}

    private:
        /// The \a thread_function will be registered as the thread
        /// function of a thread. It encapsulates the execution of the 
        /// original function (given by \a func).
        template <BOOST_PP_ENUM_PARAMS(N, typename Arg)>
        static threads::thread_state_enum thread_function(
            BOOST_PP_ENUM_BINARY_PARAMS(N, Arg, const& arg))
        {
            try {
                LTM_(debug) << "Executing plain action("
                            << detail::get_action_name<Derived>()
                            << ").";
                F(BOOST_PP_ENUM_PARAMS(N, arg));      // call the function, ignoring the return value
            }
            catch (hpx::exception const& e) {
                LTM_(error) 
                    << "Unhandled exception while executing plain action("
                    << detail::get_action_name<Derived>()
                    << "): " << e.what();
            }
            return threads::terminated;
        }

    public:
        typedef boost::mpl::false_ direct_execution;
        typedef util::unused_type result_type;

        // This static construct_thread_function allows to construct 
        // a proper thread function for a thread without having to 
        // instantiate the base_actionN type. This is used by the applier in 
        // case no continuation has been supplied.
        template <BOOST_PP_ENUM_PARAMS(N, typename Arg)>
        static boost::function<threads::thread_function_type> 
        construct_thread_function(naming::address::address_type lva, 
            BOOST_PP_ENUM_BINARY_PARAMS(N, Arg, const& arg)) 
        {
            // we need to assign the address of the thread function to a 
            // variable to  help the compiler to deduce the function type
            threads::thread_state_enum (*f)(BOOST_PP_ENUM_BINARY_PARAMS(N, Arg, const& arg)) =
                &BOOST_PP_CAT(plain_base_action, N)::
                    template thread_function<BOOST_PP_ENUM_PARAMS(N, Arg)>;

            return boost::bind(f, BOOST_PP_ENUM_PARAMS(N, arg));
        }

        // This static construct_thread_function allows to construct 
        // a proper thread function for a thread without having to 
        // instantiate the base_actionN type. This is used by the applier in 
        // case a continuation has been supplied
        template <BOOST_PP_ENUM_PARAMS(N, typename Arg)>
        static boost::function<threads::thread_function_type> 
        construct_thread_function(continuation_type& cont,
            naming::address::address_type lva, 
            BOOST_PP_ENUM_BINARY_PARAMS(N, Arg, const& arg)) 
        {
            return base_type::construct_continuation_thread_function_void(
                boost::bind(F, BOOST_PP_ENUM_PARAMS(N, arg)), cont);
        }

        /// serialization support
        static void register_base()
        {
            using namespace boost::serialization;
            void_cast_register<BOOST_PP_CAT(plain_base_action, N), base_type>();
            base_type::register_base();
        }

    private:
        boost::function<threads::thread_function_type>
        get_thread_function(naming::address::address_type lva) const
        {
            return construct_thread_function(lva, 
                BOOST_PP_REPEAT(N, HPX_ACTION_ARGUMENT, (*this)));
        }

        boost::function<threads::thread_function_type>
        get_thread_function(continuation_type& cont,
            naming::address::address_type lva) const
        {
            return construct_thread_function(cont, lva, 
                BOOST_PP_REPEAT(N, HPX_ACTION_ARGUMENT, (*this)));
        }

        ///
        boost::function<threads::thread_function_type>
        get_thread_function(naming::address::address_type lva,
            arguments_type const& arg) const
        {
            return construct_thread_function(lva, 
                BOOST_PP_REPEAT(N, HPX_ACTION_DIRECT_ARGUMENT, arg));
        }

        boost::function<threads::thread_function_type>
        get_thread_function(continuation_type& cont,
            naming::address::address_type lva, arguments_type const& arg) const
        {
            return construct_thread_function(cont, lva, 
                BOOST_PP_REPEAT(N, HPX_ACTION_DIRECT_ARGUMENT, arg));
        }

    private:
        // serialization support
        friend class boost::serialization::access;

        template<class Archive>
        void serialize(Archive& ar, const unsigned int /*version*/)
        {
            ar & boost::serialization::base_object<base_type>(*this);
        }
    };

    ///////////////////////////////////////////////////////////////////////////
    template <
        BOOST_PP_ENUM_PARAMS(N, typename T), 
        void (*F)(BOOST_PP_ENUM_PARAMS(N, T)),
        threads::thread_priority Priority = threads::thread_priority_default>
    class BOOST_PP_CAT(plain_action, N)
      : public BOOST_PP_CAT(plain_base_action, N)<
            BOOST_PP_ENUM_PARAMS(N, T), F, 
            BOOST_PP_CAT(plain_action, N)<
                BOOST_PP_ENUM_PARAMS(N, T), F, Priority>, Priority>
    {
    private:
        typedef BOOST_PP_CAT(plain_base_action, N)<
            BOOST_PP_ENUM_PARAMS(N, T), F, BOOST_PP_CAT(plain_action, N), Priority> 
        base_type;

    public:
        BOOST_PP_CAT(plain_action, N)(threads::thread_priority priority = Priority)
          : base_type(priority)
        {}

        // construct an action from its arguments
        template <BOOST_PP_ENUM_PARAMS(N, typename Arg)>
        BOOST_PP_CAT(plain_action, N)(
                BOOST_PP_ENUM_BINARY_PARAMS(N, Arg, const& arg)) 
          : base_type(BOOST_PP_ENUM_PARAMS(N, arg)) 
        {}

        template <BOOST_PP_ENUM_PARAMS(N, typename Arg)>
        BOOST_PP_CAT(plain_action, N)(
                threads::thread_priority priority,
                BOOST_PP_ENUM_BINARY_PARAMS(N, Arg, const& arg)) 
          : base_type(priority, BOOST_PP_ENUM_PARAMS(N, arg)) 
        {}

        /// The function \a get_action_name returns the name of this action
        /// (mainly used for debugging and logging purposes).
        char const* get_action_name() const
        {
            return detail::get_action_name<BOOST_PP_CAT(plain_action, N)>();
        }

        /// serialization support
        static void register_base()
        {
            using namespace boost::serialization;
            void_cast_register<BOOST_PP_CAT(plain_action, N), base_type>();
            base_type::register_base();
        }

    private:
        // serialization support
        friend class boost::serialization::access;

        template<class Archive>
        void serialize(Archive& ar, const unsigned int /*version*/)
        {
            ar & boost::serialization::base_object<base_type>(*this);
        }

    private:
        threads::thread_init_data& 
        get_thread_init_data(naming::address::address_type lva,
            threads::thread_init_data& data)
        {
            data.lva = lva;
            data.func = this->construct_thread_function(lva,
                BOOST_PP_REPEAT(N, HPX_ACTION_ARGUMENT, (*this)));
            data.description = detail::get_action_name<BOOST_PP_CAT(plain_action, N)>();
            data.parent_id = reinterpret_cast<threads::thread_id_type>(this->parent_id_);
            data.parent_phase = this->parent_phase_;
            data.parent_prefix = this->parent_locality_;
            data.priority = this->priority_;
            return data;
        }

        threads::thread_init_data& 
        get_thread_init_data(continuation_type& cont,
            naming::address::address_type lva, 
            threads::thread_init_data& data)
        {
            data.lva = lva;
            data.func = this->construct_thread_function(cont, lva,
                BOOST_PP_REPEAT(N, HPX_ACTION_ARGUMENT, (*this)));
            data.description = detail::get_action_name<BOOST_PP_CAT(plain_action, N)>();
            data.parent_id = reinterpret_cast<threads::thread_id_type>(this->parent_id_);
            data.parent_phase = this->parent_phase_;
            data.parent_prefix = this->parent_locality_;
            data.priority = this->priority_;
            return data;
        }
    };

    ///////////////////////////////////////////////////////////////////////////
    template <
        BOOST_PP_ENUM_PARAMS(N, typename T),
        void (*F)(BOOST_PP_ENUM_PARAMS(N, T)),
        threads::thread_priority Priority = threads::thread_priority_default>
    class BOOST_PP_CAT(plain_direct_action, N)
      : public BOOST_PP_CAT(plain_base_action, N)<
            BOOST_PP_ENUM_PARAMS(N, T), F,
            BOOST_PP_CAT(plain_direct_action, N)<
                BOOST_PP_ENUM_PARAMS(N, T), F> >
    {
    private:
        typedef BOOST_PP_CAT(plain_base_action, N)<
            BOOST_PP_ENUM_PARAMS(N, T), F, BOOST_PP_CAT(plain_direct_action, N), 
            Priority> base_type;

    public:
        BOOST_PP_CAT(plain_direct_action, N)()
        {}

        // construct an action from its arguments
        template <BOOST_PP_ENUM_PARAMS(N, typename Arg)>
        BOOST_PP_CAT(plain_direct_action, N)(
                BOOST_PP_ENUM_BINARY_PARAMS(N, Arg, const& arg)) 
          : base_type(BOOST_PP_ENUM_PARAMS(N, arg)) 
        {}

        template <BOOST_PP_ENUM_PARAMS(N, typename Arg)>
        BOOST_PP_CAT(plain_direct_action, N)(
                threads::thread_priority, 
                BOOST_PP_ENUM_BINARY_PARAMS(N, Arg, const& arg)) 
          : base_type(BOOST_PP_ENUM_PARAMS(N, arg)) 
        {}

    public:
        typedef boost::mpl::true_ direct_execution;

        ///
        template <BOOST_PP_ENUM_PARAMS(N, typename Arg)>
        static util::unused_type execute_function(naming::address::address_type lva, 
            BOOST_PP_ENUM_BINARY_PARAMS(N, Arg, const& arg))
        {
            // DTS: removed because it is logging too many 
            // console_logging_actions
            //LTM_(debug) << "Executing direct action " 
            //            << detail::get_action_name<
            //                  BOOST_PP_CAT(plain_direct_action, N)>()
            //            << ".";
            F(BOOST_PP_ENUM_PARAMS(N, arg));
            return util::unused;
        }

        /// serialization support
        static void register_base()
        {
            using namespace boost::serialization;
            void_cast_register<BOOST_PP_CAT(plain_direct_action, N), base_type>();
            base_type::register_base();
        }

    private:
        // serialization support
        friend class boost::serialization::access;

        template<class Archive>
        void serialize(Archive& ar, const unsigned int /*version*/)
        {
            ar & boost::serialization::base_object<base_type>(*this);
        }

    private:
        /// The function \a get_action_name returns the name of this action
        /// (mainly used for debugging and logging purposes).
        char const* get_action_name() const
        {
            return detail::get_action_name<BOOST_PP_CAT(plain_direct_action, N)>();
        }

        /// The function \a get_action_type returns whether this action needs
        /// to be executed in a new thread or directly.
        base_action::action_type get_action_type() const 
        {
            return base_action::direct_action;
        }

        threads::thread_init_data& 
        get_thread_init_data(naming::address::address_type lva,
            threads::thread_init_data& data)
        {
            data.lva = lva;
            data.func = this->construct_thread_function(lva,
                BOOST_PP_REPEAT(N, HPX_ACTION_ARGUMENT, (*this)));
            data.description = detail::get_action_name<BOOST_PP_CAT(plain_direct_action, N)>();
            data.parent_id = reinterpret_cast<threads::thread_id_type>(this->parent_id_);
            data.parent_phase = this->parent_phase_;
            data.parent_prefix = this->parent_locality_;
            data.priority = this->priority_;
            return data;
        }

        threads::thread_init_data& 
        get_thread_init_data(continuation_type& cont,
            naming::address::address_type lva, 
            threads::thread_init_data& data)
        {
            data.lva = lva;
            data.func = this->construct_thread_function(cont, lva,
                BOOST_PP_REPEAT(N, HPX_ACTION_ARGUMENT, (*this)));
            data.description = detail::get_action_name<BOOST_PP_CAT(plain_direct_action, N)>();
            data.parent_id = reinterpret_cast<threads::thread_id_type>(this->parent_id_);
            data.parent_phase = this->parent_phase_;
            data.parent_prefix = this->parent_locality_;
            data.priority = this->priority_;
            return data;
        }
    };

#undef HPX_REMOVE_QUALIFIERS
#undef HPX_ACTION_DIRECT_ARGUMENT
#undef HPX_ACTION_ARGUMENT
#undef N

#endif
