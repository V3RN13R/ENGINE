#include "Monkey.h"
#include "RigidBody.h"
#include <iostream>
#include <Ogre.h>


void Monkey::receiveEvent(MessageType msg, Entity* e) {
	if (msg == MessageType::W) {
		std::cout << "TECLA W\n";
		Rigidbody* rb = getComponent<Rigidbody>();
		rb->setVelocity(Vector3D(0, 0, -10));
		std::cout << "Posici�n mono: " << rb->getPosition().getZ() << "\n";
		
	}
	if (msg == MessageType::A) {
		std::cout << "TECLA A\n";
		Rigidbody* rb = getComponent<Rigidbody>();
		rb->setVelocity(Vector3D(-10, 0, 0));
		std::cout << "Posici�n mono: " << rb->getPosition().getX() << " ," << rb->getPosition().getY() << "\n";
	}
	if (msg == MessageType::S) {
		std::cout << "TECLA S\n";
		Rigidbody* rb = getComponent<Rigidbody>();
		rb->setVelocity(Vector3D(0, 0, 10));
	}
	if (msg == MessageType::D) {
		std::cout << "TECLA D\n";
		Rigidbody* rb = getComponent<Rigidbody>();
		rb->setVelocity(Vector3D(10, 0, 0));
		//_oNode->setPosition(Ogre::Vector3(_oNode->getPosition().x + 1000, _oNode->getPosition().y, _oNode->getPosition().z));
		std::cout << "Posici�n mono: " << rb->getPosition().getX() <<" ,"  << _oNode->getPosition().x << "\n";
		

	}
}