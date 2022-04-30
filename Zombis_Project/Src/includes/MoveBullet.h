#pragma once
#include "Componente.h"
#include "utils\Vectola3D.h"
class InputManager;
class Entidad;
class Transform;
class MoveBullet :
    public Componente
{
private:
    float vel;
    Vectola3D dir;
    bool isDirCalculated = false;
public:
    MoveBullet();
    ~MoveBullet();
    bool init(const std::map<std::string, std::string>& mapa);
    void setVelocity(float v);
    void setDireccion(Vectola3D d);
    void update();
};

