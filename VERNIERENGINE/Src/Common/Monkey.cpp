#include "Monkey.h"

void Monkey::receiveEvent(MessageType msg, Entity* e) {
	if (msg == MessageType::W) {
		std::cout << "TECLA W";
	}
}