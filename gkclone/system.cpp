//
//  system.cpp
//  gkclone
//
//  Created by Danny on 02/03/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#include "system.hpp"
#include "component.hpp"

void SystemBase::update(double dt) {
	for(auto c: components) {
		c->update(dt);
	}
}

