#pragma once

#include "Component.h"
#include "EngineDll.h"
#include <string>
#include <map>

namespace Ogre {
	class Root;
	class SceneManager;
	class SceneNode;
	class Entity;
	class Mesh;
}

enum PrefabType {
	PT_PLANE,
	PT_CUBE,
	PT_SPHERE
};

class V3RN13R_API MeshRenderer : public Component {
private:
	Ogre::SceneNode* _node;
	Ogre::SceneManager* _mSceneManager;
	Ogre::Entity* _ogreEnt;
	std::string _materialName;
	std::string _mesh;
	std::string _entityName;

	bool _firstEnable = true;
	bool _visible = true;
public:
	MeshRenderer(Entity* e = nullptr);
	MeshRenderer(std::map<std::string, std::string> args);
	~MeshRenderer();

	static std::string GetName() { return "MeshRenderer"; }

	virtual bool init() { return false; }

	Ogre::SceneManager* getSceneManager() { return _mSceneManager; }
	Ogre::Entity* getOgreEntity() { return _ogreEnt; }

	Ogre::Mesh* getMesh() const;

	void setVisible(bool visible);
	bool getVisible();
	void setMaterial(std::string materialName);

	virtual void onEnable(); //override
	virtual void onDisable(); //override
	bool start( std::string mesh);
};