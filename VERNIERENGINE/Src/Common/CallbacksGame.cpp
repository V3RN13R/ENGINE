#pragma once
#include "CallbacksGame.h"
#include "Callbacks.h"
#include "GameStateMachine.h"
#include <map>

CallbacksGame::CallbacksGame() : Callbacks() {

}

void CallbacksGame::menuSeleccion() {
	GameStateMachine::getInstance()->changeScene("menuprincipal.lua", "menuprincipal");
}

void CallbacksGame::initCallbacks(){
	_instance->addMethod("menuSeleccion", menuSeleccion);
}

bool CallbacksGame::init() {
	initCallbacks();
	return true;
}