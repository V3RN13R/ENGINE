#include "MovementPlayer.h"
#include "PhysicsManager.h"
#include <btBulletCollisionCommon.h>
#include "btBulletDynamicsCommon.h"
#include "Utils.h"
#include "Entity.h"
#include "RigidBody.h"
#include "Transform.h"
#include "Scene.h"


const float _PI = 3.1416;
const float toRadians = _PI / 180.0;
const float toAngles = 180.0 / _PI;

MovementPlayer::MovementPlayer(std::map<std::string, std::string> args) : _vel(std::stof(args["Vel"])), _entidadBuscar(args["Entity"])
{
	std::cout << "Contructora lua MovementPlayer\n";
}

void MovementPlayer::start()
{
	transformCamara = static_cast<Transform*>(entity_->getScene()->getObjectWithName(_entidadBuscar)->getComponent("Transform"));

}

void MovementPlayer::update(){
	if (_rbToMove) {
		std::cout << "Posicion rb en Y mono: " << _rbToMove->getPosition().getY() << "\n";
	}
	std::cout << "Posicion transform en Y mono : " << static_cast<Transform*>(entity_->getComponent("Transform"))->getPos().getY() << "\n";
}
void MovementPlayer::receiveEvent(MessageType msg, Entity* e) {
	
	_rbToMove = static_cast<Rigidbody*>(entity_->getComponent("Rigidbody"));
	if (msg == MessageType::W) {
		std::cout << "TECLA W\n";
		Vector3D dirNueva = Vector3D(std::cos(transformCamara->getRot().getY() * toRadians), 0, -std::sin(transformCamara->getRot().getY() * toRadians)) * _vel;
		//Vector3D dirNueva = Vector3D(0, 0, -1) * _vel;
		_rbToMove->setVelocity(dirNueva);
		std::cout << "Posicion mono: " << _rbToMove->getPosition().getZ() << "\n";
		//std::cout << "Ratacion Camara: " << transformCamara->getRot().getY() << "\n";

	}
	if (msg == MessageType::A) {
		Vector3D dirNueva = Vector3D(std::cos((transformCamara->getRot().getY() + 90) * toRadians), 0, -std::sin((transformCamara->getRot().getY() + 90) * toRadians)) * _vel;
		//Vector3D dirNueva = Vector3D(0, 0, -1) * _vel;
		_rbToMove->setVelocity(dirNueva);
		//std::cout << "Posicion mono: " << rb->getPosition().getX() << " ," << rb->getPosition().getY() << "\n";
		//std::cout << "Ratacion Camara: " << transformCamara->getRot().getY() << "\n";

	}
	if (msg == MessageType::S) {
		Vector3D dirNueva = Vector3D(-std::cos(transformCamara->getRot().getY() * toRadians), 0, std::sin(transformCamara->getRot().getY() * toRadians)) * _vel;
		//Vector3D dirNueva = Vector3D(0, 0, -1) * _vel;
		_rbToMove->setVelocity(dirNueva);
		//std::cout << "Ratacion Camara: " << transformCamara->getRot().getY() << "\n";

	}
	if (msg == MessageType::D) {
		Vector3D dirNueva = Vector3D(std::cos((transformCamara->getRot().getY() - 90) * toRadians), 0, -std::sin((transformCamara->getRot().getY() - 90) * toRadians)) * _vel;
		//Vector3D dirNueva = Vector3D(0, 0, -1) * _vel;
		_rbToMove->setVelocity(dirNueva);
		//_oNode->setPosition(Ogre::Vector3(_oNode->getPosition().x + 1000, _oNode->getPosition().y, _oNode->getPosition().z));
		//std::cout << "Posicion mono: " << rb->getPosition().getX() <<" ,"  << _oNode->getPosition().x << "\n";
		//std::cout << "Ratacion Camara: " << transformCamara->getRot().getY() << "\n";



	}



}