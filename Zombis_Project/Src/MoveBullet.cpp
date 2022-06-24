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

void MoveBullet::setDireccion()
{
	std::cout <<"MOUSE: "<< ih().getMousePosInGame().first << " " << ih().getMousePosInGame().second << "\n";
	Vectola3D aux = { (SCALE_WITH_CAM * ih().getMousePosInGame().first) - _entity->getComponent<Transform>()->getPosition().getX(),
						 0,
					((SCALE_WITH_CAM * ih().getMousePosInGame().second) - _entity->getComponent<Transform>()->getPosition().getZ()) };
	dir = aux;

	std::cout << "Entidad: " << _entity->getComponent<Transform>()->getPosition().getX()<<","<< _entity->getComponent<Transform>()->getPosition().getY()<<","<< _entity->getComponent<Transform>()->getPosition().getZ() << "\n";
	dir = dir.normalize();
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
void MoveBullet::onCollisionStart(Entidad* other) {
	if (other->getName() == "Player") {
		return;
	}
	else {
		SceneManager::GetInstance()->addEntityToRemove(_entity);
	}
}
