#pragma once
#include "ExampleDll.h"
#include "Component.h"
#include "Factory.h"

class Engine;
class VernierEngine;

class EXAMPLE_API Example:public Component
{
public:
	Example(std::map<std::string, std::string> args);
	void update() override;
	void fixedUpdate() override {};
	void lateUpdate() override {};
	static VernierEngine* _instanceMotor;
};

class EXAMPLE_API ExportFactories:public Factory{
	Component *createComponent(std::map<std::string, std::string> args, Entity* ent = nullptr) override;
};