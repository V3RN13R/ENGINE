#pragma once

#include "Callbacks.h"

class CallbacksGame : public Callbacks {
private:
	static void menuSeleccion();
	static void jugar();
	static void volver();
	CallbacksGame();
public:
	~CallbacksGame() {};
	static void initCallbacks();
	static bool init();
};