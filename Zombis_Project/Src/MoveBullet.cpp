#include "MoveBullet.h"
#include "Entidad.h"
#include "Transform.h"
#include "Motor.h"
#include "InputManager.h"

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

void MoveBullet::setDireccion() {
	//std::cout << "EntityPos: " << _entity->getComponent<Transform>()->getPosition().getX() << ", " << _entity->getComponent<Transform>()->getPosition().getZ() << "\n";
	//std::cout << "MousePos: " << ih().getMousePos().first << ", " << ih().getMousePos().second << "\n";

	Vectola3D aux = { (ih().getMousePos().first) - _entity->getComponent<Transform>()->getPosition().getX(),
				 0,
				 ((ih().getMousePos().second) - _entity->getComponent<Transform>()->getPosition().getZ()) };

	dir = aux.normalize();
	isDirCalculated = true;
}

void MoveBullet::update()
{
	if (!isDirCalculated) {
		setDireccion();
	}

	Vectola3D mov = { dir * vel * Motor::GetInstance()->getDeltaTime() };
	_entity->getComponent<Transform>()->setPosition(_entity->getComponent<Transform>()->getPosition() + mov);
}
