#pragma once
#include "Componente.h"

class Entidad;
class Transform;

// Componente para el movimiento del Player
class Jugador : public Componente {
public:
	Jugador();
	virtual ~Jugador() {};

	bool init(const std::map<std::string, std::string>& mapa) override;

	void update();

	void onCollisionStart(Entidad* other) override;

	//Metodo para cambiarle la velocidad al jugador
	void setSpeed(float speed) { _speed = speed; }

protected:
	Transform* _transform;
	float _speed;
	Vectola3D _dir;

	clock_t _lastZombieContact = 0;
	clock_t _lastSound = 0;
};