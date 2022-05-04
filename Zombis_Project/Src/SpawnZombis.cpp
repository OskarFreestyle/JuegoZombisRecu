#include "SpawnZombis.h"

#include "InputManager.h"
#include "Entidad.h"
#include "EntidadManager.h"
#include "Transform.h"
#include <time.h>
#include "FMODAudioManager.h"

const int POS_ZOMBIS = 800;
const clock_t TIME_TO_SPAWN = 1000;

bool SpawnZombis::init(const std::map<std::string, std::string>& mapa)
{
	return true;
}

void SpawnZombis::update()
{
	clock_t auxc = clock();
	if(auxc > lastZombie + TIME_TO_SPAWN){

		lastZombie = auxc;

		std::cout << "Se crea un Zombie\n";
		Entidad* zombie = Entidad::instantiate("Zombie.prefab");
		Singleton<FMODAudioManager>::instance()->playMusic(5, false);

		// Los zombis se generan en las 4 esquinas
		int x = POS_ZOMBIS;
		int z = POS_ZOMBIS;

		if (rand() % 2 == 1) {
			x = -x;
		}

		if (rand() % 2 == 1) {
			z = -z;
		}

		std::cout << "x: " << x << " z: " << z << "\n";
		zombie->getComponent<Transform>()->setPosition(zombie->getComponent<Transform>()->getPosition() + Vectola3D(x, 0, z));
	}
}
