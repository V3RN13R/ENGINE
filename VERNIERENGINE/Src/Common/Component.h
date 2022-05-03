#pragma once
#include <vector>
#include "Vector3D.h"

class Entity;

class Component {
public:
	Component(Entity* e = nullptr) : entity_(e) {}

	virtual ~Component() {}

	virtual void start() {}

	inline void setEntity(Entity* e) {entity_ = e;}

	inline Entity* getEntity() {return entity_;}

	inline bool getEnable() {return _enable;}

	virtual bool init() {return false;}

	inline bool isEnable() { return _enable; }

	inline void setEnable(bool set) {
		_enable = set;

		if (set)
			onEnable();
		else{
			onDisable();
		}
	}

	virtual void preUpdate() {}
	virtual void update() {}	
	virtual void lateUpdate() {}
	virtual void fixedUpdate() {}
	virtual void render() {}
	virtual void onEnable() { _enable = true; }
	virtual void onDisable() { _enable = false; }
	virtual void receiveEvent(int msg, Entity* e) {}

	virtual void onCollisionEnter(Entity* other, Vector3D point, Vector3D normal) {};
	virtual void onCollisionStay(Entity* ohter, Vector3D point) {};
	virtual void onCollisionExit(Entity* ohter, Vector3D point) {};
	
	virtual void onTriggerEnter(Entity* other, Vector3D point) {};
	virtual void onTriggerStay(Entity* ohter, Vector3D point) {};
	virtual void onTriggerExit(Entity* ohter, Vector3D point) {};

protected:
	Entity* entity_;
	bool _enable = true;
};