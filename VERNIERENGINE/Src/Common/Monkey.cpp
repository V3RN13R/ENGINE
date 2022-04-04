#include "Monkey.h"

void Monkey::receiveEvent(MessageType msg, Entity* e) {
	if (msg == MessageType::W) {
		std::cout << "TECLA W\n";
	}
	if (msg == MessageType::A) {
		std::cout << "TECLA A\n";
	}
	if (msg == MessageType::S) {
		std::cout << "TECLA S\n";
	}
	if (msg == MessageType::D) {
		std::cout << "TECLA D\n";
	}
}