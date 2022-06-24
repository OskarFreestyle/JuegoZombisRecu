#pragma once
#include "Componente.h"
const float DISTANCE_TO_FLOOR=100;
typedef long clock_t;

class Shoot : public Componente
{
public:
    Shoot();
    ~Shoot();
    bool init(const std::map<std::string, std::string>& mapa);
    void update();

private:
    int shootTime = 0;
    int cont = 0;
    
    
    clock_t lastBullet = 0;
};

