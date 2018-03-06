//
//  script_context.cpp
//  gkclone
//
//  Created by Danny on 06/03/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#include "script_context.hpp"

LuaScriptContext::LuaScriptContext() {
	L = luaL_newstate();
	luaL_openlibs(L);
}

luabridge::Namespace LuaScriptContext::getGlobalNamespace() {
	return luabridge::getGlobalNamespace(L);
}
