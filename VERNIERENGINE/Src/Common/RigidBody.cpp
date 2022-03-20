#include "RigidBody.h"
#include "Entity.h"
#include "Transform.h"
#include "PhysicsManager.h"
#include <btBulletDynamicsCommon.h>

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
