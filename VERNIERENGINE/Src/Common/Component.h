#pragma once

class Entity;

class Component {
public:
	Component(Entity* e = nullptr) :
		entity_(e) {
	}

	virtual ~Component() {
	}

	inline void setEntity(Entity* e) {
		entity_ = e;
	}

	inline Entity* getEntity() {
		return entity_;
	}

	virtual bool init() {
		return false;
	}

	virtual void update() {
	}

	virtual void render() {
	}

protected:
	Entity* entity_;

};

