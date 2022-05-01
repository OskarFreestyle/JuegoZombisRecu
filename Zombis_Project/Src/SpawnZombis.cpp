#include "SpawnZombis.h"

#include "InputManager.h"
#include "Entidad.h"
#include "EntidadManager.h"
#include "Transform.h"


bool SpawnZombis::init(const std::map<std::string, std::string>& mapa)
{
	return true;
}

void SpawnZombis::update()
{
	if (ih().isKeyDown(SDL_SCANCODE_Z)) {
		std::cout << "Se crea un Zombie\n";
		Entidad* zombie = Entidad::instantiate("Zombie.prefab");

		// Voy a ponerles posiciones aleatorias hasta que arreglemos el problema con las isntancias
		int x = rand() % 600 - 300;
		int z = rand() % 600 - 300;
		std::cout << "x: " << x << " z: " << z << "\n";
		zombie->getComponent<Transform>()->setPosition(zombie->getComponent<Transform>()->getPosition() + Vectola3D(x, 10, z));
		//zombie->getComponent<Transform>()->getPosition().setY(10);
		//zombie->getComponent<Transform>()->getPosition().setX(x);
		//zombie->getComponent<Transform>()->getPosition().setZ(z);
	}
}
