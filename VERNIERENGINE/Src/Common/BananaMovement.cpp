#include "BananaMovement.h"
#include "Scene.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "Entity.h"
#include "VernierTime.h"
#include "ENGINE.h"
//#include "checkML.h"

BananaMovement::BananaMovement(std::map<std::string, std::string> args, Entity* ent) : Component(ent), _disparador(args["Disparador"])
{
	_speed = std::stof(args["Speed"]);
	_ttl = std::stof(args["TTL"]);

	//Coger referencias al que dispara, el rb y tr de la propia entidad
	_disparadorEnt = entity_->getScene()->getObjectWithName(_disparador);
	_rb = static_cast<Rigidbody*>(entity_->getComponent("Rigidbody"));
	_tr = static_cast<Transform*>(entity_->getComponent("Transform"));

	if (_disparadorEnt) {
		_transformDisp = (Transform*)_disparadorEnt->getComponent("Transform");
		_dir = Vector3D(std::cos(_transformDisp->getRot().getY() * toRadians), 0, -std::sin(_transformDisp->getRot().getY() * toRadians)) * _speed;

		_trMono = static_cast<Transform*>(entity_->getScene()->getObjectWithName(_disparador)->getComponent("Transform"));
		_tr->setPosition(Vector3D(_trMono->getPos()));
		_rb->setVelocity(_dir.normalize() * _speed);
		_rb->setCenterRb(_trMono->getPos());
	}
}

BananaMovement::~BananaMovement()
{
	_rb = nullptr;
}

void BananaMovement::start()
{
	_lastTime = VernierEngine::getInstance()->getTime()->Time();
}

void BananaMovement::update()
{	
	float currentTime = VernierEngine::getInstance()->getTime()->Time();
	if (_lastTime + _ttl < currentTime) {
		entity_->destroy();
	}		
}

void BananaMovement::onTriggerExit(Entity* ohter, Vector3D point)
{
	if (ohter->getComponent("Destroyable")) {
		Rigidbody* _rbOther = static_cast<Rigidbody*>(ohter->getComponent("Rigidbody"));
		_rbOther->setEnable(false);
		_rb->setEnable(false);
		ohter->destroy();
		entity_->destroy();
	}	
}
