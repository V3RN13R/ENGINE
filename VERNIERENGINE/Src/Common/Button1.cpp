#pragma once
#include "Button1.h"
#include "InputManager.h"
#include "Entity.h"
#include "Transform.h"
#include "Collisions.h"
#include "Callbacks.h"

Button1::Button1(std::map<std::string, std::string> args, Entity* ent) : _callbackName(args["callback"]) {
    _ent = ent;
}

void Button1::start() {
    _tr = static_cast<Transform*>(_ent->getComponent("Transform"));

    setCallBackFunction(_callbackName);
}

void Button1::update() {
    // Cogemos las coordenadas del rat�n.
    float mX = InputManager::getInstance()->getMousePos().first;
    float mY = InputManager::getInstance()->getMousePos().second;

    // Creamos el Vector3D con las coordenadas del rat�n.
    Vector3D vRaton(mX, mY, 0);
    //std::cout << vRaton.getX() << " " << vRaton.getY() << std::endl;

    // Detectamos el click en la zona.
    if (Collisions::collides(vRaton, 10, 10, _tr->getPos(), 400, 400) && InputManager::getInstance()->getMouseDown()) {
        std::cout << "COLISIONES" << std::endl;
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