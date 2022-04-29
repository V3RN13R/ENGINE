#pragma once
#include "Factory.h"
#include <map>
class Component;
class TransformFactory : public Factory
{
public:
	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
};

class MeshRendererFactory : public Factory
{
public:
	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
};

class RigidBodyFactory : public Factory
{
public:
	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
};

class ShootFactory : public Factory
{
public:
	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
};

class CameraFactory : public Factory
{
public:
	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
};

class MovementPlayerFactory : public Factory
{
public:
	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
};


class ImageFactory : public Factory
{
public:
	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
};

class Light_Factory : public Factory
{
public:
	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
};

class MonkeyStatsFactory : public Factory
{
public:
	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
};

//class Button1Factory : public Factory
//{
//	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
//};
void setupFactories();