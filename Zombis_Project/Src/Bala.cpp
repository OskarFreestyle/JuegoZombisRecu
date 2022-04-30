#include "Bala.h"
#include "LuaReader.h"
#include "EntidadManager.h"
#include "LoadResources.h"
#include "Entidad.h"

Bala::Bala()
{
	
	readPrefab(Singleton<LoadResources>::instance()->prefab("Bala.prefab"))->setEntityMngr(Singleton<EntidadManager>::instance());
	
}

Bala::~Bala()
{
}

