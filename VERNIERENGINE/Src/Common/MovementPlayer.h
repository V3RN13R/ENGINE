#pragma once

#include "Component.h"
#include "Vector3D.h"
#include <map>

class btRigidBody;
class btVector3;
class Rigidbody;

class MovementPlayer : public Component {
private:
	Rigidbody* _rbToMove = nullptr;
	float  _vel;
public:
	MovementPlayer() {}
	MovementPlayer(std::map<std::string, std::string> args);
	~MovementPlayer() {}
	bool init();
	void receiveEvent(MessageType msg, Entity* e);

};