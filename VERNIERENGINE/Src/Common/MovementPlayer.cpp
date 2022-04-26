#include "MovementPlayer.h"
#include "PhysicsManager.h"
#include <btBulletCollisionCommon.h>
#include "btBulletDynamicsCommon.h"
#include "Utils.h"
#include "Entity.h"
#include "RigidBody.h"
#include "Transform.h"
#include "Scene.h"


//const float _PI = 3.1416;
//const float toRadians = _PI / 180.0;
//const float toAngles = 180.0 / _PI;

MovementPlayer::MovementPlayer(std::map<std::string, std::string> args) : _vel(std::stof(args["Vel"])), _entidadBuscar(args["Entity"])
{
	std::cout << "Contructora lua MovementPlayer\n";
}

void MovementPlayer::start()
{
	transformCamara = static_cast<Transform*>(entity_->getScene()->getObjectWithName(_entidadBuscar)->getComponent("Transform"));

}

void MovementPlayer::update(){
	dirFinal = Vector3D(0, 0, 0);
}
void MovementPlayer::receiveEvent(MessageType msg, Entity* e) {
	
	_rbToMove = static_cast<Rigidbody*>(entity_->getComponent("Rigidbody"));
	 
	if (msg == MessageType::W) {
		std::cout << "PulsaW\n";
		dirFinal += Vector3D(std::cos(transformCamara->getRot().getY() * toRadians), 0, -std::sin(transformCamara->getRot().getY() * toRadians)) * _vel;

	}
	if (msg == MessageType::A) {
		std::cout << "PulsaA\n";

		dirFinal += Vector3D(std::cos((transformCamara->getRot().getY() + 90) * toRadians), 0, -std::sin((transformCamara->getRot().getY() + 90) * toRadians)) * _vel;

	}
	if (msg == MessageType::S) {
		dirFinal += Vector3D(-std::cos(transformCamara->getRot().getY() * toRadians), 0, std::sin(transformCamara->getRot().getY() * toRadians)) * _vel;

	}
	if (msg == MessageType::D) {
		dirFinal += Vector3D(std::cos((transformCamara->getRot().getY() - 90) * toRadians), 0, -std::sin((transformCamara->getRot().getY() - 90) * toRadians)) * _vel;
	}

	_rbToMove->setVelocity(dirFinal);


}