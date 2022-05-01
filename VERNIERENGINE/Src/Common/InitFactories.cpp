#pragma once
#include "InitFactories.h"
#include "FactoryManager.h"
#include "MeshRenderer.h"
#include "Transform.h"
#include "RigidBody.h"
#include "Shoot.h"
#include "Camera.h"
#include "Light.h"
#include "MovementPlayer.h"
#include "MonkeyStats.h"
#include "Health.h"
#include <ENGINE.h>

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

//Component* ImageFactory::createComponent(std::map<std::string, std::string> args, Entity* ent)
//{
//	return new Image(args, ent);
//};

Component* MovementPlayerFactory::createComponent(std::map<std::string, std::string> args, Entity* ent)
{
	return new MovementPlayer(args);
};

Component* Light_Factory::createComponent(std::map<std::string, std::string> args, Entity* ent)
{
	return new Light(args, ent);
};

//Component* MonkeyStatsFactory::createComponent(std::map<std::string, std::string> args, Entity* ent)
//{
//	return new MonkeyStats(args);
//};

//Component* Button1Factory::createComponent(std::map<std::string, std::string> args, Entity* ent) {
//	return new Button1(args, ent);
//}

Component* HealthFactory::createComponent(std::map<std::string, std::string> args, Entity* ent)
{
	return new Health(args);
};


void setupFactories()
{
	FactoryManager* _fM = VernierEngine::getInstance()->getFactoryMng();

	_fM->addFactory("Transform", new TransformFactory());
	_fM->addFactory("MeshRenderer", new MeshRendererFactory());
	_fM->addFactory("Rigidbody", new RigidBodyFactory());
	_fM->addFactory("Shoot", new ShootFactory());
	_fM->addFactory("Camera", new CameraFactory());
	_fM->addFactory("MovementPlayer", new MovementPlayerFactory());
	//_fM->addFactory("Image", new ImageFactory());
	_fM->addFactory("Light", new Light_Factory());
	_fM->addFactory("Health", new HealthFactory());

	//_fM->addFactory("MonkeyStats", new MonkeyStatsFactory());
	//_fM->addFactory("Button1", new Button1Factory());
}