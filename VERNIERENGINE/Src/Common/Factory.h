#pragma once
#include "Component.h"
/*
De esta clase heredan cada factoría de cada componente.
Cuando creamos un componente tiene que heredar de Factory e implementar su método createComponent().
*/
class Factory
{
public:
	Factory() {};
	//Este método es el que tienen que sobreescribir las factorías para crear los componentes
	virtual Component* createComponent() = 0;
private:

};