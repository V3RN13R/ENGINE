#pragma once

#include "Callbacks.h"

class CallbacksGame : public Callbacks {
private:
	static void menuSeleccion();
	// Dependiendo del mono que escojas.
	static void jugar1();
	static void jugar2();
	static void jugar3();
	static void volver();
	CallbacksGame();
public:
	~CallbacksGame() {};
	static void initCallbacks();
	static bool init();
};