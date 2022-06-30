#pragma once
#include "Componente.h"

class Entidad;

// Mueve al zombie en linea recta hacia el jugador
class ZombieMove : public Componente
{
public:
	ZombieMove() {};
	virtual ~ZombieMove();

	bool init(const std::map<std::string, std::string>& mapa);

	void onCollisionStart(Entidad* other);

	void update();

private:
	Entidad* _player=nullptr;
	int _life;
	int _speed;
	int _pointsOnDead;
};

