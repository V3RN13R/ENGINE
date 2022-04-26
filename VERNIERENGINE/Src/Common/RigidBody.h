#pragma once
#include "Component.h"
#include "Vector3D.h"
#include <map>
enum CT_Collider;
class btRigidBody;
class Component;
class Rigidbody: public Component
{
public:
	Rigidbody(Entity* e = nullptr) {};
	Rigidbody(std::map<std::string, std::string> args);
	~Rigidbody();
	void addSphereRigidbody (float mass,float radius,Vector3D pos, bool statc=false);
	void addBoxRigidbody(float mass, Vector3D pos, Vector3D size, bool statc=false);
	//virtual void preUpdate() override;

	virtual void fixedUpdate() override;
	virtual void onEnable() override;
	virtual void onDisable() override;
	Vector3D getPosition();
	//virtual void sendEvent(MessageType msg) {}
	//virtual void receiveEvent(MessageType msg) {}
	//virtual void lateUpdate() override;
	void resetTransform(Vector3D v1, float q1, float q2, float q3, float q4);
	void clearForce();

	void setVelocity(Vector3D dir);
private:
	btRigidBody* _brb=nullptr;
	std::string _type;
	float _mass = 1;
	float _radius;
	Vector3D _position;
	Vector3D _scale;
	bool _static;
	Vector3D _positionConstrains;
	Vector3D _rotationConstrains;

};
