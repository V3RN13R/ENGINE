#pragma once
#include "ExampleDll.h"
#include "Component.h"
#include "Factory.h"
class EXAMPLE_API Example:public Component
{
public:
	Example();
	void update() override;
};

class EXAMPLE_API ExportFactories:public Factory{
	Component *createComponent(std::map<std::string, std::string> args, Entity* ent = nullptr) override;
};