#pragma once 
#include "Singleton.h"
#include <map>
#include <string>

class Texture;

class LoadImage : public Singleton<LoadImage> {
	friend Singleton<LoadImage>;

private:
	std::map<std::string, Texture*> _imagenes;
	LoadImage() {};

public:
	~LoadImage() {};

	void cargaImagen(const std::string& file, const std::string& name);

	LoadImage& ih() {
		return *LoadImage::instance();
	}
};