#pragma once
#include "InitFactories.h"
#include "FactoryManager.h"
#include "MeshRenderer.h"
#include "Transform.h"
#include "RigidBody.h"
#include "Shoot.h"

Component* TransformFactory::createComponent(std::map<std::string, std::string> args, Entity* ent)
{
	return new Transform(args);
};


Component* MeshRendererFactory::createComponent(std::map<std::string, std::string> args, Entity* ent)
{
	return new MeshRenderer(args);
};


Component* RigidBodyFactory::createComponent(std::map<std::string, std::string> args, Entity* ent)
{
	return new Rigidbody(args);
};


Component* ShootFactory::createComponent(std::map<std::string, std::string> args, Entity* ent)
{
	return new Shoot(args,ent);
};

void setupFactories()
{
	FactoryManager* _fM = FactoryManager::getInstance();

	_fM->addFactory("Transform", new TransformFactory());
	_fM->addFactory("MeshRenderer", new MeshRendererFactory());
	_fM->addFactory("Rigidbody", new RigidBodyFactory());
	_fM->addFactory("Shoot", new ShootFactory());
}