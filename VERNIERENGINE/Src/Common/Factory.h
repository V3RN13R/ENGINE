#pragma once

#include "Component.h"
#include <string>
#include <map>
//#include "json.hpp"
//using json = nlohmann::json;

class Factory
{
public:
	Factory() {};
	
	virtual Component* createComponent(std::map<std::string, std::string> args) = 0;
	//virtual Component* createComponent(json& args) = 0;
};