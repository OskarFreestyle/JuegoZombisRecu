#include "MuteCross.h"
#include "ImageComponent.h"
#include "AudioManager.h"
#include "Entidad.h"

MuteCross::~MuteCross()
{
}

bool MuteCross::init(const std::map<std::string, std::string>& mapa)
{
    // Image Component necesita existir antes
    if (!_entity->getComponent<ImageComponent>()->getInitialized()) return false;

    // Activa o no la imagen segun el estado del sonido del juego (muteado o no)
    isMute = AudioManager::GetInstance()->getMute();
    _entity->getComponent<ImageComponent>()->setActive(isMute);

    _inicializado = true;
   
    return true;
}

void MuteCross::update()
{
    lastState = isMute;
    isMute = AudioManager::GetInstance()->getMute();

    // Solo manda activar/desactivar la imagen si hay un cambio en el mute
    if (lastState != isMute) {
        _entity->getComponent<ImageComponent>()->setActive(isMute);
    }
}