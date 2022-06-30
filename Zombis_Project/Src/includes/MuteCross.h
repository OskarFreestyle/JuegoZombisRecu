#pragma once
#include "Componente.h"

// Imagen que se desactiva/activa al mutear el juego
class MuteCross : public Componente
{
public:
    MuteCross() {};
    ~MuteCross();
    bool init(const std::map<std::string, std::string>& mapa);
    void update();

private:
    bool _lastState = false;
    bool _isMute = false;
};

