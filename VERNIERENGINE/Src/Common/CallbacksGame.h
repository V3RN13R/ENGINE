#pragma once

#include "Callbacks.h"

class CallbacksGame {

private:
	static std::unique_ptr<CallbacksGame> instance_;
	void initCallbacks();
	static void toScene2();
public:
	CallbacksGame() {};
	~CallbacksGame() {};
	static bool init();
	static CallbacksGame* instance();
};