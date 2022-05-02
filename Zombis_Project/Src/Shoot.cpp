#include "Shoot.h"
#include "InputManager.h"

#include "Entidad.h"
#include "EntidadManager.h"
#include "Transform.h"
#include <time.h>
//Bala* g;
const clock_t TIME_TO_SPAWN = 2000;
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
    if (mapa.find("numBullets") == mapa.end()) return false;
    std::string::size_type sz = 0, sa = 0;
    std::string numBulletsString = mapa.at("numBullets");
    maxNumBullets = stoi(numBulletsString);
    inicializado_ = true;
   
    return true;
}

void Shoot::update()
{
    //g = new Bala();
   /* if (g = nullptr) {
        g = new Bala();
    }*/
    clock_t auxc = clock();
    if (auxc > lastBullet + TIME_TO_SPAWN) {
        
        if (ih().getMouseButtonState(ih().LEFT)) {
            lastBullet = auxc;
            std::cout << "Dispara" << std::endl;

            Entidad* bala = Entidad::instantiate("Bala.prefab", entity_->getComponent<Transform>()->getPosition());


            // e->setEntityMngr(Singleton<EntidadManager>::instance());


        }
    }
}

/*void Shoot::setBala(Bala* ba)
{
    g = ba;
}*/
