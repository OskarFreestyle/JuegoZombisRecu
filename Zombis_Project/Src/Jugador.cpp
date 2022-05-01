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
		double ejx = 0;
		double ejz = 0;

		//el imput para ir al norte o al sur del escenario
		if (ih().isKeyDown(SDL_SCANCODE_W)) {
			ejz = speed_;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_S)) {
			ejz = -speed_;
		}

		//el imput para ir al este o al oeste del escenario
		if (ih().isKeyDown(SDL_SCANCODE_A)) {
			ejx = -speed_;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_D)) {
			ejx = speed_;
		}

		//Esto es para que se mueva el personaje, hay 2 versiones porque no se cual es la correcta, descomentarlo para testear
		//version 1 usando el translate del transform
		//entity_->getComponent<Transform>()->translate(ejx, 0.0, ejz);
		//version 2 crea un vector3d y lo suma a la posicion del personaje
		//Vectola3D res = { ejx, 0.0, ejz };
		//entity_->getComponent<Transform>()->setPosition(entity_->getComponent<Transform>()->getPosition() + res);

		//Este es el caso en el que el jugador pulse el boton izquierdo del raton
		/*if (ih().getMouseButtonState(ih().LEFT)) {
			//aqui poner el metodo de disparar cuando esten las balas
		}*/
	}
}