//
//  system.hpp
//  gkclone
//
//  Created by Danny on 02/03/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#pragma once

#include <vector>

class Component;
class Entity;

class SystemBase {
public:
	virtual void update(double dt) = 0;
	virtual Component* createInstance(Entity& e) = 0;
};

template<typename T>
class System: public SystemBase {
public:
	void addComponent(T* c) {
		components.emplace_back(c);
	}
	
	void removeComponent(T* toBeRemoved) {
		auto it = std::remove_if(components.begin(), components.end(), [&](auto c)
								 {
									 return c == toBeRemoved;
								 });
		components.erase(it);
	}
	
protected:
	
	std::vector<T> components;
};
