#include "MoveBullet.h"
#include "Entidad.h"
#include "Transform.h"
#include "InputManager.h"
MoveBullet::MoveBullet()
{
}

MoveBullet::~MoveBullet()
{
}

bool MoveBullet::init(const std::map<std::string, std::string>& mapa)
{
	if (mapa.find("direction") == mapa.end() || mapa.find("velocity") == mapa.end()) return false;
	std::string::size_type sz = 0, sa = 0;

	std::string posString = mapa.at("direction");
	float a = stof(posString, &sz);
	std::string temp = posString.substr(sz + 1);
	float b = stof(temp, &sa);
	float c = stof(posString.substr(sz + sa + 2));
	dir = { a, b, c };

	/*std::string s2 = mapa.at("rotation");
	_localRotation = Quaterniola::Euler({ stof(s2, &sz), stof(s2.substr(sz + 1), &sa), stof(s2.substr(sz + sa + 2)) });*/

	std::string velocityString = mapa.at("velocity");
	vel = stof(velocityString);

	inicializado_ = true;
	
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
		std::cout << ih().getMousePosInGame().first << " " << ih().getMousePosInGame().second  << std::endl;
		std::cout << this->getEntidad()->getComponent<Transform>()->getPosition().getX()<<" "<< this->getEntidad()->getComponent<Transform>()->getPosition().getY()<<" "<< this->getEntidad()->getComponent<Transform>()->getPosition().getZ() << std::endl;
		std::cout << this->getEntidad()->getComponent<Transform>()->getLocalPosition().getX() << " " << this->getEntidad()->getComponent<Transform>()->getLocalPosition().getY() << " " << this->getEntidad()->getComponent<Transform>()->getLocalPosition().getZ() << std::endl;
		Vectola3D aux = { (SCALE_X*ih().getMousePosInGame().first) - this->getEntidad()->getComponent<Transform>()->getPosition().getX(),
						 0,
						 ((SCALE_Z *ih().getMousePosInGame().second) - this->getEntidad()->getComponent<Transform>()->getPosition().getZ())};
		std::cout << aux.getX() << " " << aux.getY() << " " << aux.getZ() << std::endl;

		
		setDireccion(aux);
		dir = dir.normalize();
		isDirCalculated = true;
	}
	Vectola3D mov = { dir * vel };
	this->getEntidad()->getComponent<Transform>()->setPosition(this->getEntidad()->getComponent<Transform>()->getPosition()+mov);
}
