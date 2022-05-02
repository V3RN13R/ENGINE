#pragma once

#include "Component.h"
#include "Vector3D.h"
#include <map>
#include <string>

class Entity;
class btRigidBody;
class btVector3;
class Rigidbody;
class Transform;

class BananaMovement : public Component {
private:
	float _ttl;
	float _speed = 3.0;
	double _lastTime = 0;
	Vector3D _dir;
	std::string _disparador;
	Entity* _disparadorEnt;
	Transform* _transformDisp = nullptr;
	Transform* _tr = nullptr;
	Transform* _trMono = nullptr;
	Rigidbody* _rb = nullptr;
	float lastTime_ = .0;
public:

	BananaMovement(std::map<std::string, std::string> args, Entity* ent);
	~BananaMovement();
	void start() override;
	void update() override;
	//virtual void onCollisionEnter(Entity* other, Vector3D point, Vector3D normal);
	//virtual void onCollisionStay(Entity* ohter, Vector3D point) {};

	Vector3D getDir() { return _dir; }
	void setDir(Vector3D d) { _dir = d; }
	float getSpeed() { return _speed; }
	void setSpeed(float s) { _speed = s; }	
};