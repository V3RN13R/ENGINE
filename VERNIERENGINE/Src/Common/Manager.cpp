//// This file is part of the course TPV2@UCM - Samir Genaim
//
//#include "Manager.h"
//
//#include <algorithm>
//#include <SDL.h>
//
//Manager::Manager() {
//}
//
//Manager::~Manager() {
//	for (auto e : entities_) {
//		delete e;
//	}
//}
//
//void Manager::refresh() {
//	// remove dead entities from the list of entities
//	entities_.erase( //
//		std::remove_if( //
//			entities_.begin(), //
//			entities_.end(), //
//			[](const Entity* e) { //
//				if (e->isActive()) {
//					return false;
//				}
//				else {
//					delete e;
//					return true;
//				}
//			}), //
//		entities_.end());
//
//	//auto toRemove = std::remove_if( //
//	//		entities_.begin(), //
//	//		entities_.end(), //
//	//		[](const Entity *e) { //
//	//			return !e->isActive();
//	//		});
//
//	//std::for_each(toRemove, entities_.end(), [](const Entity *e) {
//	//	delete e;
//	//});
//
//	//// remove dead entities from the list of entities
//	//entities_.erase(toRemove, entities_.end());
//}
//
//
////bool Manager::keyPressed() {
////	SDL_Event event;
////	while (SDL_PollEvent(&event)) {
////		if (event.type == SDL_QUIT) {
////			return false;
////		}
////		
////
////
////		if (event.type == SDL_KEYDOWN) {
////			//se mira qué tecla se ha preisonado
////			if (event.key.keysym.sym == SDLK_ESCAPE) {
////				return false;
////			}
////
////
////
////			MessageType tecla = MessageType::DEFAULT;
////			if (event.key.keysym.sym == SDLK_w) {
////				tecla = MessageType::W;
////			}
////			else if (event.key.keysym.sym == SDLK_a) {
////				tecla = MessageType::A;
////			}
////			else if (event.key.keysym.sym == SDLK_s) {
////				tecla = MessageType::S;
////			}
////			else if (event.key.keysym.sym == SDLK_d) {
////				tecla = MessageType::D;
////			}
////			else if (event.key.keysym.sym == SDLK_q) {
////				tecla = MessageType::PULSA_Q;
////			}
////			else if (event.key.keysym.sym == SDLK_e) {
////				tecla = MessageType::PULSA_E;
////			}
////
////
////			//si es una tecla válida se envia el mensaje correspondiente
////			if (tecla != MessageType::DEFAULT) {
////				for (Entity* e : Entity::_listeners) {
////					e->receiveEvent(tecla, e);
////				}
////			}
////		}
////	}
////	return true;
////}
//
//void Manager::update() {
//	//keyPressed();
//	auto n = entities_.size();
//	for (auto i = 0u; i < n; i++)
//		entities_[i]->update();
//}
//void Manager::fixedUpdate()
//{
//	auto n = entities_.size();
//	for (auto i = 0u; i < n; i++)
//		entities_[i]->fixedUpdate();
//}
//
//void Manager::render() {
//	auto n = entities_.size();
//	for (auto i = 0u; i < n; i++)
//		entities_[i]->render();
//}