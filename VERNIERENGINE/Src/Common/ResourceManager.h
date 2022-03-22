#pragma once

#include "WindowRender.h"

class ResourceManager
{
private:
	static std::unique_ptr<ResourceManager> _instance;
	Ogre::FileSystemLayer* _FSLayer;

	void loadResources();
	//bool initRTShaderSystem();
	//void wipeRTShaderSystem();

public:
	ResourceManager(std::string assetsPath);
	~ResourceManager();

	static bool init(std::string assetsPath);
	static ResourceManager* instance();

	void setUp();
};