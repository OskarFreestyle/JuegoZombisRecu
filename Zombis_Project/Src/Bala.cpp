#include "Bala.h"
#include "LuaReader.h"
#include "EntidadManager.h"
#include "LoadResources.h"
#include "Entidad.h"
#include "InputManager.h"
#include "Transform.h"
#include "MoveBullet.h"


Bala::Bala()
{
	
	
	
}

Bala::~Bala()
{
	
}

void Bala::click()
{
	if (ih().getMouseButtonState(ih().LEFT)) {
		creaBala();
	}
}




/*Vectola3D* Bala::getDir()
{
	return dir;
}

float Bala::getVel()
{
	return vel;
}

void Bala::setVel(float v)
{
	vel = v;
}

void Bala::setDir(Vectola3D* v)
{
	dir = v;
}
*/
void Bala::creaBala()
{
	Entidad* e = Entidad::instantiate("Bala.prefab");
	e->setEntityMngr(Singleton<EntidadManager>::instance());
	if (e->getComponent<MoveBullet>()) {
		std::cout << "Tiene moveBullet" << std::endl;
	}
	//vel = 5.0f;
	//dir = new Vectola3D ();
	//dir->setX(ih().getMousePos().first - e->getComponent<Transform>()->getPosition().getX());
	//dir->setY(ih().getMousePos().second - e->getComponent<Transform>()->getPosition().getY());
	
}

