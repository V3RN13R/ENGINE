#include "RigidBody.h"
#include "Entity.h"
#include "Transform.h"
#include "PhysicsManager.h"
#include <btBulletDynamicsCommon.h>

Rigidbody::~Rigidbody()
{
	/*PhysicsManager::getInstance()->getDynamicsWorld()->removeRigidBody(_brb);
	delete _brb;*/
}

void Rigidbody::addSphereRigidbody (float mass,float radius,Vector3D pos,bool statc)
{
	_brb = PhysicsManager::getInstance()->addSphereRigidbody(mass, radius, {pos.getX(),pos.getY(),pos.getZ()});
}

void Rigidbody::addBoxRigidbody(float mass, Vector3D pos, Vector3D size, bool statc)
{
	_brb = PhysicsManager::getInstance()->addBoxRigidbody(mass, { pos.getX(),pos.getY(),pos.getZ() }, { size.getX(),size.getY(),size.getZ() });
}

void Rigidbody::fixedUpdate()
{
}

Vector3D Rigidbody::getPosition()
{
	return Vector3D(_brb->getCenterOfMassTransform().getOrigin().getX(), _brb->getCenterOfMassTransform().getOrigin().getY(), _brb->getCenterOfMassTransform().getOrigin().getZ());
}


void Rigidbody::setVelocity(Vector3D dir) {
	//_brb->setLinearVelocity(btVector3(dir.getX(), dir.getY(), dir.getZ()));
	_brb->applyCentralForce(btVector3(dir.getX(), dir.getY(), dir.getZ()));

	std::cout << "Vel X bullet: " << _brb->getWorldTransform().getOrigin().getX() << "\n";
};
