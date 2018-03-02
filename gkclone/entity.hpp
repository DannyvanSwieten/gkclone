//
//  entity.hpp
//  gkclone
//
//  Created by Danny on 02/03/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#pragma once

#include <vector>

#include "component.hpp"

class Entity {
public:
	
	void addComponent(Component* component);
	void setPosition(float x);
	inline float getPosition() {
		return position;
	}
	
	template<typename T>
	T* getComponent() {
		for(auto c: components) {
			auto tid = T::type_id;
			if(c->reflection_id == tid)
				return static_cast<T*>(c);
		}
		
		return nullptr;
	}
	
private:
	
	std::vector<Component*> components;
	
	float position = 0;
};
