//
//  main.cpp
//  gkclone
//
//  Created by Danny on 02/03/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#include <iostream>
#include "component.hpp"
#include "entity.hpp"
#include "system.hpp"

class RigidBody: public Component {
public:
	
	REGISTER_COMPONENT("Rigid Body");
	RigidBody(Entity& entity): Component(entity, type_id) {
		
	}
	
	void update(double dt) override {
		velocity = (momentum / mass) * dt;
		entity.setPosition(entity.getPosition() + velocity);
	}
	
private:
	
	float mass = 1;
	float momentum = 100;
	float velocity = 0;
};

class PhysicsSystem: public System<RigidBody> {
public:
	
};

int main(int argc, const char * argv[]) {

	Entity e;
	RigidBody b(e);
	PhysicsSystem s;
	e.addComponent(&b);
	
	return 0;
}
