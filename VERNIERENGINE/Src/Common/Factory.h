#pragma once

#include "Component.h"
#include <string>
#include <map>

class Factory
{
public:
	Factory() {};
	virtual ~Factory() {};
	virtual Component* createComponent(std::map<std::string, std::string> args, Entity* ent = nullptr) = 0;
};