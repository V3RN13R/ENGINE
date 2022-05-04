#pragma once
#include "Component.h"
#include <map>
#include "Vector3D.h"

class UIImage;

class Image : public Component {
private:
	std::string _overlayName;
	std::string _name;
	UIImage* _img;
	float _x, _y;
	int _w, _h;
public:
	Image(){}
	~Image(){}

	Image(std::map<std::string, std::string> args);
	
	void start();
	void show();
	Vector3D getPos3D() { return { _x, _y, 0 }; }
	int getW() { return _w; }
	int getH() { return _h; }
};