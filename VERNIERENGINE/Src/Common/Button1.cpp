#pragma once
#include "Button1.h"
#include "InputManager.h"

void Button1::update() {
	int mX = InputManager::instance()->getMousePos().first;
	int mY = InputManager::instance()->getMousePos().second;
}