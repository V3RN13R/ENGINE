#pragma once
#include <string>
class MessageType {
public:
	static const int DEFAULT = 0;
	static const int MOVIMIENTO = 1;
	static const int MOVERW = 2;
	static const int MOVERA = 3;
	static const int MOVERS = 4;
	static const int MOVERD = 5;
	static const int W = 6;
	static const int A = 7;
	static const int S = 8;
	static const int D = 9;
	static const int ESPACIO = 10;
	static const int DISPARO = 11;
	static const int PULSA_Q = 12;
	static const int PULSA_E = 13;
	static const int R = 14;
	static const int T = 15;
	static const int ESCENA1 = 16;
	static const int ESCENA2 = 17;
	static const int CLICKIZ = 18;
	static const int CLICKDE = 19;
	static const int LAST = 20;
	static const int UNO = 21;

};
const float _PI = 3.1416;
const float toRadians = _PI / 180.0;
const float toAngles = 180.0 / _PI;
