#include "Shoot.h"
#include "Scene.h"
#include "InputManager.h"
#include "Utils.h"

Shoot::Shoot(std::map<std::string, std::string> args, Entity* ent) : Component(ent),  _file(args["File"]), _name(args["Name"]), _prefabName(args["PrefabName"])
{

}

void Shoot::Dispara() {
}

void Shoot::receiveEvent(int msg, Entity* e) {
	if (msg == MessageType::DISPARO){
		
		Entity* en= entity_->getScene()->createEntityByPrefab(_file, _name, _prefabName + std::to_string(cont));

		cont++;
		//_ent->getScene()->createEntityByPrefab(_file, _name, _prefabName);
		//Entity::getEntity(_entityName)->getScene()->createEntityByPrefab(_file, _name, _prefabName);
		//entity_->getScene()->createEntityByPrefab(_file, _name, _prefabName);
	}
}