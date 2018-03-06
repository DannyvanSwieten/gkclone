//
//  physics_system.cpp
//  gkclone
//
//  Created by Danny on 06/03/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#include "physics_system.hpp"

void PhysicsSystem::update(double dt) {
	for(auto& body: components) {
		body.update(dt);
	}
}

Component* PhysicsSystem::createInstance(Entity &e) {
	return &components.emplace_back(e);
}
