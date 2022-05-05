#pragma once
#include "Button1.h"
#include "InputManager.h"
#include "Entity.h"
#include "Image.h"
#include "Collisions.h"
#include "Callbacks.h"

Button1::Button1(std::map<std::string, std::string> args, Entity* ent) : _callbackName(args["Callback"]) {
    _ent = ent;
}

void Button1::start() {
    _img = static_cast<Image*>(_ent->getComponent("Image"));

    setCallback();
}

void Button1::update() {
    // Cogemos las coordenadas del rat�n.
    float mX = InputManager::getInstance()->getMousePos().first;
    float mY = InputManager::getInstance()->getMousePos().second;

    // Creamos el Vector3D con las coordenadas del rat�n.
    Vector3D vRaton(mX, mY, 0);

    // Detectamos el click en la zona.
    if (Collisions::collides(vRaton, 10, 10, _img->getPos3D(), _img->getW(), _img->getH()) && InputManager::getInstance()->getMouseDown()) {
        if (callback != nullptr)
            callback();
    }
}

void Button1::setCallBackFunction(std::string callBackName)
{
    setCallBackFunction(Callbacks::instance()->getMethod(callBackName));
}

void Button1::setCallBackFunction(std::function<void()> callBack)
{
    //element_->removeAllEvents();
    //element_->subscribeEvent(CEGUI::PushButton::EventClicked, callBack);
}

void Button1::setCallback() {
    callback = Callbacks::instance()->getMethod(_callbackName);
}