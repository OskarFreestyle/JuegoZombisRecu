#pragma once
#include "Componente.h"
#include "utils\Vectola3D.h"
class InputManager;
class Entidad;
class Transform;

const float SCALE_X= 1270.0 / 320;
const float SCALE_Z=940.0 / 240;

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

