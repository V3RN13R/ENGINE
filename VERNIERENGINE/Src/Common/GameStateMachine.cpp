#include "GameStateMachine.h"
#include "Scene.h"
#include "SDL.h"


void GameStateMachine::initScene(const std::string& sceneFile, const std::string& scene) {
	_sceneStack.push((new Scene(sceneFile, scene, instance())));
	_sceneStack.top()->start();
	_sceneStack.top()->onEnable();
}

void GameStateMachine::clearScenes() {
	while (!_sceneStack.empty()) {
		delete _sceneStack.top();
		_sceneStack.pop();
	}
}

void GameStateMachine::popScene() {
	_pop = true;
}

void GameStateMachine::changeScene(std::string file, std::string name, bool push) {
	if (_sceneStack.empty()) {
		Scene* scene = new Scene(file, name, instance());
		_sceneStack.push(scene);
		scene->start();
	}
	else {
		if (!push) {
			_load = true;
		}
		else {
			_push = true;
		}
		_name = name;
		_file = file;
	}
}

void GameStateMachine::fixedUpdate() {
	if (!_sceneStack.empty())
		_sceneStack.top()->fixedUpdate();
}

void GameStateMachine::update() {
	if (!_sceneStack.empty())
		_sceneStack.top()->update();
}

Scene* GameStateMachine::getScene() { return _sceneStack.top(); }

bool GameStateMachine::lastUpdate()
{
	if (!_sceneStack.empty()) {
		//_sceneStack.top()->lastUpdate();
		if (_pop) {
			delete _sceneStack.top();
			_sceneStack.pop();
			if (_sceneStack.empty())
				return false;
			getScene()->setSceneActive(true);
			_pop = false;
		}
		else if(_load || _push) {
			if (_load)
				clearScenes();
			Scene* scene = new Scene(_file, _name, instance());
			_sceneStack.push(scene);
			scene->start();
			_load = false;
		}
		return true;
	}
	return false;
}
//bool GameStateMachine::keyPressed() {
	//SDL_Event event;
	//while (SDL_PollEvent(&event)) {
	//	if (event.type == SDL_QUIT) {
	//		return false;
	//	}

	//	if (event.type == SDL_KEYDOWN) {
	//		//se mira qué tecla se ha preisonado
	//		if (event.key.keysym.sym == SDLK_ESCAPE) {
	//			return false;
	//		}

	//		MessageType tecla = MessageType::DEFAULT;
	//		if (event.key.keysym.sym == SDLK_1) {
	//			tecla = MessageType::ESCENA1;
	//		}
	//		else if (event.key.keysym.sym == SDLK_2) {
	//			tecla = MessageType::ESCENA2;
	//		}

	//		std::pair<Sint32, Sint32> mousePos_;
	//		if (event.type == SDL_MOUSEMOTION) {
	//			mousePos_.first = event.motion.x;
	//			mousePos_.second = event.motion.y;
	//			std::cout << mousePos_.first << " " << mousePos_.second << std::endl;
	//		}

	//		//si es una tecla válida se envia el mensaje correspondiente
	//		if (tecla != MessageType::DEFAULT) {
	//			for (Entity* e : Entity::_listeners) {
	//				e->receiveEvent(tecla, e);
	//			}
	//		}
	//	}
	//}
	//return true;
//}