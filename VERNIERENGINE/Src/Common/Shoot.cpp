#include "Shoot.h"
#include "Scene.h"
#include "Utils.h"
#include "InputManager.h"

Shoot::Shoot(std::map<std::string, std::string> args, Entity* ent) : Component(ent),  _file(args["File"]), _name(args["Name"]), _nameInGame(args["NameInGame"])
{

}

void Shoot::dispara() {
	Entity* en = entity_->getScene()->createEntityByPrefab(_file, _name, _nameInGame + std::to_string(cont));
	en->start();
	en->onEnable();
	cont++;
}

void Shoot::receiveEvent(int msg, Entity* e) {
	if (msg == MessageType::DISPARO)
		dispara();	
}