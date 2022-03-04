#pragma once
#ifndef _RENDERENGINE_RENDERENGINE_H
#define _RENDERENGINE_RENDERENGINE_H

#include <memory>

class RenderMain {

public:
	RenderMain() {}
	static RenderMain* setUpInstance(const std::string& appName);
	static RenderMain* getInstance();
	bool init(const std::string& appName);
private:
	static std::unique_ptr<RenderMain> _instance;
};
#endif