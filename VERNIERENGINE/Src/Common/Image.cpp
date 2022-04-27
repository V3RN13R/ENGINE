#include "Image.h"
#include <SDL.h>
#include <SDL_image.h>
#include "LoadImages.h"
#include "WindowRender.h"

Image::Image(std::map<std::string, std::string> args, Entity* ent) : _texture(args["Id"]), _ent(ent)
{
	_ruta = LoadImages::instance()->getRutas(_texture);
	//_tx = getImage(_texture);
}

void Image::render() {
	if (_tr != nullptr) {
		_dest = build_sdlrect(_tr->getPos(), _tr->getW(), _tr->getH());
	}
}

void Image::start() {

	_tr = static_cast<Transform*>(_ent->getComponent("Transform"));

	_tx = new Texture(LoadImages::instance()->getRenderer(), _ruta);
	assert(_tx != nullptr);
	LoadImages::instance()->addTexture(_tx);
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