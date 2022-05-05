#pragma once
#include "InitFactories.h"
#include "FactoryManager.h"
#include "MeshRenderer.h"
#include "Transform.h"
#include "RigidBody.h"
#include "Camera.h"
#include "Light.h"
#include "Image.h"
#include "Text.h"
#include "SoundComponent.h"
#include "Button1.h"
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

Component* CameraFactory::createComponent(std::map<std::string, std::string> args, Entity* ent)
{
	return new Camera(args, ent);
}

Component* SoundComponentFactory::createComponent(std::map<std::string, std::string> args, Entity* ent)
{
	return new SoundComponent(args, ent);
}

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

Component* Button1Factory::createComponent(std::map<std::string, std::string> args, Entity* ent)
{
	return new Button1(args, ent);
};

void setupFactories()
{
	FactoryManager* _fM = VernierEngine::getInstance()->getFactoryMng();

	_fM->addFactory("Transform", new TransformFactory());
	_fM->addFactory("MeshRenderer", new MeshRendererFactory());
	_fM->addFactory("Rigidbody", new RigidBodyFactory());
	_fM->addFactory("Camera", new CameraFactory());
	_fM->addFactory("Image", new ImageFactory());
	_fM->addFactory("Text", new TextFactory());
	_fM->addFactory("Light", new Light_Factory());
	_fM->addFactory("SoundComponent", new SoundComponentFactory());
	_fM->addFactory("Button1", new Button1Factory());
}


