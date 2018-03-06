//
//  component.hpp
//  gkclone
//
//  Created by Danny on 02/03/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#pragma once

#include <cstddef>

#define REGISTER_COMPONENT(name) \
static constexpr size_t type_id = hash(#name); \
static constexpr const char* const id = #name;

// FNV-1a constants
static constexpr unsigned long long basis = 14695981039346656037ULL;
static constexpr unsigned long long prime = 1099511628211ULL;

// compile-time hash helper function
constexpr size_t hashOne(char c, const char* const remain, unsigned long long value)
{
	return c == 0 ? value : hashOne(remain[0], remain + 1, (value ^ c) * prime);
}

// compile-time hash
constexpr size_t hash(const char* const str)
{
	return hashOne(str[0], str + 1, basis);
}

class Entity;

class Component {
public:
	Component(Entity& entity, size_t reflectionId);
	virtual void update(double dt) = 0;
	
	const size_t reflection_id;
	
protected:
	
	Entity& entity;
};
