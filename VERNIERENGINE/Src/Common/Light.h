#pragma once

#include "Component.h"
#include "Vector3D.h"
#include "Utils.h"
#include <map>

namespace Ogre {
	class Light;
	class SceneNode;
}

enum class LightMode
{
	POINTLIGHT = 0,
	DIRECTIONAL_LIGHT = 1,
	SPOTLIGHT = 2
};

//int SconvertToInt(const std::string& str)
//{
//	if (str == "POINTLIGHT") return 0;
//	else if (str == "DIRECTIONAL_LIGHT") return 1;
//	else if (str == "SPOTLIGHT") return 2;
//};

class Light: public Component {
private:

	Ogre::SceneNode* _node;

	Ogre::Light* _light;

	int _lightType;

	Vector3D _diffuseColor;
	Vector3D _specularColor;

	Vector3D _direction;

	float _distance;

	float _innerAngle;

	float _outerAngle;

	int _isOn = 1; //Funciona como booleano 1 encendido 0 apagado

	bool _firstEnable = true;
	bool _ambientBool = true;
	Vector3D _ambientColor;

public:

	Light(std::map<std::string, std::string> args, Entity* ent);
	~Light();

	static std::string GetName() { return "Light"; }
		

	//virtual bool init(LuaBridge::LuaRef parameterTable = { nullptr }) override;

	virtual void onEnable() override;

	virtual void onDisable() override;

	static void setAmbientLight(Vector3D light);

	void setDiffuseColor(Vector3D color);

	void setSpecularColor(Vector3D color);

	// FUNCIONA COMO UN LOOK AT
	void setDirection(Vector3D direction, bool global = true);

	void setType(LightMode type);

	void setDistance(float power);

	// FUNCIONA SOLO CON SPOTLIGHT
	void setInnerAngle(float angle);

	// FUNCIONA SOLO CON SPOTLIGHT
	void setOuterAngle(float angle);

	float getDistance() { return _distance; }
};