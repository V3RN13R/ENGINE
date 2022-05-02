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
#include "Ground.h"
#include "Pickable.h"
#include "Player.h"
#include "Image.h"
#include "Text.h"
#include "BananaMovement.h"
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
	return new Shoot(args, ent);
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

Component* PickableFactory::createComponent(std::map<std::string, std::string> args, Entity* ent)
{
	return new Pickable(args);
};

Component* GroundFactory::createComponent(std::map<std::string, std::string> args, Entity* ent)
{
	return new Ground(args);
};

Component* Light_Factory::createComponent(std::map<std::string, std::string> args, Entity* ent)
{
	return new Light(args, ent);
};

Component* ImageFactory::createComponent(std::map<std::string, std::string> args, Entity* ent)
{
	return new Image(args);
};

Component* TextFactory::createComponent(std::map<std::string, std::string> args, Entity* ent)
{
	return new Text(args);
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

Component* PlayerFactory::createComponent(std::map<std::string, std::string> args, Entity* ent)
{
	return new Player(args);
};

Component* BananaMovementFactory::createComponent(std::map<std::string, std::string> args, Entity* ent)
{
	return new BananaMovement(args, ent);
}


void setupFactories()
{
	FactoryManager* _fM = VernierEngine::getInstance()->getFactoryMng();

	_fM->addFactory("Transform", new TransformFactory());
	_fM->addFactory("MeshRenderer", new MeshRendererFactory());
	_fM->addFactory("Rigidbody", new RigidBodyFactory());
	_fM->addFactory("Shoot", new ShootFactory());
	_fM->addFactory("Camera", new CameraFactory());
	_fM->addFactory("MovementPlayer", new MovementPlayerFactory());
	_fM->addFactory("Image", new ImageFactory());
	_fM->addFactory("Text", new TextFactory());
	_fM->addFactory("Light", new Light_Factory());
	_fM->addFactory("Health", new HealthFactory());
	_fM->addFactory("Ground", new GroundFactory());
	_fM->addFactory("Pickable", new PickableFactory());
	_fM->addFactory("Player", new PlayerFactory());
	_fM->addFactory("BananaMovement", new BananaMovementFactory());

	//_fM->addFactory("MonkeyStats", new MonkeyStatsFactory());
	//_fM->addFactory("Button1", new Button1Factory());
}


