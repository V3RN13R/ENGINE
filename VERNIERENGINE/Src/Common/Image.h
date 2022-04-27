// This file is part of the course TPV2@UCM - Samir Genaim

#pragma once

#include "Component.h"
#include "Texture.h"
#include "Entity.h"
#include "Transform.h"
#include <map>

class Image : public Component {
public:
	Image(std::map<std::string, std::string> args, Entity* ent);

	Image(Texture* tex) : _tr(nullptr), _tx(tex), currFrame(0) {
		_src = { 0, 0, tex->width(), tex->height() };
	}

	Image(Texture* tex, SDL_Rect src) : _tr(nullptr), _tx(tex), _src(src) {
		currFrame = src.x * src.w;
	}

	Image(Texture* tex, int rows, int cols, int r, int c) : _tr(nullptr), _tx(tex) {
		auto w = tex->width() / cols;
		auto h = tex->height() / rows;
		_src = { w * c, h * r, w, h };
		currFrame = c * w;
	}


	virtual ~Image() {
	}

	virtual void start();

	void render() override;

	virtual void update();

	void setTexture(Texture* tex) { _tx = tex; }

	Texture* getTexture() { return _tx; }

	SDL_Rect build_sdlrect(Vector3D& pos, float w, float h) {
		return
		{
			static_cast<int>(pos.getX()),
			static_cast<int>(pos.getY()),
			static_cast<int>(w),
			static_cast<int>(h)
		};
	}

private:
	Transform* _tr;
	Texture* _tx;
	SDL_Rect _src;
	SDL_Rect _dest;
	int currFrame;
	Entity* _ent;

	std::string _texture;
	std::string _ruta;
};