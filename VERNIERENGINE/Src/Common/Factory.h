#pragma once
#include "Component.h"
/*
De esta clase heredan cada factor�a de cada componente.
Cuando creamos un componente tiene que heredar de Factory e implementar su m�todo createComponent().
*/
class Factory
{
public:
	Factory() {};
	//Este m�todo es el que tienen que sobreescribir las factor�as para crear los componentes
	virtual Component* createComponent() = 0;
private:

};