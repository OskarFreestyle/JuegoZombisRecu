#pragma once
#include "Componente.h"

typedef long clock_t;

const int POS_ZOMBIS_X = 1000;
const int POS_ZOMBIS_Y = 1;
const int POS_ZOMBIS_Z = 1000;
const int MARGIN = 100;
const float ZOMBIE_FAST_CHANCE = 0.1f;
const float ZOMBIE_STRONG_CHANCE = 0.1f;

// Spawnea un zombie de tipo aleatorio cada cierto tiempo hasta llegar al limite de la ronda
class SpawnZombis : public Componente
{
public:
    SpawnZombis() {};
    ~SpawnZombis() {};
    bool init(const std::map<std::string, std::string>& mapa);
    void update();
private:
    clock_t _lastZombie = 0;
    clock_t _timeToSpawn = 0;
};

