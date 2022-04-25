#include "RigidBody.h"
#include "Entity.h"
#include "Transform.h"
#include "Component.h"
#include "PhysicsManager.h"
#include <btBulletDynamicsCommon.h>

Rigidbody::Rigidbody(std::map<std::string, std::string> args) : _position(args["Position"]) , _type(args["Type"])
{
	std::cout << "Masa en cosntructora lua: " << args["Mass"] << "\n";
	_mass = std::stof(args["Mass"]);
	if (_type == "Sphere") {
		_radius = std::stof(args["Radius"]);
		addSphereRigidbody(_mass, _radius, _position);
	}
	else if (_type == "Box")
	{
		_scale = args["Scale"];
		addBoxRigidbody(_mass, _position, _scale);
	}
	else {
		throw "ERROR: No se reconoce el tipo del rigid body\n";
	}
}

Rigidbody::~Rigidbody()
{
	/*PhysicsManager::getInstance()->getDynamicsWorld()->removeRigidBody(_brb);
	delete _brb;*/
}

void Rigidbody::addSphereRigidbody(float mass, float radius, Vector3D pos, bool statc)
{
	_brb = PhysicsManager::getInstance()->addSphereRigidbody(mass, radius, { pos.getX(),pos.getY(),pos.getZ() });

}

void Rigidbody::addBoxRigidbody(float mass, Vector3D pos, Vector3D size, bool statc)
{
	_brb = PhysicsManager::getInstance()->addBoxRigidbody(mass, { pos.getX(),pos.getY(),pos.getZ() }, { size.getX(),size.getY(),size.getZ() });
}

void Rigidbody::fixedUpdate()
{
	//clearForce();

}

Vector3D Rigidbody::getPosition()
{
	return Vector3D(_brb->getCenterOfMassTransform().getOrigin().getX(), _brb->getCenterOfMassTransform().getOrigin().getY(), _brb->getCenterOfMassTransform().getOrigin().getZ());
}


void Rigidbody::resetTransform(Vector3D v1, float q1, float q2, float q3, float q4)
{
	btTransform tr = _brb->getCenterOfMassTransform();
	Transform* transform = entity_->getComponent<Transform>();

	tr.setOrigin(btVector3(v1.getX(), v1.getY(), v1.getZ()));
	btQuaternion(q1, q2, q3, q4);
	tr.setRotation(btQuaternion(q1, q2, q3, q4));

	//tr.setOrigin({ transform->getPos().getX(), transform->getPos().getY(), transform->getPos().getZ() });
	//tr.setRotation({ transform->getRot().getX(), transform->getRot().getY(), transform->getRot().getZ() });

	_brb->setWorldTransform(tr);
	//_brb->getCollisionShape()->setLocalScaling({ transform->getScale().getX()/100, transform->getScale().getY()/100, transform->getScale().getZ()/100});
	_brb->getMotionState()->setWorldTransform(tr);

}

void Rigidbody::clearForce()
{
	_brb->clearForces();
	btVector3 v(0, 0, 0);
	_brb->setLinearVelocity(v);
	_brb->setAngularVelocity(v);
}

void Rigidbody::setVelocity(Vector3D dir) {
	/*_brb->activate();
	_brb->setLinearVelocity(btVector3(dir.getX(), dir.getY(), dir.getZ()));*/


	//_brb->applyCentralForce(btVector3(dir.getX(), dir.getY(), dir.getZ()));
	//_brb->applyCentralImpulse(btVector3(dir.getX(), dir.getY(), dir.getZ()));
	//_brb->setLinearVelocity(btVector3(dir.getX(), dir.getY(), dir.getZ()));



	btTransform transform = _brb->getCenterOfMassTransform();
	transform.setOrigin(btVector3(transform.getOrigin().getX() + dir.getX(), transform.getOrigin().getY() + dir.getY(), transform.getOrigin().getZ() + dir.getZ()));
	_brb->setCenterOfMassTransform(transform);


	//std::cout << "Vel X bullet: " << _brb->getLinearVelocity().getX() << "\n";
};
