//
//  component.cpp
//  gkclone
//
//  Created by Danny on 02/03/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#include "component.hpp"

#include "entity.hpp"

Component::Component(Entity& entity, size_t reflectionId): entity(entity), reflection_id(reflectionId) {
	entity.addComponent(this);
}
