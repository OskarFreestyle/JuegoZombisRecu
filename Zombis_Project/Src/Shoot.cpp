#include "Shoot.h"
#include "InputManager.h"

#include "Entidad.h"
#include "EntidadManager.h"
#include "Transform.h"
#include <time.h>
#include "FMODAudioManager.h"


//const clock_t TIME_TO_SPAWN = 2000;

Shoot::Shoot()
{
}

Shoot::~Shoot()
{
    //balas.clear();
    //Si acaso luego borrar vector balas
}

bool Shoot::init(const std::map<std::string, std::string>& mapa)
{
    if (mapa.find("shootTime") == mapa.end()) return false;
    std::string::size_type sz = 0, sa = 0;
    std::string shootTimeString = mapa.at("shootTime");
    shootTime = stoi(shootTimeString);
    inicializado_ = true;
   
    return true;
}

void Shoot::update()
{
    clock_t auxc = clock();
    // Primero compueba que haya pasado el tiempo necesario para disparar una bala
    if (auxc > lastBullet + shootTime) {
        // Luego si está pulsado el boton izquierdo del ratón se dispara
        if (ih().getMouseButtonState(ih().LEFT)) {

            std::cout << "Dispara" << std::endl;

            // Actualiza el tiempo
            lastBullet = auxc;

            // Se instancia la bala
            Vectola3D pos = entity_->getComponent<Transform>()->getPosition();
            pos.setY(100);

            Entidad* bala = Entidad::instantiate("Bala.prefab", pos);
            Singleton<FMODAudioManager>::instance()->playMusic(2, false);
        }
        if (ih().getMouseButtonState(ih().RIGHT)) {

            std::cout << "Crea Zombie" << std::endl;

            // Actualiza el tiempo
            lastBullet = auxc;

            // Se instancia la bala
            Vectola3D pos = entity_->getComponent<Transform>()->getPosition();
            pos.setY(100);
            pos.setX(200);
            pos.setZ(200);

            Entidad* bala = Entidad::instantiate("Zombie.prefab", pos);
            //Singleton<FMODAudioManager>::instance()->playMusic(2, false);
        }
    }
}