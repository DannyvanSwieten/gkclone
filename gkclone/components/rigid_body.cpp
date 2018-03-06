//
//  rigid_body.cpp
//  gkclone
//
//  Created by Danny on 06/03/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#include "rigid_body.hpp"

#include "entity.hpp"

RigidBody::RigidBody(Entity& entity): Component(entity, type_id) {
	
}

void RigidBody::update(double dt) {
	velocity = (momentum / mass) * dt;
	entity.setPosition(entity.getPosition() + velocity);
}
