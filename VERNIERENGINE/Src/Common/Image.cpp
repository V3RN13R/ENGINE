#include "Image.h"
#include <SDL.h>
#include <SDL_image.h>

Image::Image(std::map<std::string, std::string> args) : _texture(args["texture"])
{
	//_tx = getImage(_texture);
}

void Image::render() {
	if (_tr != nullptr) {
		_dest = build_sdlrect(_tr->getPos(), _tr->getW(), _tr->getH());
	}
}

void Image::update() {
	_tx->render(_dest);
}

//
//void Image::shiny() {
//	if (_src.x < 3 * _src.w) //el 3 está cableado por código
//		_src.x += _src.w;
//}
//
//void Image::dark() {
//	_src.x = currFrame;
//}