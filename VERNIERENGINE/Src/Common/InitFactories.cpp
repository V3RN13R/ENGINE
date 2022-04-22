#include "Factory.h"
#include "FactoryManager.h"
#include "MeshRenderer.h"
#include "Transform.h"
#include "RigidBody.h"
class TransformFactory : public Factory
{
public:
	Component* createComponent(std::map<std::string, std::string> args) override
	{		
		return new Transform(args);
	};
};

class MeshRendererFactory : public Factory
{
public:
	Component* createComponent(std::map<std::string, std::string> args) override
	{
		return new MeshRenderer(args);
	};
};

class RigidBodyFactory : public Factory
{
public:
	Component* createComponent(std::map<std::string, std::string> args) override
	{
		return new Rigidbody(args);
	};
};

void setupFactories()
{
	FactoryManager* _fM = FactoryManager::getInstance();

	_fM->addFactory("Transform", new TransformFactory());
	_fM->addFactory("MeshRenderer", new MeshRendererFactory());
	_fM->addFactory("Rigidbody", new RigidBodyFactory());
}