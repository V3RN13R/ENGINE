#include "Monkey.h"

void Monkey::receiveEvent(MessageType msg) {
	if (msg == MessageType::W) {
		std::cout << "TECLA W";
	}
}