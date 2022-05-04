#pragma once
#include "CallbacksGame.h"
#include "Callbacks.h"
#include "GameStateMachine.h"
#include "ENGINE.h"
#include <iostream>
#include <map>

CallbacksGame::CallbacksGame() : Callbacks() {

}

void CallbacksGame::menuSeleccion() {
	VernierEngine::getInstance()->getGSM()->changeScene("menuseleccionpersonajes.lua", "menuseleccionpersonajes", true);
	std::cout << "Cambiado a menú selección de personajes" << "\n";
}

void CallbacksGame::initCallbacks(){
	_instance->addMethod("menuSeleccion", menuSeleccion);
}

bool CallbacksGame::init() {
	initCallbacks();
	return true;
}