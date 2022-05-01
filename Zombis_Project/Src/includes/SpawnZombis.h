#pragma once
#include "Componente.h"

class SpawnZombis : public Componente
{
public:
    SpawnZombis() {};
    ~SpawnZombis() {};
    bool init(const std::map<std::string, std::string>& mapa);
    void update();
};

