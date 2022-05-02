#pragma once

#include "Component.h"
#include <string>
#include <map>

class Shoot : public Component
{
private:
	double lastTime;
	std::string _file;
	std::string _name;
	std::string _prefabName;
	int cont = 0;
public:
	Shoot(std::map<std::string, std::string> args, Entity* ent);
	//Shoot(std::string file, std::string name, std::string prefabName, Scene* scene);
	void start();
	void update();
	void Dispara();
	virtual void receiveEvent(int msg, Entity* e) override;
};

