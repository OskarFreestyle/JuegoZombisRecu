#pragma once
#include "Componente.h"
#include "Transform.h"
#include "Entidad.h"

//Este es el componente generico para el jugador y los zombies
class Personaje : public Componente {
public:
	Personaje() : maxHealth() {};
	virtual ~Personaje() {};

	bool init(const std::map<std::string, std::string>& mapa) { 
		if (mapa.find("maxHealth") == mapa.end() || mapa.find("lifefactor") == mapa.end())
			return false;
		
		std::string maxHealthString = mapa.at("maxHealth");
		maxHealth = stof(maxHealthString);
		health = maxHealth; 

		std::string lifeFactorString = mapa.at("lifefactor");
		lifefactor = stof(lifeFactorString);

		return true;
	};

	//metodo en el que recibe daño el personaje 
	//los zombis siempre haran el mismo daño y el jugador podria aumentar el daño que inflinge a los zombis
	void takeDamage(double dmg) {
		health = health - dmg;
		//Si el personaje pierde toda la vida se destruira. Se tiene que hacer una distincion entre los zombis y el jugador
		//la distincion puede ser si tiene el componente jugador o zombi
		if (health <= 0) {
			entity_->destroy();
		}
	};

	//Metodo que escala la vida de los zombis para que aumente segun la ronda
	//Tambien se puede usar para subir la vida maxima del jugador si hacemos que se la pueda aumentar con un powerup o algo
	void scaleHealth(int s) {
		//Este calculo es para que aumente un cinco por ciento la vida por cada ronda y se podria implementar en el init directamente
		maxHealth += maxHealth * lifefactor * s;
		health = maxHealth;

		//Este otro calculo es la escala que tienen los zombis en cod zombies y este no se puede poner en el init directamente
		//ni sirve para aumentar la vida del jugador pero proporciona un mejor incremento de dificultad 
		//este calculo es perfecto si implementamos maneras de que el jugador pueda mejorar su arma y hacer mas daño
		/*if (s <= 9) {
			maxHealth = 10 * s + 5;
			health = maxHealth;
		}
		else {
			maxHealth = 95 * pow(1.1, s-9);
			health = maxHealth;
		}*/
	}

private:
	float health;
	float maxHealth;
	//esto es el valor sobre el que se escala la vida del personaje, por defecto seria 0.05f (cinco por ciento)
	float lifefactor = 0.05f;  

};