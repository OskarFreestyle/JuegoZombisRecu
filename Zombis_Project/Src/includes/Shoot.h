#pragma once
#include "Componente.h"
//#include <vector>
class InputManager;
class Bala;
class Entidad;
class EntidadManager;

class Shoot :
    public Componente
{
private:
    //Bala* g;
    int maxNumBullets;
    int cont = 0;
public:
    Shoot();
    ~Shoot();
    bool init(const std::map<std::string, std::string>& mapa);
    void update();
    void setBala(Bala* ba);
};

