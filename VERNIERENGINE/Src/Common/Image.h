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
	int _x, _y;
	int _w, _h;
public:
	Image(){}
	~Image(){}

	Image(std::map<std::string, std::string> args);
	
	void start();
	void show();
};