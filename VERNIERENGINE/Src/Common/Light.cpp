//#include "Light.h"
//#include "WindowRender.h"
//#include "Transform.h"
//#include <OgreLight.h>
//#include <OgreSceneNode.h>
//#include <OgreSceneManager.h>
//
//
//Light::Light() :
//	_light(nullptr),
//	_node(nullptr)
//{}
//
//Light::~Light()
//{
//	WindowRender::getInstance()->getSceneManager()->destroyLight(_light);
//	_light = nullptr;
//}
//
//void Light::setAmbientLight(Vector3D light)
//{
//	WindowRender::getInstance()->setAmbientLight(light.x, light.y, light.z);
//}
//
//bool Light::init(LuaBridge::LuaRef parameterTable)
//{
//	LuaRef dColor = NULL, sColor = NULL, dir = NULL;
//	bool correct = true;
//
//	correct &= readVariable<int>(parameterTable, "LightType", (int*)(&_lightType));
//	correct &= readVariable<LuaRef>(parameterTable, "DiffuseColor", &dColor);
//	correct &= readVariable<LuaRef>(parameterTable, "SpecularColor", &sColor);
//	correct &= readVariable<LuaRef>(parameterTable, "Direction", &dir);
//	correct &= readVariable<float>(parameterTable, "Distance", &_distance);
//	correct &= readVariable<float>(parameterTable, "InnerAngle", &_innerAngle);
//	correct &= readVariable<float>(parameterTable, "OuterAngle", &_outerAngle);
//	correct &= readVariable<bool>(parameterTable, "isOn", &_isOn);
//
//	if (!correct) return false;
//
//	_diffuseColor = Vector3D(dColor[1], dColor[2], dColor[3]);
//	_specularColor = Vector3D(sColor[1], sColor[2], sColor[3]);
//	_direction = Vector3D(dir[1], dir[2], dir[3]);
//
//	return true;
//}
//
//void Light::onEnable()
//{
//	if (_firstEnable) {
//		_light = WindowRender::getInstance()->createLigth((Ogre::LightTypes)_lightType);
//		_node = transform->getNode()->createChildSceneNode();
//		_node->attachObject(_light);
//		_node->lookAt(_direction.toOgrePosition(), Ogre::Node::TransformSpace::TS_WORLD);
//
//		_light->setDiffuseColour(_diffuseColor.x, _diffuseColor.y, _diffuseColor.z);
//		_light->setSpecularColour(_specularColor.x, _specularColor.y, _specularColor.z);
//		_light->setCastShadows(true);
//		setDistance(_distance);
//		if (_lightType = SPOTLIGHT) {
//			_light->setSpotlightInnerAngle(Ogre::Radian(Ogre::Degree(_innerAngle)));
//			_light->setSpotlightOuterAngle(Ogre::Radian(Ogre::Degree(_innerAngle)));
//		}
//		_firstEnable = false;
//	}
//	_light->setVisible(_isOn);
//}
//
//void Light::onDisable()
//{
//	_light->setVisible(false);
//}
//
//void Light::setDiffuseColor(Vector3D color)
//{
//	_diffuseColor = color;
//	_light->setDiffuseColour(color.x, color.y, color.z);
//}
//
//void Light::setSpecularColor(Vector3D color)
//{
//	_specularColor = color;
//	_light->setSpecularColour(color.x, color.y, color.z);
//}
//
//void Light::setDirection(Vector3D orientation, bool global)
//{
//	_direction = orientation;
//	_node->lookAt(Vector3D::toOgre(_direction), global ?
//		Ogre::Node::TransformSpace::TS_WORLD :
//		Ogre::Node::TransformSpace::TS_LOCAL);
//}
//
//void Light::setType(LightType type)
//{
//	_light->setType((Ogre::Light::LightTypes)type);
//	if (_lightType = SPOTLIGHT) {
//		_light->setSpotlightInnerAngle(Ogre::Radian(Ogre::Degree(_innerAngle)));
//		_light->setSpotlightOuterAngle(Ogre::Radian(Ogre::Degree(_innerAngle)));
//	}
//}
//
//void Light::setDistance(float distance)
//{
//	_distance = distance;
//	float linear = 4.5 / distance;
//	float quadratic = 75.0 / pow(pow(_distance, 3), 2);
//
//	_light->setAttenuation(pow(_distance, 3), 0.8, linear, quadratic);
//}
//
//void Light::setInnerAngle(float angle)
//{
//	_innerAngle = angle;
//	if (_lightType = SPOTLIGHT)
//		_light->setSpotlightInnerAngle(Ogre::Radian(Ogre::Degree(_innerAngle)));
//}
//
//void Light::setOuterAngle(float angle)
//{
//	_outerAngle = angle;
//	if (_lightType = SPOTLIGHT)
//		_light->setSpotlightOuterAngle(Ogre::Radian(Ogre::Degree(_innerAngle)));
//}