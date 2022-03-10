#include "MeshRenderer.h"
#include "Entity.h"
#include "RenderMain.h"
#include <Ogre.h>

using OgrePrefab = Ogre::SceneManager::PrefabType;

MeshRenderer::MeshRenderer(Entity* e) : Component(e), ogreEnt_(nullptr)
{
	mSM_ = RenderMain::getInstance()->getSceneManager();
}


MeshRenderer::~MeshRenderer()
{
	if (node_)
		node_->detachObject(ogreEnt_);
	node_ = nullptr;
	RenderMain::getInstance()->getSceneManager()->destroyEntity(ogreEnt_);
	ogreEnt_ = nullptr;
	//borrar basura creada al meter la mesh?� como el Ogre::Entity quizas no lo s�
}