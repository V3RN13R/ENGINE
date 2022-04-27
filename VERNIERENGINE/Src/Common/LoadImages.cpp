
#include "LoadImages.h"
#include "LuaManager.h"
#include "Texture.h"
#include "WindowRender.h"
#include "SDL_render.h"
#include <iostream>

//file = prueba2.lua
//name = prueba2

void LoadImages::cargaImagen(const std::string& file, const std::string& name)
{
    lua_State* _state = nullptr;
    try {
        _state = readFileLua(file);
        std::cout << "Archivo " << file << " abierto con �xito\n";
    }
    catch (std::string& error) {
        std::cout << "ERROR al leer el archivo " << file << "\n";
        std::cout << error << '\n';
        return;
    }
    if (_state == nullptr) {
        std::cout << "ERROR al leer el archivo " << file << "\n";
        return;
    }

    LuaRef _refScene = NULL;
    try {
        _refScene = readElementFromFile(_state, name);
    }
    catch (...) {
        std::cout << "ERROR al cargar la escena del archivo " << file << "\n";
        return;
    }

    //sacamos el vector de entidades y las creamos
    enableExceptions(_refScene);

    LuaRef _images = NULL;
    try {
        //leemos el vector que contiene las entidades
        _images = _refScene.rawget("images");
    }
    catch (...) {
        std::cout << "ERROR al cargar la lista de imagenes" << file << "\n";
        return;
    }

    //SDL_Renderer* _renderer = WindowRender::getInstance()->getRenderer();
    for (int i = 1; i <= _images.length(); i++) {
        std::string _img = _images[i];
        LuaRef _imageInfo = readElementFromFile(_state, _img);

        LuaRef _name = _imageInfo.rawget("Name");
        if (_name.isNil()) { std::cout << "ERROR: No se ha podido leer el name de la Imagen\n"; }

        std::cout << _img << "\n";
        std::cout << _name << "\n";
        _imagenes.insert({ _img, _name });
    }
    std::cout << "Listo.\n\n-------------------------\n\n";
}

std::string LoadImages::getRutas(std::string ruta) {
    auto it = _imagenes.find(ruta);
    return (*it).second;
}

void LoadImages::init() {
    _renderer = SDL_CreateRenderer(WindowRender::getInstance()->getSDLWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void LoadImages::renderTexturas() {
    for (int i = 0; i < _texturas.size(); i++) _texturas[i]->render(-100, 100);
    SDL_RenderPresent(_renderer);
}