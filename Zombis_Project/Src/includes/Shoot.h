#pragma once
#include "Componente.h"
//#include <vector>
class InputManager;
class Entidad;
class Transform;
class EntidadManager;

typedef long clock_t;

class Shoot :
    public Componente
{
private:
    //Bala* g;
    int maxNumBullets;
    int cont = 0;
    
    clock_t lastBullet = 0;
public:
    Shoot();
    ~Shoot();
    bool init(const std::map<std::string, std::string>& mapa);
    void update();
    //void setBala(Bala* ba);
};

