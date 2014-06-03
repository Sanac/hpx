// Copyright (c) 2007-2013 Hartmut Kaiser
// Copyright (c) 2012-2013 Thomas Heller
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// This file has been automatically generated using the Boost.Wave tool.
// Do not edit manually.


namespace hpx { namespace util { namespace detail
{
    template <
        typename Functor
      , typename R
       
    >
    struct get_table<
        Functor
      , R()
    >
    {
        template <bool Unique, typename IArchive, typename OArchive>
        struct generate_vtable
        {
            typedef
                typename unique_vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R()
                      , IArchive, OArchive
                    >
                type;
        };
        
        template <typename IArchive, typename OArchive>
        struct generate_vtable<false, IArchive, OArchive>
        {
            typedef
                typename vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R()
                      , IArchive, OArchive
                    >
                type;
        };
        template <bool Unique, typename IArchive, typename OArchive>
        BOOST_FORCEINLINE static vtable_ptr_base<
            R()
          , IArchive, OArchive
        >*
        get()
        {
            typedef
                typename generate_vtable<Unique, IArchive, OArchive>::type
                vtable_type;
            typedef
                vtable_ptr<
                    R()
                  , IArchive, OArchive
                  , vtable_type
                >
                vtable_ptr_type;
            static vtable_ptr_type ptr;
            return &ptr;
        }
    };
}}}
namespace hpx { namespace util { namespace detail
{
    template <
        typename Functor
      , typename R
      , typename A0
    >
    struct get_table<
        Functor
      , R(A0)
    >
    {
        template <bool Unique, typename IArchive, typename OArchive>
        struct generate_vtable
        {
            typedef
                typename unique_vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0)
                      , IArchive, OArchive
                    >
                type;
        };
        
        template <typename IArchive, typename OArchive>
        struct generate_vtable<false, IArchive, OArchive>
        {
            typedef
                typename vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0)
                      , IArchive, OArchive
                    >
                type;
        };
        template <bool Unique, typename IArchive, typename OArchive>
        BOOST_FORCEINLINE static vtable_ptr_base<
            R(A0)
          , IArchive, OArchive
        >*
        get()
        {
            typedef
                typename generate_vtable<Unique, IArchive, OArchive>::type
                vtable_type;
            typedef
                vtable_ptr<
                    R(A0)
                  , IArchive, OArchive
                  , vtable_type
                >
                vtable_ptr_type;
            static vtable_ptr_type ptr;
            return &ptr;
        }
    };
}}}
namespace hpx { namespace util { namespace detail
{
    template <
        typename Functor
      , typename R
      , typename A0 , typename A1
    >
    struct get_table<
        Functor
      , R(A0 , A1)
    >
    {
        template <bool Unique, typename IArchive, typename OArchive>
        struct generate_vtable
        {
            typedef
                typename unique_vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1)
                      , IArchive, OArchive
                    >
                type;
        };
        
        template <typename IArchive, typename OArchive>
        struct generate_vtable<false, IArchive, OArchive>
        {
            typedef
                typename vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1)
                      , IArchive, OArchive
                    >
                type;
        };
        template <bool Unique, typename IArchive, typename OArchive>
        BOOST_FORCEINLINE static vtable_ptr_base<
            R(A0 , A1)
          , IArchive, OArchive
        >*
        get()
        {
            typedef
                typename generate_vtable<Unique, IArchive, OArchive>::type
                vtable_type;
            typedef
                vtable_ptr<
                    R(A0 , A1)
                  , IArchive, OArchive
                  , vtable_type
                >
                vtable_ptr_type;
            static vtable_ptr_type ptr;
            return &ptr;
        }
    };
}}}
namespace hpx { namespace util { namespace detail
{
    template <
        typename Functor
      , typename R
      , typename A0 , typename A1 , typename A2
    >
    struct get_table<
        Functor
      , R(A0 , A1 , A2)
    >
    {
        template <bool Unique, typename IArchive, typename OArchive>
        struct generate_vtable
        {
            typedef
                typename unique_vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2)
                      , IArchive, OArchive
                    >
                type;
        };
        
        template <typename IArchive, typename OArchive>
        struct generate_vtable<false, IArchive, OArchive>
        {
            typedef
                typename vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2)
                      , IArchive, OArchive
                    >
                type;
        };
        template <bool Unique, typename IArchive, typename OArchive>
        BOOST_FORCEINLINE static vtable_ptr_base<
            R(A0 , A1 , A2)
          , IArchive, OArchive
        >*
        get()
        {
            typedef
                typename generate_vtable<Unique, IArchive, OArchive>::type
                vtable_type;
            typedef
                vtable_ptr<
                    R(A0 , A1 , A2)
                  , IArchive, OArchive
                  , vtable_type
                >
                vtable_ptr_type;
            static vtable_ptr_type ptr;
            return &ptr;
        }
    };
}}}
namespace hpx { namespace util { namespace detail
{
    template <
        typename Functor
      , typename R
      , typename A0 , typename A1 , typename A2 , typename A3
    >
    struct get_table<
        Functor
      , R(A0 , A1 , A2 , A3)
    >
    {
        template <bool Unique, typename IArchive, typename OArchive>
        struct generate_vtable
        {
            typedef
                typename unique_vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3)
                      , IArchive, OArchive
                    >
                type;
        };
        
        template <typename IArchive, typename OArchive>
        struct generate_vtable<false, IArchive, OArchive>
        {
            typedef
                typename vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3)
                      , IArchive, OArchive
                    >
                type;
        };
        template <bool Unique, typename IArchive, typename OArchive>
        BOOST_FORCEINLINE static vtable_ptr_base<
            R(A0 , A1 , A2 , A3)
          , IArchive, OArchive
        >*
        get()
        {
            typedef
                typename generate_vtable<Unique, IArchive, OArchive>::type
                vtable_type;
            typedef
                vtable_ptr<
                    R(A0 , A1 , A2 , A3)
                  , IArchive, OArchive
                  , vtable_type
                >
                vtable_ptr_type;
            static vtable_ptr_type ptr;
            return &ptr;
        }
    };
}}}
namespace hpx { namespace util { namespace detail
{
    template <
        typename Functor
      , typename R
      , typename A0 , typename A1 , typename A2 , typename A3 , typename A4
    >
    struct get_table<
        Functor
      , R(A0 , A1 , A2 , A3 , A4)
    >
    {
        template <bool Unique, typename IArchive, typename OArchive>
        struct generate_vtable
        {
            typedef
                typename unique_vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4)
                      , IArchive, OArchive
                    >
                type;
        };
        
        template <typename IArchive, typename OArchive>
        struct generate_vtable<false, IArchive, OArchive>
        {
            typedef
                typename vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4)
                      , IArchive, OArchive
                    >
                type;
        };
        template <bool Unique, typename IArchive, typename OArchive>
        BOOST_FORCEINLINE static vtable_ptr_base<
            R(A0 , A1 , A2 , A3 , A4)
          , IArchive, OArchive
        >*
        get()
        {
            typedef
                typename generate_vtable<Unique, IArchive, OArchive>::type
                vtable_type;
            typedef
                vtable_ptr<
                    R(A0 , A1 , A2 , A3 , A4)
                  , IArchive, OArchive
                  , vtable_type
                >
                vtable_ptr_type;
            static vtable_ptr_type ptr;
            return &ptr;
        }
    };
}}}
namespace hpx { namespace util { namespace detail
{
    template <
        typename Functor
      , typename R
      , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5
    >
    struct get_table<
        Functor
      , R(A0 , A1 , A2 , A3 , A4 , A5)
    >
    {
        template <bool Unique, typename IArchive, typename OArchive>
        struct generate_vtable
        {
            typedef
                typename unique_vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5)
                      , IArchive, OArchive
                    >
                type;
        };
        
        template <typename IArchive, typename OArchive>
        struct generate_vtable<false, IArchive, OArchive>
        {
            typedef
                typename vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5)
                      , IArchive, OArchive
                    >
                type;
        };
        template <bool Unique, typename IArchive, typename OArchive>
        BOOST_FORCEINLINE static vtable_ptr_base<
            R(A0 , A1 , A2 , A3 , A4 , A5)
          , IArchive, OArchive
        >*
        get()
        {
            typedef
                typename generate_vtable<Unique, IArchive, OArchive>::type
                vtable_type;
            typedef
                vtable_ptr<
                    R(A0 , A1 , A2 , A3 , A4 , A5)
                  , IArchive, OArchive
                  , vtable_type
                >
                vtable_ptr_type;
            static vtable_ptr_type ptr;
            return &ptr;
        }
    };
}}}
namespace hpx { namespace util { namespace detail
{
    template <
        typename Functor
      , typename R
      , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6
    >
    struct get_table<
        Functor
      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6)
    >
    {
        template <bool Unique, typename IArchive, typename OArchive>
        struct generate_vtable
        {
            typedef
                typename unique_vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6)
                      , IArchive, OArchive
                    >
                type;
        };
        
        template <typename IArchive, typename OArchive>
        struct generate_vtable<false, IArchive, OArchive>
        {
            typedef
                typename vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6)
                      , IArchive, OArchive
                    >
                type;
        };
        template <bool Unique, typename IArchive, typename OArchive>
        BOOST_FORCEINLINE static vtable_ptr_base<
            R(A0 , A1 , A2 , A3 , A4 , A5 , A6)
          , IArchive, OArchive
        >*
        get()
        {
            typedef
                typename generate_vtable<Unique, IArchive, OArchive>::type
                vtable_type;
            typedef
                vtable_ptr<
                    R(A0 , A1 , A2 , A3 , A4 , A5 , A6)
                  , IArchive, OArchive
                  , vtable_type
                >
                vtable_ptr_type;
            static vtable_ptr_type ptr;
            return &ptr;
        }
    };
}}}
namespace hpx { namespace util { namespace detail
{
    template <
        typename Functor
      , typename R
      , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7
    >
    struct get_table<
        Functor
      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7)
    >
    {
        template <bool Unique, typename IArchive, typename OArchive>
        struct generate_vtable
        {
            typedef
                typename unique_vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7)
                      , IArchive, OArchive
                    >
                type;
        };
        
        template <typename IArchive, typename OArchive>
        struct generate_vtable<false, IArchive, OArchive>
        {
            typedef
                typename vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7)
                      , IArchive, OArchive
                    >
                type;
        };
        template <bool Unique, typename IArchive, typename OArchive>
        BOOST_FORCEINLINE static vtable_ptr_base<
            R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7)
          , IArchive, OArchive
        >*
        get()
        {
            typedef
                typename generate_vtable<Unique, IArchive, OArchive>::type
                vtable_type;
            typedef
                vtable_ptr<
                    R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7)
                  , IArchive, OArchive
                  , vtable_type
                >
                vtable_ptr_type;
            static vtable_ptr_type ptr;
            return &ptr;
        }
    };
}}}
namespace hpx { namespace util { namespace detail
{
    template <
        typename Functor
      , typename R
      , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8
    >
    struct get_table<
        Functor
      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8)
    >
    {
        template <bool Unique, typename IArchive, typename OArchive>
        struct generate_vtable
        {
            typedef
                typename unique_vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8)
                      , IArchive, OArchive
                    >
                type;
        };
        
        template <typename IArchive, typename OArchive>
        struct generate_vtable<false, IArchive, OArchive>
        {
            typedef
                typename vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8)
                      , IArchive, OArchive
                    >
                type;
        };
        template <bool Unique, typename IArchive, typename OArchive>
        BOOST_FORCEINLINE static vtable_ptr_base<
            R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8)
          , IArchive, OArchive
        >*
        get()
        {
            typedef
                typename generate_vtable<Unique, IArchive, OArchive>::type
                vtable_type;
            typedef
                vtable_ptr<
                    R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8)
                  , IArchive, OArchive
                  , vtable_type
                >
                vtable_ptr_type;
            static vtable_ptr_type ptr;
            return &ptr;
        }
    };
}}}
namespace hpx { namespace util { namespace detail
{
    template <
        typename Functor
      , typename R
      , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9
    >
    struct get_table<
        Functor
      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9)
    >
    {
        template <bool Unique, typename IArchive, typename OArchive>
        struct generate_vtable
        {
            typedef
                typename unique_vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9)
                      , IArchive, OArchive
                    >
                type;
        };
        
        template <typename IArchive, typename OArchive>
        struct generate_vtable<false, IArchive, OArchive>
        {
            typedef
                typename vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9)
                      , IArchive, OArchive
                    >
                type;
        };
        template <bool Unique, typename IArchive, typename OArchive>
        BOOST_FORCEINLINE static vtable_ptr_base<
            R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9)
          , IArchive, OArchive
        >*
        get()
        {
            typedef
                typename generate_vtable<Unique, IArchive, OArchive>::type
                vtable_type;
            typedef
                vtable_ptr<
                    R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9)
                  , IArchive, OArchive
                  , vtable_type
                >
                vtable_ptr_type;
            static vtable_ptr_type ptr;
            return &ptr;
        }
    };
}}}
namespace hpx { namespace util { namespace detail
{
    template <
        typename Functor
      , typename R
      , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10
    >
    struct get_table<
        Functor
      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10)
    >
    {
        template <bool Unique, typename IArchive, typename OArchive>
        struct generate_vtable
        {
            typedef
                typename unique_vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10)
                      , IArchive, OArchive
                    >
                type;
        };
        
        template <typename IArchive, typename OArchive>
        struct generate_vtable<false, IArchive, OArchive>
        {
            typedef
                typename vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10)
                      , IArchive, OArchive
                    >
                type;
        };
        template <bool Unique, typename IArchive, typename OArchive>
        BOOST_FORCEINLINE static vtable_ptr_base<
            R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10)
          , IArchive, OArchive
        >*
        get()
        {
            typedef
                typename generate_vtable<Unique, IArchive, OArchive>::type
                vtable_type;
            typedef
                vtable_ptr<
                    R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10)
                  , IArchive, OArchive
                  , vtable_type
                >
                vtable_ptr_type;
            static vtable_ptr_type ptr;
            return &ptr;
        }
    };
}}}
namespace hpx { namespace util { namespace detail
{
    template <
        typename Functor
      , typename R
      , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11
    >
    struct get_table<
        Functor
      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11)
    >
    {
        template <bool Unique, typename IArchive, typename OArchive>
        struct generate_vtable
        {
            typedef
                typename unique_vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11)
                      , IArchive, OArchive
                    >
                type;
        };
        
        template <typename IArchive, typename OArchive>
        struct generate_vtable<false, IArchive, OArchive>
        {
            typedef
                typename vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11)
                      , IArchive, OArchive
                    >
                type;
        };
        template <bool Unique, typename IArchive, typename OArchive>
        BOOST_FORCEINLINE static vtable_ptr_base<
            R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11)
          , IArchive, OArchive
        >*
        get()
        {
            typedef
                typename generate_vtable<Unique, IArchive, OArchive>::type
                vtable_type;
            typedef
                vtable_ptr<
                    R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11)
                  , IArchive, OArchive
                  , vtable_type
                >
                vtable_ptr_type;
            static vtable_ptr_type ptr;
            return &ptr;
        }
    };
}}}
namespace hpx { namespace util { namespace detail
{
    template <
        typename Functor
      , typename R
      , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12
    >
    struct get_table<
        Functor
      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12)
    >
    {
        template <bool Unique, typename IArchive, typename OArchive>
        struct generate_vtable
        {
            typedef
                typename unique_vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12)
                      , IArchive, OArchive
                    >
                type;
        };
        
        template <typename IArchive, typename OArchive>
        struct generate_vtable<false, IArchive, OArchive>
        {
            typedef
                typename vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12)
                      , IArchive, OArchive
                    >
                type;
        };
        template <bool Unique, typename IArchive, typename OArchive>
        BOOST_FORCEINLINE static vtable_ptr_base<
            R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12)
          , IArchive, OArchive
        >*
        get()
        {
            typedef
                typename generate_vtable<Unique, IArchive, OArchive>::type
                vtable_type;
            typedef
                vtable_ptr<
                    R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12)
                  , IArchive, OArchive
                  , vtable_type
                >
                vtable_ptr_type;
            static vtable_ptr_type ptr;
            return &ptr;
        }
    };
}}}
namespace hpx { namespace util { namespace detail
{
    template <
        typename Functor
      , typename R
      , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13
    >
    struct get_table<
        Functor
      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13)
    >
    {
        template <bool Unique, typename IArchive, typename OArchive>
        struct generate_vtable
        {
            typedef
                typename unique_vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13)
                      , IArchive, OArchive
                    >
                type;
        };
        
        template <typename IArchive, typename OArchive>
        struct generate_vtable<false, IArchive, OArchive>
        {
            typedef
                typename vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13)
                      , IArchive, OArchive
                    >
                type;
        };
        template <bool Unique, typename IArchive, typename OArchive>
        BOOST_FORCEINLINE static vtable_ptr_base<
            R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13)
          , IArchive, OArchive
        >*
        get()
        {
            typedef
                typename generate_vtable<Unique, IArchive, OArchive>::type
                vtable_type;
            typedef
                vtable_ptr<
                    R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13)
                  , IArchive, OArchive
                  , vtable_type
                >
                vtable_ptr_type;
            static vtable_ptr_type ptr;
            return &ptr;
        }
    };
}}}
namespace hpx { namespace util { namespace detail
{
    template <
        typename Functor
      , typename R
      , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14
    >
    struct get_table<
        Functor
      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14)
    >
    {
        template <bool Unique, typename IArchive, typename OArchive>
        struct generate_vtable
        {
            typedef
                typename unique_vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14)
                      , IArchive, OArchive
                    >
                type;
        };
        
        template <typename IArchive, typename OArchive>
        struct generate_vtable<false, IArchive, OArchive>
        {
            typedef
                typename vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14)
                      , IArchive, OArchive
                    >
                type;
        };
        template <bool Unique, typename IArchive, typename OArchive>
        BOOST_FORCEINLINE static vtable_ptr_base<
            R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14)
          , IArchive, OArchive
        >*
        get()
        {
            typedef
                typename generate_vtable<Unique, IArchive, OArchive>::type
                vtable_type;
            typedef
                vtable_ptr<
                    R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14)
                  , IArchive, OArchive
                  , vtable_type
                >
                vtable_ptr_type;
            static vtable_ptr_type ptr;
            return &ptr;
        }
    };
}}}
namespace hpx { namespace util { namespace detail
{
    template <
        typename Functor
      , typename R
      , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15
    >
    struct get_table<
        Functor
      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15)
    >
    {
        template <bool Unique, typename IArchive, typename OArchive>
        struct generate_vtable
        {
            typedef
                typename unique_vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15)
                      , IArchive, OArchive
                    >
                type;
        };
        
        template <typename IArchive, typename OArchive>
        struct generate_vtable<false, IArchive, OArchive>
        {
            typedef
                typename vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15)
                      , IArchive, OArchive
                    >
                type;
        };
        template <bool Unique, typename IArchive, typename OArchive>
        BOOST_FORCEINLINE static vtable_ptr_base<
            R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15)
          , IArchive, OArchive
        >*
        get()
        {
            typedef
                typename generate_vtable<Unique, IArchive, OArchive>::type
                vtable_type;
            typedef
                vtable_ptr<
                    R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15)
                  , IArchive, OArchive
                  , vtable_type
                >
                vtable_ptr_type;
            static vtable_ptr_type ptr;
            return &ptr;
        }
    };
}}}
namespace hpx { namespace util { namespace detail
{
    template <
        typename Functor
      , typename R
      , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16
    >
    struct get_table<
        Functor
      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16)
    >
    {
        template <bool Unique, typename IArchive, typename OArchive>
        struct generate_vtable
        {
            typedef
                typename unique_vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16)
                      , IArchive, OArchive
                    >
                type;
        };
        
        template <typename IArchive, typename OArchive>
        struct generate_vtable<false, IArchive, OArchive>
        {
            typedef
                typename vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16)
                      , IArchive, OArchive
                    >
                type;
        };
        template <bool Unique, typename IArchive, typename OArchive>
        BOOST_FORCEINLINE static vtable_ptr_base<
            R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16)
          , IArchive, OArchive
        >*
        get()
        {
            typedef
                typename generate_vtable<Unique, IArchive, OArchive>::type
                vtable_type;
            typedef
                vtable_ptr<
                    R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16)
                  , IArchive, OArchive
                  , vtable_type
                >
                vtable_ptr_type;
            static vtable_ptr_type ptr;
            return &ptr;
        }
    };
}}}
namespace hpx { namespace util { namespace detail
{
    template <
        typename Functor
      , typename R
      , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17
    >
    struct get_table<
        Functor
      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17)
    >
    {
        template <bool Unique, typename IArchive, typename OArchive>
        struct generate_vtable
        {
            typedef
                typename unique_vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17)
                      , IArchive, OArchive
                    >
                type;
        };
        
        template <typename IArchive, typename OArchive>
        struct generate_vtable<false, IArchive, OArchive>
        {
            typedef
                typename vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17)
                      , IArchive, OArchive
                    >
                type;
        };
        template <bool Unique, typename IArchive, typename OArchive>
        BOOST_FORCEINLINE static vtable_ptr_base<
            R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17)
          , IArchive, OArchive
        >*
        get()
        {
            typedef
                typename generate_vtable<Unique, IArchive, OArchive>::type
                vtable_type;
            typedef
                vtable_ptr<
                    R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17)
                  , IArchive, OArchive
                  , vtable_type
                >
                vtable_ptr_type;
            static vtable_ptr_type ptr;
            return &ptr;
        }
    };
}}}
namespace hpx { namespace util { namespace detail
{
    template <
        typename Functor
      , typename R
      , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18
    >
    struct get_table<
        Functor
      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18)
    >
    {
        template <bool Unique, typename IArchive, typename OArchive>
        struct generate_vtable
        {
            typedef
                typename unique_vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18)
                      , IArchive, OArchive
                    >
                type;
        };
        
        template <typename IArchive, typename OArchive>
        struct generate_vtable<false, IArchive, OArchive>
        {
            typedef
                typename vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18)
                      , IArchive, OArchive
                    >
                type;
        };
        template <bool Unique, typename IArchive, typename OArchive>
        BOOST_FORCEINLINE static vtable_ptr_base<
            R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18)
          , IArchive, OArchive
        >*
        get()
        {
            typedef
                typename generate_vtable<Unique, IArchive, OArchive>::type
                vtable_type;
            typedef
                vtable_ptr<
                    R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18)
                  , IArchive, OArchive
                  , vtable_type
                >
                vtable_ptr_type;
            static vtable_ptr_type ptr;
            return &ptr;
        }
    };
}}}
namespace hpx { namespace util { namespace detail
{
    template <
        typename Functor
      , typename R
      , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19
    >
    struct get_table<
        Functor
      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19)
    >
    {
        template <bool Unique, typename IArchive, typename OArchive>
        struct generate_vtable
        {
            typedef
                typename unique_vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19)
                      , IArchive, OArchive
                    >
                type;
        };
        
        template <typename IArchive, typename OArchive>
        struct generate_vtable<false, IArchive, OArchive>
        {
            typedef
                typename vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19)
                      , IArchive, OArchive
                    >
                type;
        };
        template <bool Unique, typename IArchive, typename OArchive>
        BOOST_FORCEINLINE static vtable_ptr_base<
            R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19)
          , IArchive, OArchive
        >*
        get()
        {
            typedef
                typename generate_vtable<Unique, IArchive, OArchive>::type
                vtable_type;
            typedef
                vtable_ptr<
                    R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19)
                  , IArchive, OArchive
                  , vtable_type
                >
                vtable_ptr_type;
            static vtable_ptr_type ptr;
            return &ptr;
        }
    };
}}}
namespace hpx { namespace util { namespace detail
{
    template <
        typename Functor
      , typename R
      , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20
    >
    struct get_table<
        Functor
      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20)
    >
    {
        template <bool Unique, typename IArchive, typename OArchive>
        struct generate_vtable
        {
            typedef
                typename unique_vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20)
                      , IArchive, OArchive
                    >
                type;
        };
        
        template <typename IArchive, typename OArchive>
        struct generate_vtable<false, IArchive, OArchive>
        {
            typedef
                typename vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20)
                      , IArchive, OArchive
                    >
                type;
        };
        template <bool Unique, typename IArchive, typename OArchive>
        BOOST_FORCEINLINE static vtable_ptr_base<
            R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20)
          , IArchive, OArchive
        >*
        get()
        {
            typedef
                typename generate_vtable<Unique, IArchive, OArchive>::type
                vtable_type;
            typedef
                vtable_ptr<
                    R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20)
                  , IArchive, OArchive
                  , vtable_type
                >
                vtable_ptr_type;
            static vtable_ptr_type ptr;
            return &ptr;
        }
    };
}}}
namespace hpx { namespace util { namespace detail
{
    template <
        typename Functor
      , typename R
      , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21
    >
    struct get_table<
        Functor
      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21)
    >
    {
        template <bool Unique, typename IArchive, typename OArchive>
        struct generate_vtable
        {
            typedef
                typename unique_vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21)
                      , IArchive, OArchive
                    >
                type;
        };
        
        template <typename IArchive, typename OArchive>
        struct generate_vtable<false, IArchive, OArchive>
        {
            typedef
                typename vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21)
                      , IArchive, OArchive
                    >
                type;
        };
        template <bool Unique, typename IArchive, typename OArchive>
        BOOST_FORCEINLINE static vtable_ptr_base<
            R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21)
          , IArchive, OArchive
        >*
        get()
        {
            typedef
                typename generate_vtable<Unique, IArchive, OArchive>::type
                vtable_type;
            typedef
                vtable_ptr<
                    R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21)
                  , IArchive, OArchive
                  , vtable_type
                >
                vtable_ptr_type;
            static vtable_ptr_type ptr;
            return &ptr;
        }
    };
}}}
namespace hpx { namespace util { namespace detail
{
    template <
        typename Functor
      , typename R
      , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12 , typename A13 , typename A14 , typename A15 , typename A16 , typename A17 , typename A18 , typename A19 , typename A20 , typename A21 , typename A22
    >
    struct get_table<
        Functor
      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22)
    >
    {
        template <bool Unique, typename IArchive, typename OArchive>
        struct generate_vtable
        {
            typedef
                typename unique_vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22)
                      , IArchive, OArchive
                    >
                type;
        };
        
        template <typename IArchive, typename OArchive>
        struct generate_vtable<false, IArchive, OArchive>
        {
            typedef
                typename vtable<sizeof(Functor) <= sizeof(void *)>::
                    template type<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22)
                      , IArchive, OArchive
                    >
                type;
        };
        template <bool Unique, typename IArchive, typename OArchive>
        BOOST_FORCEINLINE static vtable_ptr_base<
            R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22)
          , IArchive, OArchive
        >*
        get()
        {
            typedef
                typename generate_vtable<Unique, IArchive, OArchive>::type
                vtable_type;
            typedef
                vtable_ptr<
                    R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22)
                  , IArchive, OArchive
                  , vtable_type
                >
                vtable_ptr_type;
            static vtable_ptr_type ptr;
            return &ptr;
        }
    };
}}}