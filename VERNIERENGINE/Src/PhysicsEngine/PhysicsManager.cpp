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
	for (int i = 0; i < 100; i++){
		dynamicsWorld->stepSimulation(1.f / 60.f, 10);
		for (int j = dynamicsWorld->getNumCollisionObjects() - 1; j >= 0; j--) {
			btCollisionObject* obj = dynamicsWorld->getCollisionObjectArray()[j];
			btRigidBody* body = btRigidBody::upcast(obj);
			btTransform trans;

			if (body && body->getMotionState()) {
				body->getMotionState()->getWorldTransform(trans);
			}
			else {
				trans = obj->getWorldTransform();
			}
			btVector3 v3 = body->getLinearVelocity();
			std::cout << "Y: " << v3.getY();
		}
	}
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


	float startx = 0, starty = 1, startz = 10;
	float radius = 0.1;
	btCollisionShape* colShape = new btSphereShape(btScalar(radius));
	btTransform startTransform;
	startTransform.setIdentity();
	btScalar mass2(1.f);
	btVector3 localInertia2(0, 0, 0);
	colShape->calculateLocalInertia(mass2, localInertia2);
	startTransform.setOrigin(btVector3(startx, starty, startz));
	btDefaultMotionState* myMotionState2 = new btDefaultMotionState(startTransform);
	btRigidBody::btRigidBodyConstructionInfo rbInfo2(mass2, myMotionState2, colShape, localInertia2);
	btRigidBody* body2 = new btRigidBody(rbInfo2);
	body2->setRestitution(0.2);
	dynamicsWorld->addRigidBody(body2);
}

void PhysicsManager::clean()
{
	delete this;
}
