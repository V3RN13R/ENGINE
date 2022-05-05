#include "PhysicsManager.h"

#include <Windows.h> 
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>

#include "Vector3D.h"
#include <iostream>


PhysicsManager* PhysicsManager::_instance = nullptr;
PhysicsManager* PhysicsManager::getInstance()
{
	return _instance;
}

bool PhysicsManager::setUpInstance() {
	if (_instance == nullptr) {
		try {
			_instance = new PhysicsManager();
			_instance->init(Vector3D(0.0, -800, 0.0));
		}
		catch (...) {
			return false;
		}
	}

	return true;
}

void PhysicsManager::stepPhysics()
{
	double time = (double)GetTickCount64() / 1000.0 - _firstTime;
	dynamicsWorld->stepSimulation((time - _lastFrameTime, 10));
	_lastFrameTime = time;

	int numManifolds = dynamicsWorld->getDispatcher()->getNumManifolds();
	auto manifolds = dynamicsWorld->getDispatcher()->getInternalManifoldPointer();
	for (int i = 0; i < numManifolds; i++) {
		btPersistentManifold* manifold = manifolds[i];
		for (int j = 0; j < manifold->getNumContacts(); j++)
		{
			const btManifoldPoint& mp = manifold->getContactPoint(j);
			auto body0 = static_cast<CollisionListener*>(manifold->getBody0()->getUserPointer());
			auto body1 = static_cast<CollisionListener*>(manifold->getBody1()->getUserPointer());
			if (body0 && body1) {
				body0->p(body0->obj, body1->obj, mp);
				body1->p(body1->obj, body0->obj, mp);
			}				
		}
	}
}




void PhysicsManager::stopObjectSimulation(btRigidBody* brb) {
	dynamicsWorld->removeRigidBody(brb);
}

void PhysicsManager::resumeObjectSimulation(btRigidBody* brb) {
	dynamicsWorld->addRigidBody(brb);
}



PhysicsManager::PhysicsManager() {

}
PhysicsManager::~PhysicsManager()
{
	//cleanup in the reverse order of creation/initialization

		//remove the rigidbodies from the dynamics world and delete them
	int i;
	for (i = dynamicsWorld->getNumCollisionObjects() - 1; i >= 0; i--)
	{
		btCollisionObject* obj = dynamicsWorld->getCollisionObjectArray()[i];
		dynamicsWorld->removeCollisionObject(obj);
		delete obj;
	}

	//delete collision shapes
	for (unsigned int j = 0; j < collisionShapes.size(); j++)
	{
		btCollisionShape* shape = collisionShapes[j];
		delete shape;
	}

	delete dynamicsWorld;
	delete collConfig;
	delete collDispatcher;
	delete broadPhaseInterface;
	delete constraintSolver;
	delete mDebugDrawer_;
}


void PhysicsManager::init(const Vector3D gravity)
{
	collConfig = new btDefaultCollisionConfiguration();

	collDispatcher = new btCollisionDispatcher(collConfig);

	broadPhaseInterface = new btDbvtBroadphase();
	constraintSolver = new btSequentialImpulseConstraintSolver();
	
	dynamicsWorld = new btDiscreteDynamicsWorld(collDispatcher, broadPhaseInterface, constraintSolver, collConfig);

	dynamicsWorld->setGravity(btVector3(gravity.getX(), gravity.getY(), gravity.getZ()));

	_firstTime = (double)GetTickCount64() / 1000.0;
	_lastFrameTime = _firstTime - 0.01;
}

btRigidBody* PhysicsManager::addSphereRigidbody(float mass, float radius, btVector3 pos, void(*d)(void*, void* other, const btManifoldPoint& mnf), void* listener)
{
	btTransform startTransform;
	startTransform.setIdentity();
	startTransform.setOrigin(pos);

	btCollisionShape* sphereShape = new btSphereShape(radius);
	btScalar massSphere(mass);
	btVector3 sphereLocalInertia(1, 1, 1);
	sphereShape->calculateLocalInertia(massSphere, sphereLocalInertia);


	btRigidBody* rb = new btRigidBody(mass, new btDefaultMotionState(startTransform), sphereShape, btVector3(0, 0, 0));
	rb->setUserPointer(new CollisionListener(d,listener));
	rb->setCcdMotionThreshold(1e-7);
	rb->setCcdSweptSphereRadius(0.50);
	dynamicsWorld->addRigidBody(rb);

	return rb;
}

void PhysicsManager::deleteInstance()
{
	delete _instance;
}


btRigidBody* PhysicsManager::addBoxRigidbody(float mass, btVector3 pos, btVector3 size, void(*d)(void*, void* other, const btManifoldPoint& mnf), void* listener)
{

	btTransform startTransform;
	startTransform.setIdentity();
	startTransform.setOrigin(pos);
	btRigidBody* rb = new btRigidBody(mass, new btDefaultMotionState(startTransform), new btBoxShape(size), btVector3(0, 0, 0));
	rb->setUserPointer(new CollisionListener(d, listener));
	dynamicsWorld->addRigidBody(rb);
	return rb;
}