
#include "LoadImage.h"
#include "LuaManager.h"
#include "Texture.h"
#include "WindowRender.h"
#include <iostream>

//file = prueba2.lua
//name = prueba2

void LoadImage::cargaImagen(const std::string& file, const std::string& name)
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
        //LuaRef _xPos = _imageInfo.rawget("xPos");
        //LuaRef _yPos = _imageInfo.rawget("yPos");
        //LuaRef _w = _imageInfo.rawget("width");
        //LuaRef _h = _imageInfo.rawget("height");
        //_imagenes.emplace(_name, new Texture(_renderer, _name));
        std::cout << _name << "\n";
    }
    std::cout << "Listo.\n\n-------------------------\n\n";
}