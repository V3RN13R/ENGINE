#include "CallBacks.h"
#include <iostream>
#include <assert.h>

std::unique_ptr<Callbacks> Callbacks::_instance;

Callbacks::Callbacks()
{

}

Callbacks* Callbacks::init()
{
	assert(_instance.get() == nullptr);
	_instance.reset(new Callbacks());
	return _instance.get();
}

void Callbacks::addMethod(std::string name, void(*func)())
{
	_methods.insert({ name, func });
}


std::function<void()> Callbacks::getMethod(std::string name)
{
	auto m = _methods.find(name);
	if (m != _methods.end())
		return (*m).second;
	else
		return []() {
		std::cout << "Este CallBack no existe, comprueba el nombre de la funcion, o si has guardado el metodo\n";
	};

}