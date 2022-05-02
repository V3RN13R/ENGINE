#pragma once

#include "Component.h"
#include <string>
#include <map>

class Shoot : public Component
{
private:
	std::string _file;
	std::string _name;
	std::string _nameInGame;
	int cont = 0;

public:
	Shoot(std::map<std::string, std::string> args, Entity* ent);
	void dispara();
	virtual void receiveEvent(int msg, Entity* e) override;
};