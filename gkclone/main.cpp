//
//  main.cpp
//  gkclone
//
//  Created by Danny on 02/03/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#include <iostream>
#include "engine.hpp"
#include "script_system.hpp"
#include "physics_system.hpp"

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
		engine: log('Hello world!')
		self.entity: setPosition(10);
    end
	
	return Self
	)";
	
	Engine engine;
	engine.createSystem<Script>(0, std::make_unique<ScriptSystem>(engine.getScriptContext()));
	engine.createSystem<RigidBody>(1, std::make_unique<PhysicsSystem>());
	
	auto& e = engine.createEntity();
	engine.createComponent<RigidBody>(e);
	engine.createComponent<Script>(e);
	e.getComponent<Script>()->loadScript(source);
	
	engine.update();
	
	return 0;
}
