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


void Bala::creaBala()
{
	//Entidad* e = Entidad::instantiate("Bala.prefab");
	Entidad* e=Entidad::instantiate("Bala.prefab", Vectola3D(0, 0, 0));
	//return e;
	//EntidadManager* aux = Singleton<EntidadManager>::instance();
	//std::cout << e << std::endl;
	//e->setEntityMngr(Singleton<EntidadManager>::instance());
	//std::cout << balas.size() << std::endl;
	//e->setEntityMngr(Singleton<EntidadManager>::instance());
	/*if (e->getComponent<MoveBullet>()) {
		std::cout << "Tiene moveBullet" << std::endl;
	}*/
	
}

