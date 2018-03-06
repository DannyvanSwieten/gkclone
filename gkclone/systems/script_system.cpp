//
//  script_system.cpp
//  gkclone
//
//  Created by Danny on 05/03/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#include "script_system.hpp"
#include "script_context.hpp"

ScriptSystem::ScriptSystem(LuaScriptContext& context): L(context.getState()) {
	
}

Component *ScriptSystem::createInstance(Entity &e) {
	return &components.emplace_back(e, L);
}

void ScriptSystem::update(double dt) { 
	for(auto& script: components)
		script.update(dt);
}
