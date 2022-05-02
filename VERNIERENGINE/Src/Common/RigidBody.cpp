#include "RigidBody.h"
#include "Entity.h"
#include "Transform.h"
#include "Component.h"
#include "ENGINE.h"
#include "VernierTime.h"
#include "PhysicsManager.h"
#include <btBulletDynamicsCommon.h>

Rigidbody::Rigidbody(std::map<std::string, std::string> args) : _position(args["Position"]) , _type(args["Type"])
{
	std::cout << "Masa en cosntructora lua: " << args["Mass"] << "\n";
	_isNew = true;
	if (args["isTrigger"] == "true") {
		_isTrigger = true;
	}
	else {
		_isTrigger = false;
	}
	
	
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
	_brb = VernierEngine::getInstance()->getPhysicsMng()->addSphereRigidbody(mass, radius, { pos.getX(),pos.getY(),pos.getZ() }, &sendContacts, this);
	setTrigger(_isTrigger);
	
	_brb->setActivationState(DISABLE_DEACTIVATION);
}

void Rigidbody::addBoxRigidbody(float mass, Vector3D pos, Vector3D size, bool statc)
{
	_brb = VernierEngine::getInstance()->getPhysicsMng()->addBoxRigidbody(mass, { pos.getX(),pos.getY(),pos.getZ() }, { size.getX(),size.getY(),size.getZ() }, &sendContacts, this);
	setTrigger(_isTrigger);
	_brb->setActivationState(DISABLE_DEACTIVATION);
}

void Rigidbody::update()
{
	for (CollisionInfo& cI : collisions) {
		cI.time += VernierEngine::getInstance()->getTime()->deltaTime();
	}
}

void Rigidbody::fixedUpdate()
{
	//clearForce();

}

void Rigidbody::lateUpdate()
{
	for (auto it = collisions.begin(); it != collisions.end();) {

		if ((it)->time > TIME_TO_EXIT) {
			if ((it)->rb)
				((it)->_isTrigger) ? entity_->onTriggerExit((it)->rb->entity_, (*it).point) : entity_->onCollisionExit((it)->rb->entity_, (it)->point);
			it = collisions.erase(it);
		}
		else
			it++;
	}
}

void Rigidbody::onEnable()
{
	Component::onEnable();
	if (!_isNew) {
		PhysicsManager::getInstance()->resumeObjectSimulation(_brb);
	}
	_isNew = false;

}

void Rigidbody::onDisable()
{
	Component::onDisable();
	PhysicsManager::getInstance()->stopObjectSimulation(_brb);

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


void Rigidbody::setTrigger(bool trigger)
{
	trigger = trigger;

	if (trigger)
		_brb->setCollisionFlags(btCollisionObject::CollisionFlags::CF_NO_CONTACT_RESPONSE);
	else
		_brb->setCollisionFlags(0);
}


void Rigidbody::sendContacts(void* first, void* other, const btManifoldPoint& manifold)
{
	static_cast<Rigidbody*>(first)->contact(static_cast<Rigidbody*>(other), manifold);
}

void Rigidbody::contact(Rigidbody* other, const btManifoldPoint& manifold)
{
	btVector3 v = manifold.getPositionWorldOnA();

	for (auto it = collisions.begin(); it != collisions.end(); ++it) {
		if (it->rb == other) {
			it->time = 0;
			it->point = Vector3D((float)v.x(), (float)v.y(), (float)v.z());
			entity_->onCollisionStay(other->entity_, it->point);
			return;
		}
		
	}

	/*for (CollisionInfo& obj : collisions) {
		if (obj.rb == other) {
			obj.time = 0;
			obj.point = Vector3D((float)v.x(), (float)v.y(), (float)v.z());
			entity_->onCollisionStay(other->entity_, obj.point);
			return;
		}
	}*/
	
	Vector3D p = Vector3D((float)v.x(), (float)v.y(), (float)v.z());
	collisions.push_back({ other,0 , p , other->_isTrigger || _isTrigger });
	(other->_isTrigger  || _isTrigger) ? entity_->onTriggerEnter(other->entity_, p) : entity_->onCollisionEnter(other->entity_, p, Vector3D(manifold.m_normalWorldOnB.getX(), manifold.m_normalWorldOnB.getY(), manifold.m_normalWorldOnB.getZ()));
	
}

void Rigidbody::setVelocity(Vector3D dir) {
	/*_brb->activate();*/
	_brb->setLinearVelocity(btVector3(dir.getX(), dir.getY(), dir.getZ()));


	//_brb->applyCentralForce(btVector3(dir.getX(), dir.getY(), dir.getZ())*50);
	//_brb->applyCentralImpulse(btVector3(dir.getX(), dir.getY(), dir.getZ()));
	//_brb->setLinearVelocity(btVector3(dir.getX(), dir.getY(), dir.getZ()));



	/*btTransform transform = _brb->getCenterOfMassTransform();
	transform.setOrigin(btVector3(transform.getOrigin().getX() + dir.getX(), transform.getOrigin().getY() + dir.getY(), transform.getOrigin().getZ() + dir.getZ()));
	_brb->setCenterOfMassTransform(transform);*/


	//std::cout << "Vel X bullet: " << _brb->getLinearVelocity().getX() << "\n";
}

void Rigidbody::setCenterRb(Vector3D dir) {
	btTransform transform = _brb->getCenterOfMassTransform();
	transform.setOrigin(btVector3(transform.getOrigin().getX() + dir.getX(), transform.getOrigin().getY() + dir.getY(), transform.getOrigin().getZ() + dir.getZ()));
	_brb->setCenterOfMassTransform(transform);
}
void Rigidbody::addImpulse(Vector3D dir)
{
	_brb->applyCentralImpulse(btVector3(dir.getX(), dir.getY(), dir.getZ()));

};
void Rigidbody::addForce(Vector3D dir)
{
	_brb->applyCentralForce(btVector3(dir.getX(), dir.getY(), dir.getZ()));

};
Vector3D Rigidbody::getGravity() {
	return Vector3D(_brb->getGravity().getX(), _brb->getGravity().getY(), _brb->getGravity().getZ());

}
Vector3D Rigidbody::getVel() {
	return Vector3D(_brb->getLinearVelocity().getX(), _brb->getLinearVelocity().getY(), _brb->getLinearVelocity().getZ());
}
