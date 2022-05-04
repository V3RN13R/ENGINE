#include "MeshRenderer.h"
#include "Entity.h"
#include "RenderMain.h"

#include <Ogre.h>
#include <ENGINE.h>
//#include "checkML.h"

using OgrePrefab = Ogre::SceneManager::PrefabType;

MeshRenderer::MeshRenderer(Entity* e) : Component(e), _ogreEnt(nullptr)
{
	_mSceneManager = VernierEngine::getInstance()->getRenderMain()->getSceneManager();
}

MeshRenderer::MeshRenderer(std::map<std::string, std::string> args) : _ogreEnt(nullptr), _mesh(args["Mesh"]), _materialName(args["Material"])
{
	_mSceneManager = VernierEngine::getInstance()->getRenderMain()->getSceneManager();
	start(_mesh);
	setMaterial(_materialName);
}

void MeshRenderer::onEnable()
{
	Component::onEnable();
	_visible = true;

	if (_firstEnable) {
		//node_ = transform->getNode();
		_node = _mSceneManager->getSceneNode(entity_->getName());
		if (_ogreEnt)
			_node->attachObject(_ogreEnt);
		_firstEnable = false;
	}
	if (_ogreEnt)
		_ogreEnt->setVisible(_visible);
}

void MeshRenderer::onDisable()
{
	Component::onDisable();
	_visible = false;
	_ogreEnt->setVisible(false);
}

bool MeshRenderer::start(std::string mesh)
{
	if (mesh == "Sphere")
		_ogreEnt = _mSceneManager->createEntity(Ogre::SceneManager::PrefabType::PT_SPHERE);
	else if (mesh == "Cube")
		_ogreEnt = _mSceneManager->createEntity(Ogre::SceneManager::PrefabType::PT_CUBE);
	else if (mesh == "Plane")
		_ogreEnt = _mSceneManager->createEntity(Ogre::SceneManager::PrefabType::PT_PLANE);
	else
		_ogreEnt = _mSceneManager->createEntity( mesh);
	return true;
}

MeshRenderer::~MeshRenderer()
{
	if (_node)
		_node->detachObject(_ogreEnt);
	_node = nullptr;
	VernierEngine::getInstance()->getRenderMain()->getSceneManager()->destroyEntity(_ogreEnt);
	_ogreEnt = nullptr;
	//borrar basura creada al meter la mesh?� como el Ogre::Entity quizas no lo s�
}

Ogre::Mesh* MeshRenderer::getMesh() const
{
	return _ogreEnt->getMesh().get();
}

void MeshRenderer::setVisible(bool visible)
{
	_visible = visible;
	_ogreEnt->setVisible(_visible);
}

bool MeshRenderer::getVisible()
{
	return _visible;
}

void MeshRenderer::setMaterial(std::string materialName)
{
	_ogreEnt->setMaterialName(materialName);
	_ogreEnt->setCastShadows(true);
}