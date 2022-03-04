// ENGINE.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>
#include "RenderMain.h"
#include "WindowRender.h"
#include <OgreRoot.h>

std::unique_ptr<RenderMain>  RenderMain::_instance;

RenderMain* RenderMain::setUpInstance(const std::string& appName)
{
	assert(_instance.get() == nullptr);
	_instance.reset(new RenderMain());
	return _instance.get();
}

RenderMain* RenderMain::getInstance()
{
	assert(_instance.get() != nullptr);
	return _instance.get();
}

bool RenderMain::init(const std::string& appName)
{
	WindowRender* _windowRender = new WindowRender(appName);
	return true;
}
