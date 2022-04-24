#pragma once
#include <cassert>
#include <functional>
#include <map>
#include <memory>
#include <string>

class CallBacks {

public:
	~CallBacks() {};

	static  CallBacks* init();

	static CallBacks* instance() {
		assert(_instance.get() != nullptr);
		return _instance.get();
	}

	void addMethod(std::string name, void (*func)());

	std::function<void()> getMethod(std::string name);

private:
	std::map<std::string, std::function<void()>> _methods;

	CallBacks();

protected:
	static std::unique_ptr<CallBacks> _instance;

};