#include "zombieMove.h"
#include "Entidad.h"
#include "Transform.h"
#include "grafoConObstaculos.h"

ZombieMove::ZombieMove()
{
}

ZombieMove::~ZombieMove()
{
}

bool ZombieMove::init(const std::map<std::string, std::string>& mapa)
{

	return true;
}

void ZombieMove::update()
{
	if (entity_->hasComponent<Transform>())
	{
		//Transform * tr= entity_->getComponent<Transform>();
		//Vectola3D pos=  tr->getPosition();
		//int index =  GrafoConObstaculos::getMatrizPos(pos);


	}
}
