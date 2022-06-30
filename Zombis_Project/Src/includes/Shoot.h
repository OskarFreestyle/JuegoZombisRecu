#pragma once
#include "Componente.h"
 
const float DISTANCE_TO_FLOOR = 110;
typedef long clock_t;

// Crea una bala 
class Shoot : public Componente
{
public:
    Shoot();
    ~Shoot();
    bool init(const std::map<std::string, std::string>& mapa);
    void update();

private:
    int _shootTime = 0;
    int _cont = 0;
    
    clock_t _lastBullet = 0;
};

