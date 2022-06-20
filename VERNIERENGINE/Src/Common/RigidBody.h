#pragma once
#include "Component.h"
#include "EngineDll.h"
#include "Vector3D.h"
#include <map>
enum CT_Collider;
class btRigidBody;

class btManifoldPoint;

const float TIME_TO_EXIT = 0.1f;


class V3RN13R_API Rigidbody: public Component
{
public:
	Rigidbody(Entity* e = nullptr) {};
	Rigidbody(std::map<std::string, std::string> args);
	~Rigidbody();
	void addSphereRigidbody (float mass,float radius,Vector3D pos, bool statc=false);
	void addBoxRigidbody(float mass, Vector3D pos, Vector3D size, bool statc=false);

	virtual void update() override;
	virtual void firstUpdate() override;
	virtual void lateUpdate() override;
	virtual void onEnable() override;
	virtual void onDisable() override;
	Vector3D getPosition();

	void resetTransform(Vector3D v1, float q1, float q2, float q3, float q4);
	void clearForce();
	void setCenterRb(Vector3D dir);

	static void sendContacts(void* first, void* other, const btManifoldPoint& manifold);
	void contact(Rigidbody* other, const btManifoldPoint& manifold);


	void setVelocity(Vector3D dir);
	void addImpulse(Vector3D dir);
	void addForce(Vector3D dir);

	Vector3D getGravity();
	Vector3D getVel();


private:

	struct CollisionInfo {
		Rigidbody* rb = nullptr;
		float time = 0;
		Vector3D point;
		bool _isTrigger;

	};

	bool _isNew;
	void setTrigger(bool trigger);

	btRigidBody* _brb =nullptr;
	std::string _type;
	float _mass = 1;
	float _radius;
	Vector3D _position;
	Vector3D _scale;
	bool _static;
	Vector3D _positionConstrains;
	Vector3D _rotationConstrains;
	bool _isTrigger;

	std::vector<CollisionInfo> collisions;

};
