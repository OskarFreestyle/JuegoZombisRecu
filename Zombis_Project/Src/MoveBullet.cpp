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
	float camScale = SCALE_WITH_CAM * SceneManager::GetInstance()->getEntityByName("Camera")->getComponent<Transform>()->getPosition().getY();

	dir = { camScale * ih().getMousePosInGame().first - _entity->getComponent<Transform>()->getPosition().getX(),
			0,
			(camScale * ih().getMousePosInGame().second - _entity->getComponent<Transform>()->getPosition().getZ()) };

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
