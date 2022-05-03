#pragma once
#include "Factory.h"
#include <map>
class Component;
class TransformFactory : public Factory
{
private:
	Component* _c;
public:
	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
	//virtual ~TransformFactory() { if (_c != nullptr) delete _c; };
};

class MeshRendererFactory : public Factory
{
private:
	Component* _c;
public:
	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
	//virtual ~MeshRendererFactory() { if(_c != nullptr) delete _c; };
};

class RigidBodyFactory : public Factory
{
private:
	Component* _c;
public:
	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
	//virtual ~RigidBodyFactory() { if (_c != nullptr) delete _c; };
};

class ShootFactory : public Factory
{
private:
	Component* _c;
public:
	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
	//virtual ~ShootFactory() { if (_c != nullptr) delete _c; };
};

class CameraFactory : public Factory
{
private:
	Component* _c;
public:
	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
	//virtual ~CameraFactory() { if (_c != nullptr)delete _c; };
};

class MovementPlayerFactory : public Factory
{
private:
	Component* _c;
public:
	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
	//virtual ~MovementPlayerFactory() { if (_c != nullptr) delete _c; };
};

class GroundFactory : public Factory
{
private:
	Component* _c;
public:
	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
	//virtual ~GroundFactory() { if (_c != nullptr) delete _c; };
};

class PickableFactory : public Factory
{
private:
	Component* _c;
public:
	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
	//virtual ~PickableFactory() { if (_c != nullptr) delete _c; };
};


class PlayerFactory : public Factory
{
private:
	Component* _c;
public:
	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
	//virtual ~PlayerFactory() { if (_c != nullptr) delete _c; };
};

class ImageFactory : public Factory
{
private:
	Component* _c;
public:
	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
	//virtual ~ImageFactory() { if (_c != nullptr) delete _c; };
};





//class ImageFactory : public Factory
//{
//public:
//	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
//};

class Light_Factory : public Factory
{
private:
	Component* _c;
public:
	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
	//virtual ~Light_Factory() { if (_c != nullptr) delete _c; };
};

//class MonkeyStatsFactory : public Factory
//{
//public:
//	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
//};

class HealthFactory : public Factory
{
private:
	Component* _c;
public:
	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
	//virtual ~HealthFactory() { if (_c != nullptr) delete _c; };
};

class TextFactory : public Factory
{
private:
	Component* _c;
public:
	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
	//virtual ~TextFactory() { if (_c != nullptr)delete _c; };
};

class BananaMovementFactory : public Factory
{
private:
	Component* _c;
public:
	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
	//virtual ~BananaMovementFactory() { if (_c != nullptr) delete _c; };
};
class SoundComponentFactory : public Factory
{
public:
	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
};

class DestroyableFactory : public Factory
{
public:
	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
};

//class Button1Factory : public Factory
//{
//	Component* createComponent(std::map<std::string, std::string> args, Entity* ent) override;
//};
void setupFactories();