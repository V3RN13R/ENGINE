#pragma once
#include "Component.h"
#include <map>

namespace Ogre {
}

class UIImage;

class Image : public Component {
private:
	std::string _overlayName;
	std::string _name;
	UIImage* _img;
public:
	Image(){}
	~Image(){}

	Image(std::map<std::string, std::string> args);
	
	void start();
	void show();
};