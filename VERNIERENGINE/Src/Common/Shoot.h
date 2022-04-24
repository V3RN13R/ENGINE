#pragma once

#include "Component.h"
#include <string>
#include <map>

class Shoot : public Component
{
private:
	std::string _file;
	std::string _name;
	std::string _prefabName;
	Entity* _ent;
public:
	Shoot(std::map<std::string, std::string> args, Entity* ent);
	//Shoot(std::string file, std::string name, std::string prefabName, Scene* scene);

	void Dispara();
	virtual void receiveEvent(MessageType msg, Entity* e) override;
};

