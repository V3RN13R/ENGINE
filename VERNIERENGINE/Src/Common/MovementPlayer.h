#pragma once

#include "Component.h"
#include "Vector3D.h"

class btRigidBody;
class btVector3;

class MovementPlayer : public Component {
private:
	char _c;
	btRigidBody* _mono;
public:
	MovementPlayer(btRigidBody* mono) : _mono(mono) {}
	~MovementPlayer() {}
	void mover();
	//virtual void sendEvent(MessageType msg);
	//virtual void receiveEvent(MessageType msg);
};