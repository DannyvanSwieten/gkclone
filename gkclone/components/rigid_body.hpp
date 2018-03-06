//
//  rigid_body.hpp
//  gkclone
//
//  Created by Danny on 06/03/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#pragma once

#include "component.hpp"

class RigidBody: public Component {
public:
	
	REGISTER_COMPONENT("Rigid Body");
	RigidBody(Entity& entity);
	
	void update(double dt) override;
	
private:
	
	float mass = 1;
	float momentum = 100;
	float velocity = 0;
};
