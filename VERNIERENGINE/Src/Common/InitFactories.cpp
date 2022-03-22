#include "Factory.h"
#include "FactoryManager.h"
#include "Transform.h"
#include "RigidBody.h"
#include <map>
class TransformFactory : public Factory
{
public:
	Component* createComponent(std::map<std::string, std::string> args) override
	{		

		return new Transform(args);
	};
};

void setupFactories()
{
	FactoryManager* _fM = FactoryManager::getInstance();

	_fM->addFactory("Transform", new TransformFactory());
}