#pragma once
#include "Component.h"
//#include "LuaBridge.h"
#include "Vector3D.h"

namespace Ogre {
	class Light;
	class SceneNode;
}

enum LightType
{
	POINTLIGHT = 0,
	DIRECTIONAL_LIGHT = 1,
	SPOTLIGHT = 2
};


class Light: public Component {
private:

	Ogre::SceneNode* _node;

	Ogre::Light* _light;

	LightType _lightType;

	Vector3D _diffuseColor;
	Vector3D _specularColor;

	Vector3D _direction;

	float _distance;

	float _innerAngle;

	float _outerAngle;

	bool _isOn = true;

	bool _firstEnable = true;

public:

	Light();
	~Light();

	static std::string GetName() { return "Light"; }

	
	virtual bool init() override;

	//virtual bool init(LuaBridge::LuaRef parameterTable = { nullptr }) override;

	//virtual void onEnable() override;

	//virtual void onDisable() override;

	static void setAmbientLight(Vector3D light);

	void setDiffuseColor(Vector3D color);

	void setSpecularColor(Vector3D color);

	// FUNCIONA COMO UN LOOK AT
	void setDirection(Vector3D direction, bool global = true);

	void setType(LightType type);

	void setDistance(float power);

	// FUNCIONA SOLO CON SPOTLIGHT
	void setInnerAngle(float angle);

	// FUNCIONA SOLO CON SPOTLIGHT
	void setOuterAngle(float angle);

	float getDistance() { return _distance; }
};