//
//  script.hpp
//  gkclone
//
//  Created by Danny on 05/03/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#pragma once

#include <lua.hpp>
#include <LuaBridge/LuaBridge.h>
#include <string>
#include <unordered_map>

#include "component.hpp"

class Script: public Component {
public:
	REGISTER_COMPONENT(Script);
	
	Script(Entity& entity, lua_State* state);
	
	void update(double dt) override;
	void loadScript(const std::string& source);
	
private:
	
	lua_State* state = nullptr;
	luabridge::LuaRef self;
    luabridge::LuaRef updateFunction;
    luabridge::LuaRef initFunction;
	std::unordered_map<std::string, luabridge::LuaRef> properties;
};
