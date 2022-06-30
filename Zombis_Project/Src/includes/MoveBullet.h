#pragma once
#include "Componente.h"
class SceneManager;
class InputManager;
class Entidad;
class Transform;

const float SCALE_WITH_CAM = 1 / 630.0;

// Movimiento de la bala en la direccion del ratón
class MoveBullet : public Componente
{
public:
    MoveBullet();
    ~MoveBullet();
    bool init(const std::map<std::string, std::string>& mapa);
   
    void setDireccion();
    void update();

    void onCollisionStart(Entidad* other);

private:
    float _vel;
    Vectola3D _dir;
    bool _isDirCalculated = false;
};

