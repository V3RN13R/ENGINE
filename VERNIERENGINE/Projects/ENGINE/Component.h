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

// Método que otorga una entidad a un componente.
	void setEntity(Entity* e);
// Método que devuelve la entidad de la componente.
	Entity* getEntity();

// Método que inicializa el componente.
	virtual void start();
	
// Método que actualiza los componentes.
	virtual void update();
// Método que renderiza los componentes.
	virtual void render();
// Método que detecta las colisiones.
	virtual void onCollision(Entity* other);
// Método que activa/desactiva el componente.
	void setActiveOnHierarchy(bool active);
// Método que activa/desactiva el componente.
	void setEnabled(bool enabled);
// Método que devuelve si el componente está activo.
	const bool isActive() { return (_enabled && _activeOnHierarchy); }
// Método que devuelve si el componente está activo.
	const bool isEnabled() { return _enabled; }
// Método que devuelve si el componente está activo.
	const bool isActiveOnHierarchy() { return _activeOnHierarchy; }

private:
	bool _enabled = true, _activeOnHierarchy = true;
	std::string _tag;
	Entity* _e;

};

