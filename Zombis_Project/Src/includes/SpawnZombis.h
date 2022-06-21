#pragma once
#include "Componente.h"

typedef long clock_t;

const int POS_ZOMBIS_X = 1000;
const int POS_ZOMBIS_Y = 1;
const int POS_ZOMBIS_Z = 1000;
const int MARGIN = 100;
const clock_t TIME_TO_SPAWN = 400;

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

