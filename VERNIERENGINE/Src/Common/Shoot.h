#pragma once

#include "Component.h"
#include <string>
#include <map>

class Scene;

class Shoot : public Component
{
private:
	std::string _file;
	std::string _name;
	std::string _prefabName;
	Scene* _scene;
public:
	Shoot(std::map<std::string, std::string> args);
	//Shoot(std::string file, std::string name, std::string prefabName, Scene* scene);

	void Dispara();
};

