#pragma once
#include <cassert>
#include <functional>
#include <map>
#include <memory>
#include <string>
#include "EngineDll.h"

class V3RN13R_API Callbacks {

public:
	~Callbacks() {};

	static  Callbacks* init();

	static Callbacks* instance() {
		assert(_instance.get() != nullptr);
		return _instance.get();
	}

	void addMethod(std::string name, void (*func)());

	std::function<void()> getMethod(std::string name);

	void menuSeleccion();

protected:
	Callbacks();
	static std::unique_ptr<Callbacks> _instance;
	std::map<std::string, std::function<void()>> _methods;
};