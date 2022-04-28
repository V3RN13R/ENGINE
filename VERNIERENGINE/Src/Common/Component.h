#pragma once
#include <vector>


class Entity;
enum class MessageType;

class Component {
public:
	Component(Entity* e = nullptr) :
		entity_(e) {
	}

	virtual ~Component() {}

	virtual void start() {}

	inline void setEntity(Entity* e) {
		entity_ = e;
	}

	inline Entity* getEntity() {
		return entity_;
	}

	inline bool getEnable() {
		return _enable;
	}

	virtual bool init() {
		return false;
	}

	inline bool isEnable() { return _enable; }

	inline void setEnable(bool set) {
		_enable = set;

		if (set)
			onEnable();
		else
			onDisable();
	}

	virtual void preUpdate() {}
	virtual void update() {}	
	virtual void lateUpdate() {}
	virtual void fixedUpdate() {}
	virtual void render() {}
	virtual void onEnable() { _enable = true; }
	virtual void onDisable() { _enable = false; }
	virtual void receiveEvent(MessageType msg, Entity* e) {}
	virtual void onCollisionEnter(Entity*, Vector3D, Vector3D);
	virtual void onCollisionStay(Entity*, Vector3D);

protected:
	Entity* entity_;
	bool _enable = true;
};