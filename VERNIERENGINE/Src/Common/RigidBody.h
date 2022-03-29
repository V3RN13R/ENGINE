#include "Component.h"
#include "Vector3D.h"
enum CT_Collider;
class btRigidBody;
class Rigidbody: public Component
{
public:
	Rigidbody(Entity* e = nullptr) {};
	~Rigidbody();
	void addSphereRigidbody (float mass,float radius,Vector3D pos, bool statc=false);
	void addBoxRigidbody(float mass, Vector3D pos, Vector3D size, bool statc=false);
	//virtual void preUpdate() override;

	virtual void fixedUpdate() override;
	Vector3D getPosition();
	//virtual void lateUpdate() override;
private:
	btRigidBody* _brb=nullptr;
	float _mass = 1;
	bool _static;
	Vector3D _positionConstrains;
	Vector3D _rotationConstrains;

};
