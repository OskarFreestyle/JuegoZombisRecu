#include "SpawnZombis.h"

#include "InputManager.h"
#include "Entidad.h"
#include "SceneManager.h"
#include "GameManager.h"
#include "Transform.h"
#include <time.h>
#include "AudioManager.h"
#include "TextComponent.h"

bool SpawnZombis::init(const std::map<std::string, std::string>& mapa)
{
	if (mapa.find("newZombiesDelay") == mapa.end()) return false;

	std::string auxString = mapa.at("newZombiesDelay");
	timeToSpawn = stof(auxString);


	_inicializado = true;

	return true;
	return true;
}

void SpawnZombis::update()
{
	clock_t auxc = clock();
	if(auxc > lastZombie + timeToSpawn){
		lastZombie = auxc;

		// Determina el tipo de zombie que va a crearse
		Entidad* zombie = nullptr;
		float zombieChance = (rand() % 100) / 100.0f;

		// Comprueba el zombie que tiene que hacer
		if (zombieChance <= ZOMBIE_FAST_CHANCE) zombie = Entidad::instantiate("ZombieFast.prefab");
		else if (zombieChance > ZOMBIE_FAST_CHANCE && zombieChance <= (ZOMBIE_FAST_CHANCE + ZOMBIE_STRONG_CHANCE)) zombie = Entidad::instantiate("ZombieStrong.prefab");
		else zombie = Entidad::instantiate("Zombie.prefab");

		// Los zombis se generan en las 4 esquinas de manera aleatoria
		int x = POS_ZOMBIS_X;
		int z = POS_ZOMBIS_Z;

		int mx = rand() % MARGIN - MARGIN / 2;
		int mz = rand() % MARGIN - MARGIN / 2;

		if (rand() % 2 == 1) {
			x = -x;
			x += mx;
		}

		if (rand() % 2 == 1) {
			z = -z;
			z += mz;
		}

		zombie->getComponent<Transform>()->setPosition(zombie->getComponent<Transform>()->getPosition() + Vectola3D(x, POS_ZOMBIS_Y, z));

		GameManager::GetInstance()->increaseNumZombies();
	}
}
