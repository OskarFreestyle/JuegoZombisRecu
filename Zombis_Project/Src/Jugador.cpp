#include "Jugador.h"
//#include "Transform.h"
#include<Transform.h>

Jugador::Jugador() : 
	transform_(nullptr),
	speed_(), v()
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
		v.setY(0);
	
		// Arriba - Abajo
		if (ih().isKeyDown(SDL_SCANCODE_W)) {
			v.setZ(-1);
		}
		else if (ih().isKeyDown(SDL_SCANCODE_S)) {
			v.setZ(1);
		}
		else if (ih().isKeyUp(SDL_SCANCODE_W) || ih().isKeyUp(SDL_SCANCODE_S)) {
			v.setZ(0);
		}

		// Izquierda - Derecha
		if (ih().isKeyDown(SDL_SCANCODE_A)) {
			v.setX(-1);
		}
		else if (ih().isKeyDown(SDL_SCANCODE_D)) {
			v.setX(1);
		}
		else if (ih().isKeyUp(SDL_SCANCODE_A) || ih().isKeyUp(SDL_SCANCODE_D)) {
			v.setX(0);
		}

		Vectola3D mov = v.normalize() * speed_;

		entity_->getComponent<Transform>()->setPosition(entity_->getComponent<Transform>()->getPosition() + mov);

	}
}