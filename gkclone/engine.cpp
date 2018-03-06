//
//  engine.cpp
//  gkclone
//
//  Created by Danny on 06/03/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#include "engine.hpp"
#include "component.hpp"

Engine::Engine() {
	scriptContext.getGlobalNamespace().
	beginNamespace("Engine").
	beginClass<Engine>("instance").
	addFunction("log", &Engine::log).
	endClass().
	beginClass<Entity>("Entity").addFunction("setPosition", &Entity::setPosition).
	endClass().
	endNamespace();
}

Entity& Engine::createEntity() {
	return entities.emplace_back();
}

void Engine::createComponent(const char* const name, Entity& e) {
	auto h = hash(name);
	systems[h]->createInstance(e);
}

void Engine::update() {
	
	luabridge::setGlobal(scriptContext.getState(), this, "engine");
	
	for(auto& system: systems)
		system.second->update(1.0 / 60);
}
