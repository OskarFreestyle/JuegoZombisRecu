#include "Jugador.h"
#include <iostream>
#include "Transform.h"
#include "Entidad.h"
#include "InputManager.h"
#include "OgreVector3.h"
#include "RigidBody.h"
#include "GameManager.h"
#include "AudioSource.h"
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

	transform_ = _entity->getComponent<Transform>();

	std::string s = mapa.at("speed");
	speed_ = stof(s);

	return true;
};

void Jugador::update() {
	Vectola3D aux = _entity->getComponent<Transform>()->getPosition();

	if (_active) {
		if (ih().iskeyContinuos(SDL_SCANCODE_W) && !ih().iskeyContinuos(SDL_SCANCODE_S)) {
			v.setZ(-1);
			_entity->getComponent<AudioSource>()->play();
		}
		else if (ih().iskeyContinuos(SDL_SCANCODE_S) && !ih().iskeyContinuos(SDL_SCANCODE_W)) {
			v.setZ(1);
			_entity->getComponent<AudioSource>()->play();
		}
		else v.setZ(0);

		if (ih().iskeyContinuos(SDL_SCANCODE_A) && !ih().iskeyContinuos(SDL_SCANCODE_D)) { 
			v.setX(-1); 
			_entity->getComponent<AudioSource>()->play();
		}
		else if (ih().iskeyContinuos(SDL_SCANCODE_D) && !ih().iskeyContinuos(SDL_SCANCODE_A)) {
			v.setX(1);
			_entity->getComponent<AudioSource>()->play();
		}
		else v.setX(0);

		Vectola3D mov = v.normalize() * speed_;
		


		// CINEMATIC
		//_entity->getComponent<Transform>()->setPosition(_entity->getComponent<Transform>()->getPosition() + mov * 0.01f);

		// PHYSICS
		_entity->getComponent<RigidBody>()->setVelocity(physx::PxVec3(mov.getX(), mov.getY(), mov.getZ()));
		_entity->getComponent<AudioSource>()->stop();
	}
}

void Jugador::onCollisionStart(Entidad* other)
{
	if (other->getName() == "Zombie" && clock() > lastZombieContact + TIME_TO_ANOTHER_ZOMBIE_CONTACT) {
		// Pierde una vida
		GameManager::GetInstance()->removeLive();

		// Pone un tiempo para evitar que pierda varias vidas de un solo golpe
		lastZombieContact = clock();
	}
}