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
    _isMute = AudioManager::GetInstance()->getMute();
    _entity->getComponent<ImageComponent>()->setActive(_isMute);

    _inicializado = true;
   
    return true;
}

void MuteCross::update()
{
    _lastState = _isMute;
    _isMute = AudioManager::GetInstance()->getMute();

    // Solo manda activar/desactivar la imagen si hay un cambio en el mute
    if (_lastState != _isMute) {
        _entity->getComponent<ImageComponent>()->setActive(_isMute);
    }
}