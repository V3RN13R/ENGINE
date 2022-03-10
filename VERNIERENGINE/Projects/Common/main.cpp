#include "../../Src/Common/TEST-Componente1.h"
#include "../../Src/Common/TEST-Componente2.h"
#include "../../Src/Common/Entity.h"
#include "../../Src/Common/Manager.h"


// Prueba para comprobar que la arquitectura EC funciona.

int main() {
	std::unique_ptr<Manager> _mngr;
	_mngr.reset(new Manager());

	auto* prueba1 = _mngr->addEntity();
	prueba1->addComponent<TESTComponente1>();

	auto* prueba2 = _mngr->addEntity();
	prueba2->addComponent<TESTComponente2>();

	while (true)
		_mngr->update();

	return 0;
}