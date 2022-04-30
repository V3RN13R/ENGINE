#pragma once

#include "Component.h"
#include "Vector3D.h"
#include <map>
#include <string>


class btRigidBody;
class btVector3;
class Rigidbody;
class Transform;

class BananaMovement : public Component {
private:
	Vector3D dirFinal = Vector3D(0, 0, 0);
	Rigidbody* _rbToMove = nullptr;
	Transform* transformCamara = nullptr;
	std::string _entidadBuscar;
	int jumps;
	float  _vel;

	//Stats
	float _speed;
	float _jump;

	void update();
public:

	BananaMovement() {}
	BananaMovement(std::map<std::string, std::string> args);
	~BananaMovement() {}
	void start();
	void receiveEvent(MessageType msg, Entity* e);
	virtual void onCollisionEnter(Entity* other, Vector3D point, Vector3D normal);
	virtual void onCollisionStay(Entity* ohter, Vector3D point) {};

};

