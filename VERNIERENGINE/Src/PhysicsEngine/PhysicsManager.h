#pragma once
#include <map>

class btDefaultCollisionConfiguration;
class btCollisionDispatcher;
class btBroadphaseInterface;
class btSequentialImpulseConstraintSolver;
class btDiscreteDynamicsWorld;
class btRigidBody;
class OgreDebugDrawer;
class Vector3;
class CollisionObject;
class btCollisionObject;

class PhysicsManager {
public:
	static PhysicsManager* getInstance();
	static bool setUpInstance();

	//inicializa todas las variables fisicas asi como el "mundo" a partir de dichas variables
	void init(const Vector3 gravity);
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

	std::map<const btCollisionObject*, std::pair<CollisionObject*, CollisionObject*>> contacts;

};