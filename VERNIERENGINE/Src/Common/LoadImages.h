#pragma once 
#include "Singleton.h"
#include <map>
#include <unordered_map>
#include <string>
#include <vector>

class Texture;
class SDL_Renderer;

class LoadImages : public Singleton<LoadImages> {
	friend Singleton<LoadImages>;

private:
	std::unordered_map<std::string, std::string> _imagenes;
	std::vector<Texture*> _texturas;
	LoadImages() {};

public:
	~LoadImages() {};

	void init();
	void cargaImagen(const std::string& file, const std::string& name);

	std::string getRutas(std::string id);

	SDL_Renderer* _renderer;

	SDL_Renderer* getRenderer() { return _renderer; }

	void addTexture(Texture* tex) { _texturas.push_back(tex); }

	void renderTexturas();

	LoadImages& ih() {
		return *LoadImages::instance();
	}
};