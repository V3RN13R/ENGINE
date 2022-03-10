#pragma once
#ifndef _RENDERENGINE_RENDERENGINE_H
#define _RENDERENGINE_RENDERENGINE_H

#include <memory>
#include <string>
class WindowRender;
class RenderMain {

public:
	RenderMain(const std::string& appName) { _appName = appName; }
	static RenderMain* setUpInstance(const std::string& appName);
	static RenderMain* getInstance();
	bool init();
	WindowRender* GetWindowRender();
	bool updateWindow();
private:
	std::string _appName;
	static std::unique_ptr<RenderMain> _instance;
	WindowRender* _windowRender;
};
#endif