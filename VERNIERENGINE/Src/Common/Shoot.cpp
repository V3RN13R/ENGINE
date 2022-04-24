#include "Shoot.h"
#include "Scene.h"
#include "InputManager.h"
#include "Utils.h"

Shoot::Shoot(std::map<std::string, std::string> args, Entity* ent) : _file(args["file"]), _name(args["name"]), _prefabName(args["prefabName"])
{
	_ent = ent;
	if (_ent != nullptr) std::cout << "HOLA";
	//_ent->getScene()->createEntityByPrefab(_file, _name, _prefabName);
	//Entity::getEntity(_entityName)->getScene()->createEntityByPrefab(_file, _name, _prefabName);
	//entity_->getScene()->createEntityByPrefab(_file, _name, _prefabName);
}

void Shoot::Dispara() {
	_ent->getScene()->createEntityByPrefab(_file, _name, _prefabName);
}

void Shoot::receiveEvent(MessageType msg, Entity* e) {
	if (msg == MessageType::PULSA_Q){
		//Dispara();
	}
}