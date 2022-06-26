#include "zombieMove.h"
#include "Entidad.h"
#include <iostream>
#include "Transform.h"
#include "RigidBody.h"
#include "SceneManager.h"
#include "GameManager.h"
#include "AudioSource.h"
#include "AudioManager.h"

ZombieMove::~ZombieMove()
{
}

bool ZombieMove::init(const std::map<std::string, std::string>& mapa)
{
	if (mapa.find("life") == mapa.end() || mapa.find("speed") == mapa.end())
		return false;

	std::string auxString = mapa.at("life");
	_life = stof(auxString);

	auxString = mapa.at("speed");
	_speed = stof(auxString);


	return true;
}

void ZombieMove::onCollisionStart(Entidad* other) {
	if (other->getName() == "Bala") {
		// Destruir bala
		//SceneManager::GetInstance()->addEntityToRemove(other);
		_life--;
		
		if (_life <= 0) {
			if (!AudioManager::GetInstance()->getMute())
				_entity->getComponent<AudioSource>()->play();
			// Sumar punto
			GameManager::GetInstance()->onZombieKilled();
			// Destruir zombi
			SceneManager::GetInstance()->addEntityToRemove(_entity);
		}
	}
}

void ZombieMove::update()
{
	// Busca la entidad del jugador
	if (_player==nullptr) _player = SceneManager::GetInstance()->getEntityByName("Player");

	Vectola3D aux = _entity->getComponent<Transform>()->getPosition();

	if (_entity->hasComponent<RigidBody>() && _entity->hasComponent<Transform>()){
		// Se calcula la direccion
		Vectola3D dir = _player->getComponent<Transform>()->getPosition() - _entity->getComponent<Transform>()->getPosition();

		// Importante normalizar y añadir el speed
		dir = dir.normalize() * _speed;

		// CINEMATIC
		//_entity->getComponent<Transform>()->setPosition(_entity->getComponent<Transform>()->getPosition() + dir);

		// PHYSX
		_entity->getComponent<RigidBody>()->setVelocity(physx::PxVec3(dir.getX(), dir.getY(), dir.getZ()));
	}
}
