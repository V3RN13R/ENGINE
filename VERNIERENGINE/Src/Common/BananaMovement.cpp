#include "BananaMovement.h"
#include "Scene.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "Entity.h"

BananaMovement::BananaMovement(std::map<std::string, std::string> args, Entity* ent) : Component(ent), _disparador(args["Disparador"])
{
	_speed = std::stof(args["Speed"]);
	_disparadorEnt = entity_->getScene()->getObjectWithName(_disparador);
	_rb = static_cast<Rigidbody*>(entity_->getComponent("Rigidbody"));
	_tr = static_cast<Transform*>(entity_->getComponent("Transform"));
	if (_disparadorEnt) {
		_transformDisp = (Transform*)_disparadorEnt->getComponent("Transform");
		_dir = Vector3D(std::cos(_transformDisp->getRot().getY() * toRadians), 0, -std::sin(_transformDisp->getRot().getY() * toRadians)) * _speed;

		_trMono = static_cast<Transform*>(entity_->getScene()->getObjectWithName("mono2")->getComponent("Transform"));
		_tr->setPosition(Vector3D(_trMono->getPos()));
		_rb->setVelocity(_dir.normalize() * _speed);
		_rb->setCenterRb(_trMono->getPos());
	}
}

BananaMovement::~BananaMovement()
{
	_rb = nullptr;
}

void BananaMovement::update()
{
	/*_trMono = static_cast<Transform*>(entity_->getScene()->getObjectWithName("mono2")->getComponent("Transform"));
	
	_tr->setPosition(Vector3D(_trMono->getPos()));*/
}