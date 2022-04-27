#include "Light.h"
#include "Entity.h"
#include "WindowRender.h"
#include "RenderMain.h"
#include "Transform.h"
#include <OgreLight.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>


Light::Light(std::map<std::string, std::string> args, Entity* ent) : Component(ent), _node(nullptr), _light(nullptr), _firstEnable(true),
_diffuseColor(args["Diffuse"]), _specularColor(args["Specular"]), _direction(args["Direction"])
{
	if ((args["LighType"]) == "POINTLIGHT") _lightType = 0;
	else if ((args["LighType"]) == "DIRECTIONAL_LIGHT") _lightType = 1;
	else if ((args["LighType"]) == "SPOTLIGHT") _lightType = 2; ;

	_distance = stof(args["Distance"]);
	_innerAngle = stof(args["InnerAngle"]);
	_outerAngle = stof(args["OuterAngle"]);
	_isOn = stoi(args["On"]);
}

Light::~Light()
{
	WindowRender::getInstance()->getSceneManager()->destroyLight(_light);
	_light = nullptr;
}

void Light::setAmbientLight(Vector3D light)
{
	WindowRender::getInstance()->setAmbientLight(light.getX(), light.getY(), light.getZ());
}

void Light::onEnable()
{
	if (_firstEnable) {
		_light = WindowRender::getInstance()->createLight((Ogre::LightTypes)_lightType);
		
		_node = entity_->getNode()->createChildSceneNode("_" + entity_->getName()); //entity_->getName()
		_node->attachObject(_light);
		_node->lookAt(RenderMain::toOgre(_direction), Ogre::Node::TransformSpace::TS_WORLD); // toOgrePosition

		_light->setDiffuseColour(_diffuseColor.getX(), _diffuseColor.getY(), _diffuseColor.getZ());
		_light->setSpecularColour(_specularColor.getX(), _specularColor.getY(), _specularColor.getZ());
		_light->setCastShadows(true);
		setDistance(_distance);
		if (_lightType == (int)LightMode::SPOTLIGHT) {
			_light->setSpotlightInnerAngle(Ogre::Radian(Ogre::Degree(_innerAngle)));
			_light->setSpotlightOuterAngle(Ogre::Radian(Ogre::Degree(_innerAngle)));
		}
		_firstEnable = false;
	}
	_light->setVisible(_isOn);
}

void Light::onDisable()
{
	_light->setVisible(false);
}


void Light::setDiffuseColor(Vector3D color)
{
	_diffuseColor = color;
	_light->setDiffuseColour(color.getX(), color.getY(), color.getZ());
}

void Light::setSpecularColor(Vector3D color)
{
	_specularColor = color;
	_light->setSpecularColour(color.getX(), color.getY(), color.getZ());
}

void Light::setDirection(Vector3D orientation, bool global)
{
	_direction = orientation;

	_node->lookAt(RenderMain::toOgre(_direction), global ?  
		Ogre::Node::TransformSpace::TS_WORLD :
		Ogre::Node::TransformSpace::TS_LOCAL);
}

void Light::setType(LightMode type)
{
	_light->setType((Ogre::Light::LightTypes)type);
	if (_lightType == (int)LightMode::SPOTLIGHT) {
		_light->setSpotlightInnerAngle(Ogre::Radian(Ogre::Degree(_innerAngle)));
		_light->setSpotlightOuterAngle(Ogre::Radian(Ogre::Degree(_innerAngle)));
	}
}

void Light::setDistance(float distance)
{
	_distance = distance;
	float linear = 4.5 / distance;
	float quadratic = 75.0 / pow(pow(_distance, 3), 2);

	_light->setAttenuation(pow(_distance, 3), 0.8, linear, quadratic);
}

void Light::setInnerAngle(float angle)
{
	_innerAngle = angle;
	if (_lightType == (int)LightMode::SPOTLIGHT)
		_light->setSpotlightInnerAngle(Ogre::Radian(Ogre::Degree(_innerAngle)));
}

void Light::setOuterAngle(float angle)
{
	_outerAngle = angle;
	if (_lightType == (int)LightMode::SPOTLIGHT)
		_light->setSpotlightOuterAngle(Ogre::Radian(Ogre::Degree(_innerAngle)));
}