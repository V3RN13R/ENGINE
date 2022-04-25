#pragma once
#include "InitFactories.h"
#include "FactoryManager.h"
#include "MeshRenderer.h"
#include "Transform.h"
#include "RigidBody.h"
#include "Shoot.h"
#include "Button1.h"
#include "Camera.h"
#include "Image.h"
#include "MovementPlayer.h"

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

Component* CameraFactory::createComponent(std::map<std::string, std::string> args, Entity* ent)
{
	return new Camera(args, ent);
}

Component* ImageFactory::createComponent(std::map<std::string, std::string> args, Entity* ent)
{
	return new Image(args);
};
Component* MovementPlayerFactory::createComponent(std::map<std::string, std::string> args, Entity* ent)
{
	return new MovementPlayer(args);
};

//Component* Button1Factory::createComponent(std::map<std::string, std::string> args, Entity* ent) {
//	return new Button1(args, ent);
//}


void setupFactories()
{
	FactoryManager* _fM = FactoryManager::getInstance();

	_fM->addFactory("Transform", new TransformFactory());
	_fM->addFactory("MeshRenderer", new MeshRendererFactory());
	_fM->addFactory("Rigidbody", new RigidBodyFactory());
	_fM->addFactory("Shoot", new ShootFactory());
	_fM->addFactory("Camera", new CameraFactory());
	_fM->addFactory("MovementPlayer", new MovementPlayerFactory());

	_fM->addFactory("Image", new ImageFactory());
	//_fM->addFactory("Button1", new Button1Factory());
}