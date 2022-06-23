#include "MoveBullet.h"
#include "Entidad.h"
#include "Transform.h"
#include "Motor.h"
#include "InputManager.h"

MoveBullet::MoveBullet()
{
}

MoveBullet::~MoveBullet()
{
}

bool MoveBullet::init(const std::map<std::string, std::string>& mapa)
{
	if (mapa.find("velocity") == mapa.end()) return false;

	std::string velocityString = mapa.at("velocity");
	vel = stof(velocityString);

	_inicializado = true;
	
    return true;
}

void MoveBullet::setVelocity(float v)
{
	vel = v;
}

void MoveBullet::setDireccion(Vectola3D d)
{
	dir = d;
}

void MoveBullet::update()
{
	if (isDirCalculated == false) {
		Vectola3D aux = { (SCALE_X*ih().getMousePosInGame().first) - _entity->getComponent<Transform>()->getPosition().getX(),
						 0,
						 ((SCALE_Z *ih().getMousePosInGame().second) - _entity->getComponent<Transform>()->getPosition().getZ())};
		
		setDireccion(aux);
		dir = dir.normalize();
		isDirCalculated = true;
	}

	Vectola3D mov = { dir * vel * Motor::GetInstance()->getDeltaTime() };
	_entity->getComponent<Transform>()->setPosition(_entity->getComponent<Transform>()->getPosition() + mov);
	
	if (_entity->getComponent<Transform>()->getPosition().getX() > LIMIT_X || _entity->getComponent<Transform>()->getPosition().getX()< -LIMIT_X || _entity->getComponent<Transform>()->getPosition().getZ() > LIMIT_Z ||  _entity->getComponent<Transform>()->getPosition().getZ() < -LIMIT_Z) {
		_entity->setActive(false);
	}
}
