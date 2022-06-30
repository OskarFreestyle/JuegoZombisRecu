#include "LookatMouse.h"
#include "InputManager.h"
#include "Entidad.h"
#include "Transform.h"

LookatMouse::LookatMouse() : _test(false) {
}

LookatMouse::~LookatMouse() {
}

bool LookatMouse::init(const std::map<std::string, std::string>& mapa)
{	
	if (mapa.find("test") == mapa.end()) return false;

	std::string staticString = mapa.at("test");
	if (staticString == "true") _test = true;

	_transform = _entity->getComponent<Transform>();
	if (_transform == nullptr)
		return false;

	_inicializado = true;

	return true;
}

void LookatMouse::rotateToMouse2D()
{
	MP = InputManager::GetInstance()->getMousePosInGame();

	float angle = atan2(MP.second - _transform->getPosition().getY(), MP.first - _transform->getPosition().getX());

	angle *= -180 / M_PI;
	angle -= 90;

	Vectola3D v(0, angle, 0) ;
	Quaterniola x = Quaterniola::Euler(v);


	_entity->getComponent<Transform>()->setRotation(x);
}

void LookatMouse::update()
{
	if (_entity->hasComponent<Transform>())
	{
		rotateToMouse2D();
	}

}