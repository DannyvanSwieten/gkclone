//
//  script_context.hpp
//  gkclone
//
//  Created by Danny on 06/03/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#pragma once

#include <lua.hpp>
#include <LuaBridge/LuaBridge.h>

class LuaScriptContext {
public:
	LuaScriptContext();
	luabridge::Namespace getGlobalNamespace();
	
	lua_State* getState() {
		return L;
	}
	
private:
	
	lua_State* L = nullptr;
};
