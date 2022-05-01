#include "Example.h"
#include <iostream>
#include "InputManager.h"
#include "FactoryManager.h"
#include "Engine.h"

VernierEngine* _instanceMotor = nullptr;

Example::Example()
{
	std::cout << "Constructor de una clase desde dll\n";
}

void Example::update()
{
	std::cout << "jaja example\n";
	if (VernierEngine::getInstance()->getInputMng()->getKeyDown(SDL_SCANCODE_G)) {

		std::cout << "G\n\n\n";
	}
}

extern "C" {
	EXAMPLE_API void example() {
		std::cout << "\n\n\nMetodo desde una dll\n\n\n";

		_instanceMotor->setupInstance("WILDLESS", "prueba2.lua", "prueba2");

		_instanceMotor->getFactoryMng()->addFactory("Example", new ExportFactories());
			
		//delete _instanceMotor;
	}
}

Component* ExportFactories::createComponent(std::map<std::string, std::string> args, Entity* ent)
{
	return new Example();
}
