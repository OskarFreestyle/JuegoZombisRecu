#pragma once
#include "Componente.h"

class MuteCross : public Componente
{
public:
    MuteCross() {};
    ~MuteCross();
    bool init(const std::map<std::string, std::string>& mapa);
    void update();

private:
    bool lastState = false;
    bool isMute = false;
};

