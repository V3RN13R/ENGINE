#include "MovementPlayer.h"
#include "PhysicsManager.h"
#include <btBulletCollisionCommon.h>
#include "btBulletDynamicsCommon.h"
#include "Utils.h"
#include "Entity.h"
#include "RigidBody.h"


MovementPlayer::MovementPlayer(std::map<std::string, std::string> args) : _vel(std::stof(args["Vel"]))
{
	std::cout << "Contructora lua MovementPlayer\n";
}

bool MovementPlayer::init()
{
	_rbToMove = entity_->getComponent<Rigidbody>();
	return true;
}


void MovementPlayer::receiveEvent(MessageType msg, Entity* e) {
	
	
	if (msg == MessageType::W) {
		std::cout << "TECLA W\n";
		//Vector3D dirNueva = Vector3D(std::cos(transformCamara->getRot().getY() * toRadians), 0, -std::sin(transformCamara->getRot().getY() * toRadians)) * vel;
		Vector3D dirNueva = Vector3D(0, 0, -1) * _vel;
		_rbToMove->setVelocity(dirNueva);
		//std::cout << "Posicion mono: " << rb->getPosition().getZ() << "\n";
		//std::cout << "Ratacion Camara: " << transformCamara->getRot().getY() << "\n";

	}
	if (msg == MessageType::A) {
		//Vector3D dirNueva = Vector3D(std::cos((transformCamara->getRot().getY() + 90) * toRadians), 0, -std::sin((transformCamara->getRot().getY() + 90) * toRadians)) * vel;
		Vector3D dirNueva = Vector3D(0, 0, -1) * _vel;
		_rbToMove->setVelocity(dirNueva);
		//std::cout << "Posicion mono: " << rb->getPosition().getX() << " ," << rb->getPosition().getY() << "\n";
		//std::cout << "Ratacion Camara: " << transformCamara->getRot().getY() << "\n";

	}
	if (msg == MessageType::S) {
		//Vector3D dirNueva = Vector3D(-std::cos(transformCamara->getRot().getY() * toRadians), 0, std::sin(transformCamara->getRot().getY() * toRadians)) * vel;
		Vector3D dirNueva = Vector3D(0, 0, -1) * _vel;
		_rbToMove->setVelocity(dirNueva);
		//std::cout << "Ratacion Camara: " << transformCamara->getRot().getY() << "\n";

	}
	if (msg == MessageType::D) {
		//Vector3D dirNueva = Vector3D(std::cos((transformCamara->getRot().getY() - 90) * toRadians), 0, -std::sin((transformCamara->getRot().getY() - 90) * toRadians)) * vel;
		Vector3D dirNueva = Vector3D(0, 0, -1) * _vel;
		_rbToMove->setVelocity(dirNueva);
		//_oNode->setPosition(Ogre::Vector3(_oNode->getPosition().x + 1000, _oNode->getPosition().y, _oNode->getPosition().z));
		//std::cout << "Posicion mono: " << rb->getPosition().getX() <<" ,"  << _oNode->getPosition().x << "\n";
		//std::cout << "Ratacion Camara: " << transformCamara->getRot().getY() << "\n";



	}



}