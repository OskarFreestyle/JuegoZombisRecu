#pragma once
#include "Componente.h"
#include "SceneManager.h"
#include "Vectola3D.h"
class InputManager;
class Entidad;
class Transform;

const float SCALE_X= 1270.0 / 320;
const float SCALE_Z= 940.0 / 240;
const float SCALE_WITH_CAM = 3000.0 / 630;


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

