
//
//
//
//void Monkey::receiveEvent(MessageType msg, Entity* e) {
//	if (msg == MessageType::W) {
//		std::cout << "TECLA W\n";
//		Rigidbody* rb = getComponent<Rigidbody>();
//		Vector3D dirNueva = Vector3D(std::cos(transformCamara->getRot().getY()*toRadians), 0, -std::sin(transformCamara->getRot().getY()*toRadians))*vel;
//		rb->setVelocity(dirNueva);
//		//std::cout << "Posici�n mono: " << rb->getPosition().getZ() << "\n";
//		std::cout << "Rataci�n Camara: " << transformCamara->getRot().getY() << "\n";
//		
//	}
//	if (msg == MessageType::A) {
//		std::cout << "TECLA A\n";
//		Rigidbody* rb = getComponent<Rigidbody>();
//		Vector3D dirNueva = Vector3D(std::cos((transformCamara->getRot().getY()+90) * toRadians), 0, -std::sin((transformCamara->getRot().getY() + 90) * toRadians))*vel;
//		rb->setVelocity(dirNueva);
//		//std::cout << "Posici�n mono: " << rb->getPosition().getX() << " ," << rb->getPosition().getY() << "\n";
//		std::cout << "Rataci�n Camara: " << transformCamara->getRot().getY() << "\n";
//
//	}
//	if (msg == MessageType::S) {
//		std::cout << "TECLA S\n";
//		Rigidbody* rb = getComponent<Rigidbody>();
//		Vector3D dirNueva = Vector3D(-std::cos(transformCamara->getRot().getY() * toRadians), 0, std::sin(transformCamara->getRot().getY() * toRadians))*vel;
//		rb->setVelocity(dirNueva);
//		std::cout << "Rataci�n Camara: " << transformCamara->getRot().getY() << "\n";
//
//	}
//	if (msg == MessageType::D) {
//		std::cout << "TECLA D\n";
//		Rigidbody* rb = getComponent<Rigidbody>();
//		Vector3D dirNueva = Vector3D(std::cos((transformCamara->getRot().getY() - 90) * toRadians), 0, -std::sin((transformCamara->getRot().getY() - 90) * toRadians))*vel;
//		rb->setVelocity(dirNueva);
//		//_oNode->setPosition(Ogre::Vector3(_oNode->getPosition().x + 1000, _oNode->getPosition().y, _oNode->getPosition().z));
//		//std::cout << "Posici�n mono: " << rb->getPosition().getX() <<" ,"  << _oNode->getPosition().x << "\n";
//		std::cout << "Rataci�n Camara: " << transformCamara->getRot().getY() << "\n";
//
//		
//
//	}
//}