#include "Image.h"
#include "../UIManager/UIManager.h"
#include "../UIManager/UIImage.h"

Image::Image(std::map<std::string, std::string> args) : _overlayName(args["OverlayName"]), _name(args["Name"]) {

}

void Image::start() {
	_img = UIManager::getInstance()->addImage(_overlayName, _name);
}

void Image::show() {
	_img->show();
	//UIManager::getInstance()->getImage(_name)->show();
}