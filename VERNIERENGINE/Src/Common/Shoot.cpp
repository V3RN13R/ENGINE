#include "Shoot.h"
#include "Scene.h"
#include "InputManager.h"
#include "Utils.h"
#include "VernierTime.h"
#include "ENGINE.h"
#include <iostream>

Shoot::Shoot(std::map<std::string, std::string> args, Entity* ent) : Component(ent),  _file(args["File"]), _name(args["Name"]), _prefabName(args["PrefabName"])
{

}

void Shoot::start()
{
	lastTime = VernierEngine::getInstance()->getTime()->Time();;
}

void Shoot::update()
{
	float currentTime = VernierEngine::getInstance()->getTime()->Time();
	if (lastTime + 3.0 < currentTime) {
		std::cout << "Se destruye\n";
		lastTime = VernierEngine::getInstance()->getTime()->Time();;
	}
}

void Shoot::Dispara() {
}

void Shoot::receiveEvent(int msg, Entity* e) {
	if (msg == MessageType::DISPARO){
		


		Entity* en= entity_->getScene()->createEntityByPrefab(_file, _name, _prefabName + std::to_string(cont));
		en->start();
		en->onEnable();
		cont++;
		//_ent->getScene()->createEntityByPrefab(_file, _name, _prefabName);
		//Entity::getEntity(_entityName)->getScene()->createEntityByPrefab(_file, _name, _prefabName);
		//entity_->getScene()->createEntityByPrefab(_file, _name, _prefabName);
	}
}