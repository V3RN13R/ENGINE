#include "../../Src/Common/TEST-Componente1.h"
#include "../../Src/Common/TEST-Componente2.h"
#include "../../Src/Common/Entity.h"
#include "../../Src/Common/Manager.h"


// Prueba para comprobar que la arquitectura EC funciona.

int main() {
	std::unique_ptr<Manager> mngr_;
	mngr_.reset(new Manager());

	auto* prueba1 = mngr_->addEntity();
	prueba1->addComponent<TESTComponente1>();

	auto* prueba2 = mngr_->addEntity();
	prueba2->addComponent<TESTComponente2>();

	while (true)
		mngr_->update();

	return 0;
}