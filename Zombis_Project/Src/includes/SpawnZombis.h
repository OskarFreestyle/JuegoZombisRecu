#pragma once
#include "Componente.h"

typedef long clock_t;

class SpawnZombis : public Componente
{
public:
    SpawnZombis() {};
    ~SpawnZombis() {};
    bool init(const std::map<std::string, std::string>& mapa);
    void update();
private:
    clock_t lastZombie = 0;
};

