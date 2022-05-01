#include "Shoot.h"
#include "InputManager.h"
#include "Bala.h"
#include "Entidad.h"
#include "EntidadManager.h"
Bala* g;
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
    g = new Bala();
   /* if (g = nullptr) {
        g = new Bala();
    }*/
    if (ih().getMouseButtonState(ih().LEFT)) {
        std::cout << "Dispara" << std::endl;
        
        g->creaBala();
       // e->setEntityMngr(Singleton<EntidadManager>::instance());
        

    }
}

void Shoot::setBala(Bala* ba)
{
    g = ba;
}
