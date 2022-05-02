#include "MovementPlayer.h"
#include "PhysicsManager.h"
#include <btBulletCollisionCommon.h>
#include "btBulletDynamicsCommon.h"
#include "Utils.h"
#include "Entity.h"
#include "RigidBody.h"
#include "Transform.h"
#include "Scene.h"
#include "ENGINE.h"
#include "VernierTime.h"


//const float _PI = 3.1416;
//const float toRadians = _PI / 180.0;
//const float toAngles = 180.0 / _PI;

MovementPlayer::MovementPlayer(std::map<std::string, std::string> args) : _vel(std::stof(args["Vel"])), _entidadBuscar(args["Entity"]),
_speed(std::stof(args["Speed"])), _jump(std::stof(args["Jump"]))
{
	std::cout << "Contructora lua MovementPlayer\n";
}

void MovementPlayer::start()
{
	transformCamara = static_cast<Transform*>(entity_->getScene()->getObjectWithName(_entidadBuscar)->getComponent("Transform"));
	_rbToMove = static_cast<Rigidbody*>(entity_->getComponent("Rigidbody"));

}

void MovementPlayer::update() {
	dirFinal = Vector3D(0, 0, 0);
	if (VernierEngine::getInstance()->getInputMng()->getKeyDown(SDL_SCANCODE_SPACE)) {
		if (jumps > 0) {
			float currentTime = VernierEngine::getInstance()->getTime()->Time();
			if (_lastTime + 0.5f < currentTime) {
				float multiplier = 2;
				_rbToMove->addImpulse(Vector3D(0, 50, 0) * _jump * multiplier);
				jumps--;
				_lastTime = currentTime;
			}

		}
		else {
			std::cout << "No salto";
		}
	}
	if (VernierEngine::getInstance()->getInputMng()->getKeyDown(SDL_SCANCODE_S)) {
		dirFinal += Vector3D(-std::cos(transformCamara->getRot().getY() * toRadians), 0, std::sin(transformCamara->getRot().getY() * toRadians)) * _vel * _speed;

	}
	if (VernierEngine::getInstance()->getInputMng()->getKeyDown(SDL_SCANCODE_W)) {
		dirFinal += Vector3D(std::cos(transformCamara->getRot().getY() * toRadians), 0, -std::sin(transformCamara->getRot().getY() * toRadians)) * _vel * _speed;

	}
	if (VernierEngine::getInstance()->getInputMng()->getKeyDown(SDL_SCANCODE_D)) {
		dirFinal += Vector3D(std::cos((transformCamara->getRot().getY() - 90) * toRadians), 0, -std::sin((transformCamara->getRot().getY() - 90) * toRadians)) * _vel * _speed;

	}
	if (VernierEngine::getInstance()->getInputMng()->getKeyDown(SDL_SCANCODE_A)) {
		dirFinal += Vector3D(std::cos((transformCamara->getRot().getY() + 90) * toRadians), 0, -std::sin((transformCamara->getRot().getY() + 90) * toRadians)) * _vel * _speed;

	}
	//POR SI QUEREMOS NORMALIZAR
	//dirFinal = Vector3D(dirFinal.getX() != 0 ? dirFinal.getX() / dirFinal.getX() : 0, _rbToMove->getVel().getY(), dirFinal.getZ() != 0 ? dirFinal.getZ() / dirFinal.getZ() : 0);

	dirFinal = Vector3D(dirFinal.getX(), _rbToMove->getVel().getY(), dirFinal.getZ());
	_rbToMove->setVelocity(dirFinal);
	//std::cout << _rbToMove->getVel().getX() << " " << _rbToMove->getVel().getY() << " " << _rbToMove->getVel().getZ() << "\n";

}


void MovementPlayer::onCollisionEnter(Entity* other, Vector3D point, Vector3D normal)
{
	if (other->getComponent("Ground")) {
		jumps = 2;
	}
}
