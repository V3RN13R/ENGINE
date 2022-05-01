#pragma once
#include "Component.h"
#include <map>
#include <string>


class Ground : public Component
{
public:
	Ground(Entity* e = nullptr) {};
	Ground(std::map<std::string, std::string> args) {};
	~Ground() {};
private:
};
