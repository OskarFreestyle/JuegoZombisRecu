#include "Jugador.h"
#include <iostream>
#include "Transform.h"
#include "Entidad.h"
#include "InputManager.h"
#include "OgreVector3.h"
#include "FMODAudioManager.h"
#include "RigidBody.h"
#include "GameManager.h"
#include <time.h>

// Tiempo para que te pueda volver a pegar un zombie
const clock_t TIME_TO_ANOTHER_ZOMBIE_CONTACT = 2000;
const clock_t REPRODUCT_SOUND = 700;

Jugador::Jugador() : 
	transform_(nullptr), speed_(), v()
{
}

bool Jugador::init(const std::map<std::string, std::string>& mapa) {
	if (mapa.find("speed") == mapa.end())
		return false;

	transform_ = entity_->getComponent<Transform>();

	std::string s = mapa.at("speed");
	speed_ = stof(s);

	return true;
};

void Jugador::update() {

	Vectola3D aux = entity_->getComponent<Transform>()->getPosition();
	//std::cout << "PLAYER POS: " << aux.getX() << ", " << aux.getY() << ", " << aux.getZ() << ")\n";

	if (active_) {
		v.setY(0);
		//ih().refresh();
		// Arriba - Abajo
		if (ih().isKeyDown(SDL_SCANCODE_W)) {
			v.setZ(-1);
			//Singleton<FMODAudioManager>::instance()->togglePause(4);
			if (clock() > lastSound + REPRODUCT_SOUND) {
				lastSound = clock();
				Singleton<FMODAudioManager>::instance()->playMusic(4, false);
			}
		}
		else if (ih().isKeyDown(SDL_SCANCODE_S)) {
			v.setZ(1);
			//Singleton<FMODAudioManager>::instance()->togglePause(4);
			if (clock() > lastSound + REPRODUCT_SOUND) {
				lastSound = clock();
				Singleton<FMODAudioManager>::instance()->playMusic(4, false);
			}
		}
		else if (ih().isKeyUp(SDL_SCANCODE_W) || ih().isKeyUp(SDL_SCANCODE_S)) {
			v.setZ(0);
		}

		// Izquierda - Derecha
		if (ih().isKeyDown(SDL_SCANCODE_A)) {
			v.setX(-1);
			//Singleton<FMODAudioManager>::instance()->togglePause(4);
			if (clock() > lastSound + REPRODUCT_SOUND) {
				lastSound = clock();
				Singleton<FMODAudioManager>::instance()->playMusic(4, false);
			}
		}
		else if (ih().isKeyDown(SDL_SCANCODE_D)) {
			v.setX(1);
			//Singleton<FMODAudioManager>::instance()->togglePause(4);
			if (clock() > lastSound + REPRODUCT_SOUND) {
				lastSound = clock();
				Singleton<FMODAudioManager>::instance()->playMusic(4, false);
			}
		}
		else if (ih().isKeyUp(SDL_SCANCODE_A) || ih().isKeyUp(SDL_SCANCODE_D)) {
			v.setX(0);

		}
		//Singleton<FMODAudioManager>::instance()->togglePause(4);

		Vectola3D mov = v.normalize() * speed_;

		// CINEMATIC
		//entity_->getComponent<Transform>()->setPosition(entity_->getComponent<Transform>()->getPosition() + mov);
		// PHYSICS
		entity_->getComponent<RigidBody>()->setVelocity(physx::PxVec3(mov.getX(), mov.getY(), mov.getZ()));

		
	}
}

void Jugador::onCollisionStart(Entidad* other)
{
	if (other->getName() == "Zombie" && clock() > lastZombieContact + TIME_TO_ANOTHER_ZOMBIE_CONTACT) {
		// Pierde una vida
		GameManager::GetInstance()->removeLives(1);

		// Pone un tiempo para evitar que pierda varias vidas de un solo golpe
		lastZombieContact = clock();
	}
}