//
//  script_system.hpp
//  gkclone
//
//  Created by Danny on 05/03/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#pragma once

#include "system.hpp"
#include "script.hpp"

class LuaScriptContext;
class ScriptSystem: public System<Script> {
public:
	
	ScriptSystem(LuaScriptContext& context);
	
	void update(double dt) override;
	Component *createInstance(Entity &e) override;
	
private:
	
	lua_State* L = nullptr;
};
