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

void CallbacksGame::jugar1() {
	VernierEngine::getInstance()->getGSM()->changeScene("jugar1.lua", "jugar1", false);
	std::cout << "Cambiado a pantalla de jugar" << "\n";
}
void CallbacksGame::jugar2() {
	VernierEngine::getInstance()->getGSM()->changeScene("jugar2.lua", "jugar2", false);
	std::cout << "Cambiado a pantalla de jugar" << "\n";
}
void CallbacksGame::jugar3() {
	VernierEngine::getInstance()->getGSM()->changeScene("jugar3.lua", "jugar3", false);
	std::cout << "Cambiado a pantalla de jugar" << "\n";
}

void CallbacksGame::volver() {
	VernierEngine::getInstance()->getGSM()->popScene();
	std::cout << "Cambiado a pantalla de jugar desde las opciones" << "\n";
}

void CallbacksGame::initCallbacks(){
	_instance->addMethod("menuSeleccion", menuSeleccion);
	_instance->addMethod("jugar1", jugar1);
	_instance->addMethod("jugar2", jugar2);
	_instance->addMethod("jugar3", jugar3);
	_instance->addMethod("volver", volver);
}

bool CallbacksGame::init() {
	initCallbacks();
	return true;
}