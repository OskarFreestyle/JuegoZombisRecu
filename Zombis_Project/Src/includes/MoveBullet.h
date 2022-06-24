#pragma once
#include "Componente.h"
#include "SceneManager.h"
#include "Vectola3D.h"
class InputManager;
class Entidad;
class Transform;

const float SCALE_WITH_CAM = 1 / 630.0;

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
    float vel;
    Vectola3D dir;
    bool isDirCalculated = false;
};

