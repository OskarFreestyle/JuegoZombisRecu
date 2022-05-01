#include "Jugador.h"
//#include "Transform.h"
#include<Transform.h>

Jugador::Jugador() : 
	transform_(nullptr),
	speed_()
	{
	}

bool Jugador::init(const std::map<std::string, std::string>& mapa) {
	if (mapa.find("speed") == mapa.end())
		return false;

	transform_ = entity_->getComponent<Transform>();

	std::string s = mapa.at("speed");
	speed_ = stof(s);

	return true;
};

void Jugador::update() {
	if (active_) {
		Vectola3D v;
		v.setY(0);
		

		//el imput para ir al norte o al sur del escenario
		if (ih().isKeyDown(SDL_SCANCODE_W)) {
			
			v.setZ(-1);
		}
		else if (ih().isKeyDown(SDL_SCANCODE_S)) {
			
			v.setZ(1);
		}

		//el imput para ir al este o al oeste del escenario
		if (ih().isKeyDown(SDL_SCANCODE_A)) {
			v.setX(-1);
		}
		else if (ih().isKeyDown(SDL_SCANCODE_D)) {
			v.setX(1);
		}

		Vectola3D mov=v.normalize()*speed_;

		entity_->getComponent<Transform>()->setPosition(entity_->getComponent<Transform>()->getPosition() + mov);

	}
}