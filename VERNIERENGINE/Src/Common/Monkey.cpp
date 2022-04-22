#include "Monkey.h"
#include "RigidBody.h"
#include <iostream>
#include <Ogre.h>
#include "Transform.h"
#include <math.h>
#include "Scene.h"


const float M_PI = 3.1416;
const float toRadians = M_PI / 180.0;


void Monkey::receiveEvent(MessageType msg, Entity* e) {
	if (msg == MessageType::W) {
		std::cout << "TECLA W\n";
		Rigidbody* rb = getComponent<Rigidbody>();
		Vector3D dirNueva = Vector3D(std::cos(transformCamara->getRot().getY()*toRadians), 0, -std::sin(transformCamara->getRot().getY()*toRadians))*vel;
		rb->setVelocity(dirNueva);
		//std::cout << "Posición mono: " << rb->getPosition().getZ() << "\n";
		std::cout << "Ratación Camara: " << transformCamara->getRot().getY() << "\n";
		
	}
	if (msg == MessageType::A) {
		std::cout << "TECLA A\n";
		Rigidbody* rb = getComponent<Rigidbody>();
		Vector3D dirNueva = Vector3D(std::cos((transformCamara->getRot().getY()+90) * toRadians), 0, -std::sin((transformCamara->getRot().getY() + 90) * toRadians))*vel;
		rb->setVelocity(dirNueva);
		//std::cout << "Posición mono: " << rb->getPosition().getX() << " ," << rb->getPosition().getY() << "\n";
		std::cout << "Ratación Camara: " << transformCamara->getRot().getY() << "\n";

	}
	if (msg == MessageType::S) {
		std::cout << "TECLA S\n";
		Rigidbody* rb = getComponent<Rigidbody>();
		Vector3D dirNueva = Vector3D(-std::cos(transformCamara->getRot().getY() * toRadians), 0, std::sin(transformCamara->getRot().getY() * toRadians))*vel;
		rb->setVelocity(dirNueva);
		std::cout << "Ratación Camara: " << transformCamara->getRot().getY() << "\n";

	}
	if (msg == MessageType::D) {
		std::cout << "TECLA D\n";
		Rigidbody* rb = getComponent<Rigidbody>();
		Vector3D dirNueva = Vector3D(std::cos((transformCamara->getRot().getY() - 90) * toRadians), 0, -std::sin((transformCamara->getRot().getY() - 90) * toRadians))*vel;
		rb->setVelocity(dirNueva);
		//_oNode->setPosition(Ogre::Vector3(_oNode->getPosition().x + 1000, _oNode->getPosition().y, _oNode->getPosition().z));
		//std::cout << "Posición mono: " << rb->getPosition().getX() <<" ,"  << _oNode->getPosition().x << "\n";
		std::cout << "Ratación Camara: " << transformCamara->getRot().getY() << "\n";

		

	}
}