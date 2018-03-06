//
//  physics_system.hpp
//  gkclone
//
//  Created by Danny on 06/03/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#pragma once

#include "rigid_body.hpp"
#include "system.hpp"

class PhysicsSystem: public System<RigidBody> {
public:
	
	void update(double dt) override;
	Component *createInstance(Entity &e) override;
};
