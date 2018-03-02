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

class SystemBase {
public:
	void update(double dt);
	
protected:
	
	std::vector<Component*> components;
};

template<typename T>
class System: public SystemBase {
public:
	void addComponent(T* c) {
		components.emplace_back(c);
	}
	
	void removeComponent(T* c) {
		
	}
};
