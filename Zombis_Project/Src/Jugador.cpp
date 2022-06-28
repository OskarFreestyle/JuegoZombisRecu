#include "Jugador.h"
#include "InputManager.h"
#include "Transform.h"
#include "OgreVector3.h"
#include "RigidBody.h"
#include "GameManager.h"
#include "AudioSource.h"
#include <time.h>
#include "Entidad.h"

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
		// Movimiento Arriba-Abajo
		if (ih().iskeyContinuos(SDL_SCANCODE_W) && !ih().iskeyContinuos(SDL_SCANCODE_S)) v.setZ(-1);
		else if (ih().iskeyContinuos(SDL_SCANCODE_S) && !ih().iskeyContinuos(SDL_SCANCODE_W)) v.setZ(1);
		else v.setZ(0);

		// Movimiento Izquierda-Derecha
		if (ih().iskeyContinuos(SDL_SCANCODE_A) && !ih().iskeyContinuos(SDL_SCANCODE_D)) v.setX(-1);
		else if (ih().iskeyContinuos(SDL_SCANCODE_D) && !ih().iskeyContinuos(SDL_SCANCODE_A)) v.setX(1);
		else v.setX(0);

		Vectola3D mov = v.normalize() * speed_ * Motor::GetInstance()->getDeltaTime();

		// PHYSICS
		_entity->getComponent<RigidBody>()->setVelocity(physx::PxVec3(mov.getX(), mov.getY(), mov.getZ()));
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