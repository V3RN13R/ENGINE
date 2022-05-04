#pragma once
#include "Component.h"
#include <map>

class UIText;

class Text : public Component {
private:
	UIText* _uitxt;
	std::string _overlayName;
	std::string _name;
	std::string _text;
	int _x, _y;
	int _rT, _gT, _bT, _rD,_gD,_bD;
	int _size;
	int _order;

public:
	Text(std::map<std::string, std::string> args);
	~Text(){}

	void start();

};