#pragma once

#include <string>

class Entity;

class Component
{
public:
// Constructora de las componentes.
	Component(std::string tag);
// Destructora de las componentes.
	virtual ~Component();

// M�todo que otorga una entidad a un componente.
	void setEntity(Entity* e);
// M�todo que devuelve la entidad de la componente.
	Entity* getEntity();

// M�todo que inicializa el componente.
	virtual void start();
	
// M�todo que actualiza los componentes.
	virtual void update();
// M�todo que renderiza los componentes.
	virtual void render();
// M�todo que detecta las colisiones.
	virtual void onCollision(Entity* other);
// M�todo que activa/desactiva el componente.
	void setActiveOnHierarchy(bool active);
// M�todo que activa/desactiva el componente.
	void setEnabled(bool enabled);
// M�todo que devuelve si el componente est� activo.
	const bool isActive() { return (_enabled && _activeOnHierarchy); }
// M�todo que devuelve si el componente est� activo.
	const bool isEnabled() { return _enabled; }
// M�todo que devuelve si el componente est� activo.
	const bool isActiveOnHierarchy() { return _activeOnHierarchy; }

private:
	bool _enabled = true, _activeOnHierarchy = true;
	std::string _tag;
	Entity* _e;

};

