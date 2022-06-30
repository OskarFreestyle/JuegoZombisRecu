#include "Shoot.h"
#include "InputManager.h"
#include "Entidad.h"
#include "Transform.h"
#include <time.h>
#include "AudioSource.h"


Shoot::Shoot() : _shootTime(), _cont(), _lastBullet()
{
}

Shoot::~Shoot()
{
}

bool Shoot::init(const std::map<std::string, std::string>& mapa)
{
    if (mapa.find("shootTime") == mapa.end()) return false;
    std::string::size_type sz = 0, sa = 0;
    std::string shootTimeString = mapa.at("shootTime");
    _shootTime = stoi(shootTimeString);
    _inicializado = true;
   
    return true;
}

void Shoot::update()
{
    clock_t auxc = clock();

    // Primero compueba que haya pasado el tiempo necesario para disparar una bala
    if (auxc > _lastBullet + _shootTime) {

        // Luego si está pulsado el boton izquierdo del ratón se dispara
        if (ih().getMouseButtonState(ih().LEFT)) {
            // Actualiza el tiempo
            _lastBullet = auxc;

            // Se instancia la bala
            Vectola3D pos = _entity->getComponent<Transform>()->getPosition();
           
            pos.setY(DISTANCE_TO_FLOOR); //Distancia para que no choque con el suelo
           
            Entidad* bala = Entidad::instantiate("Bala.prefab", pos);

            if(bala) bala->getComponent<AudioSource>()->play();
           
        }
    }
}