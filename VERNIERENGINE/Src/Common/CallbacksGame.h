#pragma once

#include "Callbacks.h"

class CallbacksGame : public Callbacks {
private:
	static void menuSeleccion();
	CallbacksGame();
public:
	~CallbacksGame() {};
	static void initCallbacks();
	static bool init();
};