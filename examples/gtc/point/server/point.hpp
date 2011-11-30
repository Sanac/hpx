//  Copyright (c) 2011 Matthew Anderson
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(HPX_5EC73F4A_D9BD_4B9B_A02B_87A9BA04C043)
#define HPX_5EC73F4A_D9BD_4B9B_A02B_87A9BA04C043

#include <hpx/hpx_fwd.hpp>
#include <hpx/runtime/components/component_type.hpp>
#include <hpx/runtime/components/server/managed_component_base.hpp>
#include <hpx/runtime/actions/component_action.hpp>

#include "../../particle/server/particle.hpp"

///////////////////////////////////////////////////////////////////////////////
namespace gtc { namespace server
{

    ///////////////////////////////////////////////////////////////////////////
    class HPX_COMPONENT_EXPORT point
      : public hpx::components::detail::managed_component_base<point>
    {
    public:
        enum actions
        {
            point_init = 0,
            point_search = 1
        };

        point()
        {}

        ///////////////////////////////////////////////////////////////////////
        // Exposed functionality of this component.

        /// Initialize the point with the given point file. 
        void init(std::size_t objectid,std::size_t max_num_neighbors,
            std::string const& meshfile);

        /// Perform a search on the \a gtc::server::particle
        /// components in \a particle_components.
        void search(std::vector<hpx::naming::id_type> const& particle_components);

        ///////////////////////////////////////////////////////////////////////
        // Each of the exposed functions needs to be encapsulated into an
        // action type, generating all required boilerplate code for threads,
        // serialization, etc.
        typedef hpx::actions::action3<
            // Component server type.
            point,
            // Action code.
            point_init,
            // Arguments of this action.
            std::size_t,
            std::size_t,
            std::string const&,
            // Method bound to this action. 
            &point::init
        > init_action;

        typedef hpx::actions::action1<
            // Component server type.
            point,
            // Action code.
            point_search,
            // Arguments of this action.
            std::vector<hpx::naming::id_type> const&,
            // Method bound to this action.
            &point::search
        > search_action;

    private:
        std::size_t idx_;
        std::vector<std::size_t> neighbors_;
        double posx_,posy_,posz_;
    };
}}

HPX_REGISTER_ACTION_DECLARATION_EX(
              gtc::server::point::init_action,
              gtc_point_init_action)

HPX_REGISTER_ACTION_DECLARATION_EX(
              gtc::server::point::search_action,
              gtc_point_search_action)

#endif

