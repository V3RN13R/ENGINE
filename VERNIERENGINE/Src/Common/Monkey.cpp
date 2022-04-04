#include "Monkey.h"
#include "RigidBody.h"
#include <iostream>
void Monkey::receiveEvent(MessageType msg, Entity* e) {
	if (msg == MessageType::W) {
		std::cout << "TECLA W\n";
		Rigidbody* rb = getComponent<Rigidbody>();
		rb->setVelocity(Vector3D(0, 0, -1000));
		std::cout << "Posición mono: " << rb->getPosition().getX() << "\n";
		
	}
	if (msg == MessageType::A) {
		std::cout << "TECLA A\n";
		Rigidbody* rb = getComponent<Rigidbody>();
		rb->setVelocity(Vector3D(-1000, 0, 0));
		std::cout << "Posición mono: " << rb->getPosition().getX() << " ," << rb->getPosition().getY() << "\n";
	}
	if (msg == MessageType::S) {
		std::cout << "TECLA S\n";
	}
	if (msg == MessageType::D) {
		std::cout << "TECLA D\n";
		Rigidbody* rb = getComponent<Rigidbody>();
		rb->setVelocity(Vector3D(1000, 0, 0));
		std::cout << "Posición mono: " << rb->getPosition().getX() <<" ,"  << rb->getPosition().getY() << "\n";
	}
}