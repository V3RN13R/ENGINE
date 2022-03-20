#include "PhysicsManager.h"


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
			_instance->init(Vector3D(0.0, -9.8, 0.0));
		}
		catch (...) {
			return false;
		}
	}

	return true;
}

void PhysicsManager::stepPhysics()
{
	dynamicsWorld->stepSimulation(1.f / 60.f, 10);
}

PhysicsManager::PhysicsManager(){
	//registerComponent("RigidBody", 0, []() -> RigidBody * { return new RigidBody(); });

}
PhysicsManager::~PhysicsManager()
{
	delete collConfig;
	delete collDispatcher;
	delete broadPhaseInterface;
	delete constraintSolver;
	delete dynamicsWorld;
}


void PhysicsManager::init(const Vector3D gravity)
{
	collConfig = new btDefaultCollisionConfiguration();

	collDispatcher = new btCollisionDispatcher(collConfig);

	broadPhaseInterface = new btDbvtBroadphase();
	constraintSolver = new btSequentialImpulseConstraintSolver();

	dynamicsWorld = new btDiscreteDynamicsWorld(collDispatcher, broadPhaseInterface,
		constraintSolver, collConfig);

	dynamicsWorld->setGravity(btVector3(gravity.getX(), gravity.getY(), gravity.getZ()));
/*
#ifdef _DEBUG
	mDebugDrawer_ = new OgreDebugDrawer(OgreContext::getInstance()->getSceneManager());
	mDebugDrawer_->setDebugMode(btIDebugDraw::DBG_DrawWireframe);
	dynamicsWorld->setDebugDrawer(mDebugDrawer_);
#endif // DEBUG
*/

}

void PhysicsManager::clean()
{
	delete this;
}

btRigidBody* PhysicsManager::addSphereRigidbody(float mass,float radius, btVector3 pos)
{
	btTransform startTransform;
	startTransform.setIdentity();
	startTransform.setOrigin(pos);
	btRigidBody* rb = new btRigidBody(mass, new btDefaultMotionState(startTransform), new btSphereShape(radius), btVector3(0, 0, 0));
	 dynamicsWorld->addRigidBody(rb);
	 return rb;
}

btRigidBody* PhysicsManager::addBoxRigidbody(float mass, btVector3 pos, btVector3 size)
{

	btTransform startTransform;
	startTransform.setIdentity();
	startTransform.setOrigin(pos);
	btRigidBody* rb = new btRigidBody(mass, new btDefaultMotionState(startTransform), new btBoxShape(size) , btVector3(0, 0, 0));
	dynamicsWorld->addRigidBody(rb);
	return rb;
}

