#pragma once
#include <map>
#include <vector>

class btDefaultCollisionConfiguration;
class btCollisionDispatcher;
class btBroadphaseInterface;
class btSequentialImpulseConstraintSolver;
class btDiscreteDynamicsWorld;
class btRigidBody;
class OgreDebugDrawer;
class CollisionObject;
class btCollisionObject;
class btCollisionShape;
class Vector3D;
class btVector3;
class btManifoldPoint;
enum ColliderType
{
	CT_BOX,
	CT_SPHERE,
	CT_TRIMESH,
	CT_HULL
};

class CollisionListener
{
public:
	CollisionListener(void(*d)(void*, void* other, const btManifoldPoint& mnf), void* o) : p(d), obj(o) {};
	~CollisionListener() {};
	void(*p)(void*, void* other, const btManifoldPoint& mnf);
	void* obj;
};


class PhysicsManager {
public:
	static PhysicsManager* getInstance();
	static bool setUpInstance();
	static void deleteInstance();

	btDiscreteDynamicsWorld* getDynamicsWorld() { return dynamicsWorld; }
	std::vector<btCollisionShape*> getCollisionShapes() { return collisionShapes; }
	void stepPhysics();
	void stopObjectSimulation(btRigidBody* brb);
	void resumeObjectSimulation(btRigidBody* brb);
	//void trackRigidBodyWithName(btRigidBody* body, std::string physicsCubeName) { physicsAccessors.insert({ std::string("cube"), body }); }
	// 
	// 
	// 
	//inicializa todas las variables fisicas asi como el "mundo" a partir de dichas variables
	void init(const Vector3D gravity);
	btRigidBody* addSphereRigidbody(float mass, float radius, btVector3 pos, void(*d)(void*, void* other, const btManifoldPoint& mnf),void* listener);
	btRigidBody* addBoxRigidbody(float mass, btVector3 pos, btVector3 size, void(*d)(void*, void* other, const btManifoldPoint& mnf), void* listener);
private:
	PhysicsManager();
	virtual ~PhysicsManager();
	static PhysicsManager* _instance;

	//cosas de bullet
	//Configuracion sobre la gestion de colisiones con bullet, nosotros usaremos la configuracion por defecto
	btDefaultCollisionConfiguration* collConfig = nullptr;

	//Variable de bullet que hace de "pasador" de colisiones
	btCollisionDispatcher* collDispatcher = nullptr;

	//Variable de bullet que se usa para hacer calculos de manera eficiente para generar posibles colisiones
	btBroadphaseInterface* broadPhaseInterface = nullptr;

	//Variable de bullet que hace de solucionador de restricciones 
	btSequentialImpulseConstraintSolver* constraintSolver = nullptr;

	//Variable de bullet a la que se le pasa todas las variables anteriores como configuracion de la fisica
	btDiscreteDynamicsWorld* dynamicsWorld = nullptr;

	//Esto seria para dibujar los colliders en un modo debug, lo queremos?
	OgreDebugDrawer* mDebugDrawer_ = nullptr;


	std::vector<btCollisionShape*> collisionShapes;

	std::map<const btCollisionObject*, std::pair<CollisionObject*, CollisionObject*>> contacts;

};