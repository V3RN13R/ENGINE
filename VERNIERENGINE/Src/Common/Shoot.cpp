#include "Shoot.h"
#include "Scene.h"

Shoot::Shoot(std::map<std::string, std::string> args, Entity* ent) : _file(args["file"]), _name(args["name"]), _prefabName(args["prefabName"])
{
	ent->getScene()->createEntityByPrefab(_file, _name, _prefabName);
	//Entity::getEntity(_entityName)->getScene()->createEntityByPrefab(_file, _name, _prefabName);
	//entity_->getScene()->createEntityByPrefab(_file, _name, _prefabName);
}

void Shoot::Dispara()
{
	//Pulsas la Q
	//_scene->createEntityByPrefab(_file, _name, _prefabName);
}