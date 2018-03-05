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
#include "script_system.hpp"

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
	
	const char* source = R"(
	
	local Self = {
		Properties = {
			name = "Pokemonslippers",
			x = 10,
			y = 15
		}
	}
    
    function update()
        print(self.x)
        print(self.y)
        print(self.name)
    end
	
	return Self
	)";

	lua_State* state = luaL_newstate();
    luaL_openlibs(state);
	
	Entity e;
	RigidBody b(e);
	PhysicsSystem ps;
	ScriptSystem ss;
	Script script(e, state);
	script.loadScript(source);
	ss.addComponent(&script);
	ps.addComponent(&b);
	
	ss.update(1.0 / 60);
	return 0;
}
