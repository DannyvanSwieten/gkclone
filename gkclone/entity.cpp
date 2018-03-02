//
//  entity.cpp
//  gkclone
//
//  Created by Danny on 02/03/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#include "entity.hpp"

void Entity::addComponent(Component *component) {
	components.emplace_back(component);
}

void Entity::setPosition(float x) {
	position = x;
}
