#pragma once

#include "Component.h"
#include "Vector3D.h"
#include <map>
#include <string>


class btRigidBody;
class btVector3;
class Rigidbody;
class Transform;

class MovementPlayer : public Component {
private:
	Rigidbody* _rbToMove = nullptr;
	Transform* transformCamara = nullptr;
	std::string _entidadBuscar;
	float  _vel;
	void update();
public:

	MovementPlayer() {}
	MovementPlayer(std::map<std::string, std::string> args);
	~MovementPlayer() {}
	void start();
	void receiveEvent(MessageType msg, Entity* e);

};