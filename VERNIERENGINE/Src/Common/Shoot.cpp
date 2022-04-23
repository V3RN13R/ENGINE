#include "Shoot.h"
#include "Scene.h"

Shoot::Shoot(std::map<std::string, std::string> args) : _file(args["file"]), _name(args["name"]), _prefabName(args["prefabName"])
{
	//_scene->createEntityByPrefab(_file, _name, _prefabName);
}

void Shoot::Dispara()
{
	//Pulsas la Q
	//_scene->createEntityByPrefab(_file, _name, _prefabName);
}