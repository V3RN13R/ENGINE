#include "Shoot.h"
#include "Scene.h"
#include "Utils.h"
#include "InputManager.h"
//#include "checkML.h"
#include "SoundComponent.h"


Shoot::Shoot(std::map<std::string, std::string> args, Entity* ent) : Component(ent),  _file(args["File"]), _name(args["Name"]), _nameInGame(args["NameInGame"])
{
}

void Shoot::dispara() {
	Entity* en = entity_->getScene()->createEntityByPrefab(_file, _name, _nameInGame + std::to_string(cont));
	en->start();
	en->onEnable();
	cont++;
	if(_sc)
		_sc->playsound("Shoot");
}

void Shoot::receiveEvent(int msg, Entity* e) {
	if (msg == MessageType::DISPARO)
		dispara();	
}

void Shoot::onDisable()
{
	Component::onDisable();
	if (_sc)
		_sc->stopAllSounds();
}

void Shoot::start()
{
	_sc = (SoundComponent*)entity_->getComponent("SoundComponent");
}
