//
//  script.cpp
//  gkclone
//
//  Created by Danny on 05/03/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#include "script.hpp"
#include "entity.hpp"

#include <iostream>

Script::Script(Entity &entity, lua_State* state): Component(entity, Script::type_id),
state(state), self(state) {
	
	if(!state)
		return;
	
//	self = luabridge::newTable(state);
//	self["enityId"] = entity;
}


void Script::update(double dt) { 
    
}

void Script::loadScript(const std::string &source) { 
	int result = luaL_dostring(state, source.c_str());
	if(result)
		return;
	
	luabridge::LuaRef table(state);
	table.pop(state);
	luabridge::LuaRef propertyTable = table["Properties"];
	push(state, propertyTable); // push table
	
	lua_pushnil(state);  // push nil, so lua_next removes it from stack and puts (k, v) on stack
	while (lua_next(state, -2) != 0) { // -2, because we have table at -1
		if (lua_isstring(state, -2)) { // only store stuff with string keys
			properties.emplace(lua_tostring(state, -2), luabridge::LuaRef::fromStack(state, -1));
		}
		lua_pop(state, 1); // remove value, keep key for lua_next
	}
	
	lua_pop(state, 1); // pop table
}

