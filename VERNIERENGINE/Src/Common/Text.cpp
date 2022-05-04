#include "Text.h"
#include "UIManager.h"
#include "UIText.h"

//std::string overlayName, std::string fontName, int fontSize, int order, std::string text, int r, int g, int b, int x, int y

Text::Text(std::map<std::string, std::string> args) : 
	_overlayName(args["OverlayName"]), _name(args["Name"]), _x(stoi(args["X"])), _y(stoi(args["Y"])),
	_size(stoi(args["FontSize"])), _order(stoi(args["Order"])), _text(args["Text"]), _rT(stoi(args["RT"])), _gT(stoi(args["GT"])), _bT(stoi(args["BT"])),
	_rD(stoi(args["RD"])), _gD(stoi(args["GD"])), _bD(stoi(args["BD"])) {
	_uitxt = UIManager::getInstance()->createText(_overlayName, _name, _size, _order, _text, _rT, _gT, _bT, _rD, _gD, _bD, _x, _y);
	_begin = stoi(args["Begin"]) == 0 ? false : true;
}

void Text::start() {
	if (_begin) {
		showText();
	}
	//_uitxt->setFont("fuentes/Gemstone");
	//_uitxt->setRenderOrder(5);
}
void Text::showText() {
	UIManager::getInstance()->addText(_uitxt);
	_uitxt->setPosition(_x, _y);
	_uitxt->setSize(_size, _size);
	_uitxt->show();
}
void Text::hideText() {
	_uitxt->hide();
}
void Text::changeText(std::string txt) {
	_uitxt->setText(txt);
}