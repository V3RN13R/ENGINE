#include "Image.h"
#include "../UIManager/UIManager.h"
#include "../UIManager/UIImage.h"
//#include "checkML.h"


Image::Image(std::map<std::string, std::string> args) : _overlayName(args["OverlayName"]), _name(args["Name"]), _x(stoi(args["X"])), _y(stoi(args["Y"])), _w(stoi(args["W"])), _h(stoi(args["H"])) {

}

void Image::start() {
	_img = UIManager::getInstance()->addImage(_overlayName, _name);
	_img->setPosition(_x, _y);
	_img->setSize(_w, _h);
	_img->setRenderOrder(UIManager::getInstance()->getNum());
}

void Image::show() {
	_img->show();
	//UIManager::getInstance()->getImage(_name)->show();
}
