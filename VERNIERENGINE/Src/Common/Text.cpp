#include "Text.h"
#include "UIManager.h"
#include "UIText.h"

//std::string overlayName, std::string fontName, int fontSize, int order, std::string text, int r, int g, int b, int x, int y

Text::Text(std::map<std::string, std::string> args) : 
	_overlayName(args["OverlayName"]), _name(args["Name"]), _x(stoi(args["X"])), _y(stoi(args["Y"])),
	_size(stoi(args["FontSize"])), _order(stoi(args["Order"])), _text(args["Text"]), _r(stoi(args["R"])), _g(stoi(args["G"])), _b(stoi(args["B"])) {

}

void Text::start() {
	_uitxt = UIManager::getInstance()->addText(_overlayName, _name, _size, _order, _text, _r, _g, _b, _x, _y);
	_uitxt->setPosition(_x, _y);
	_uitxt->setSize(_size, _size);
	//_uitxt->setFont("fuentes/Gemstone");
	//_uitxt->setRenderOrder(5);
}