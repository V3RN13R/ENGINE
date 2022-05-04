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
	VernierEngine::getInstance()->getGSM()->changeScene("menuseleccionpersonajes.lua", "menuseleccionpersonajes");
	std::cout << "Cambiado a menú selección de personajes" << "\n";
}

void CallbacksGame::jugar() {
	VernierEngine::getInstance()->getGSM()->changeScene("prueba2.lua", "prueba2", false);
	std::cout << "Cambiado a pantalla de jugar" << "\n";
}

void CallbacksGame::volver() {
	VernierEngine::getInstance()->getGSM()->popScene();
	std::cout << "Cambiado a pantalla de jugar desde las opciones" << "\n";
}

void CallbacksGame::initCallbacks(){
	_instance->addMethod("menuSeleccion", menuSeleccion);
	_instance->addMethod("jugar", jugar);
	_instance->addMethod("volver", volver);
}

bool CallbacksGame::init() {
	initCallbacks();
	return true;
}