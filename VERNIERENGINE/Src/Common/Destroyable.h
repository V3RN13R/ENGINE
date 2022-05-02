#pragma once
#include "Component.h"
#include <map>
#include <string>

class Entity;
class Vector3D;

class Destroyable :
	public Component
{
public:
	Destroyable(std::map<std::string, std::string> args) {};
private:

};