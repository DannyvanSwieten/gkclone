//
//  engine.hpp
//  gkclone
//
//  Created by Danny on 06/03/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#pragma once

#include <iostream>
#include <map>

#include "entity.hpp"
#include "script_context.hpp"
#include "system.hpp"

class Engine {
public:
	
	Engine();
	
	Entity& createEntity();
	template<typename T>
	void createSystem(size_t priority, std::unique_ptr<SystemBase> ptr) {
		systems.emplace(T::type_id, std::move(ptr));
	}
	
	template<typename T>
	void createComponent(Entity& e) {
		systems[T::type_id]->createInstance(e);
	}
	
	void createComponent(const char* const name, Entity& e);
	void update();
	
	LuaScriptContext& getScriptContext() {
		return scriptContext;
	}
	
	void log(const std::string& s) {
		std::cout << s << '\n';
	}
	
private:
	
	std::map<size_t, std::unique_ptr<SystemBase>> systems;
	std::vector<Entity> entities;
	
	LuaScriptContext scriptContext;
};
