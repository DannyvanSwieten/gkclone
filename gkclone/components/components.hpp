//
//  components.hp
//  gkclone
//
//  Created by Danny on 06/03/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#pragma once

#include "rigid_body.hpp"
#include "script.hpp"

template<typename... Types>
struct component_list_t {};

static constexpr component_list_t<RigidBody, Script> default_component_list;
