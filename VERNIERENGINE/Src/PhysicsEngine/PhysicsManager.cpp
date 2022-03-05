//#include "PhysicsManager.h"
//
//
//#include <btBulletCollisionCommon.h>
//#include <btBulletDynamicsCommon.h>
//
////#include "Vector3D.h"
//
//PhysicsManager* PhysicsManager::_instance = nullptr;
//PhysicsManager* PhysicsManager::getInstance()
//{
//	return _instance;
//}
//
//bool PhysicsManager::setUpInstance() {
//	if (_instance == nullptr) {
//		try {
//			_instance = new PhysicsManager();
//			_instance->init(Vector3(0.0, -9.8, 0.0));
//		}
//		catch (...) {
//			return false;
//		}
//	}
//
//	return true;
//}
//
//PhysicsManager::PhysicsManager(){
//	//registerComponent("RigidBody", 0, []() -> RigidBody * { return new RigidBody(); });
//
//}
//PhysicsManager::~PhysicsManager()
//{
//}
//;
//
//void PhysicsManager::init(const Vector3 gravity)
//{
//	collConfig = new btDefaultCollisionConfiguration();
//
//	collDispatcher = new btCollisionDispatcher(collConfig);
//
//	broadPhaseInterface = new btDbvtBroadphase();
//	constraintSolver = new btSequentialImpulseConstraintSolver();
//
//	dynamicsWorld = new btDiscreteDynamicsWorld(collDispatcher, broadPhaseInterface,
//		constraintSolver, collConfig);
//
//	dynamicsWorld->setGravity(btVector3(gravity.x, gravity.y, gravity.z));
///*
//#ifdef _DEBUG
//	mDebugDrawer_ = new OgreDebugDrawer(OgreContext::getInstance()->getSceneManager());
//	mDebugDrawer_->setDebugMode(btIDebugDraw::DBG_DrawWireframe);
//	dynamicsWorld->setDebugDrawer(mDebugDrawer_);
//#endif // DEBUG
//*/
//}
