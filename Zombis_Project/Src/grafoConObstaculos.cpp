#include "grafoConObstaculos.h"
#include "generaAleatorio.h"
#include "grafo.h"
#include "bfs.h"


#include "Entidad.h"
#include "utils/Singleton.h"
#include "EntidadManager.h"
#include <string>

GrafoConObstaculos::GrafoConObstaculos()
{
	arrayCaminos = new std::vector<CaminoMasCorto>();

}

bool GrafoConObstaculos::init(const std::map<std::string, std::string>& mapa)
{

	if (mapa.find("alto") == mapa.end() || mapa.find("ancho") == mapa.end())
		return false;

	alto = stoi(mapa.at("alto"));
	ancho = stoi(mapa.at("ancho"));
	int nObstaculos = rand() % 10 + 5; //genera nObs entre 5 a 14
	int base1 = rand() % 5 + 3; //base1 entre 3 a 7
	int base2 = rand() % 5 + 4; //base2 entre 4 a 8
	GeneracionAleatorio genera(nObstaculos, base1, base2, alto, ancho);
	matriz = genera.generaObstaculo();
	int vertices = int(ancho * alto);
	g = new Grafo(vertices);

	for (int i = 0; i < ancho * alto; i++)
	{
		if (matriz[i] != 1)
		{
			addAristas(i);
		}
		else
		{
			//colocarObstaculos(i);
		}

	}
	//terminado de inicializar el grafo


	for (int i = 0; i < ancho * alto; i++)
	{
		arrayCaminos->push_back(CaminoMasCorto(g, i));

	}


	return true;
}

std::deque<int> GrafoConObstaculos::getCaminoMasCorto(int ori, int dest)
{
	if (!arrayCaminos->empty())
		return arrayCaminos->at(ori).camino(dest);
}


void GrafoConObstaculos::addAristas(int index)
{
	//poner aristas cercanos de vertice a su fila anterior y su fila actual.
	int other;

	other = index - ancho - 1;
	if (other >= 0  && index % ancho !=0  && matriz[other] !=1)
	{
		g->ponArista(index, other);

	}

	other = index - ancho;
	if (other >= 0 && matriz[other] != 1)
	{
		g->ponArista(index, other);

	}

	other = index - ancho + 1;
	if (other >= 0 && (index-1) % ancho != 0 && matriz[other] != 1)
	{
		g->ponArista(index, other);

	}

	other = index - 1;
	if (other >=0 && index % ancho != 0)
	{
		g->ponArista(index, other);
	}
	
	other = index + 1;
	if ((index-1) % ancho != 0 && other < ancho*alto && matriz[other] != 1)
	{
		g->ponArista(index, other);
	}

}
//
//void GrafoConObstaculos::colocarObstaculos(int i)
//{
//	Entidad* ent = Singleton<EntidadManager>::instance()->addEntidad();
//	//añadir componente collider;
//
//
//	std::map<std::string, std::string> compMap;
//	std::string s1 = "parent";
//	std::string s2 = "-1";
//	compMap.insert((std::pair<std::string, std::string>(s1, s2)));
//	s1 = "position";
//	s2 = "" + std::to_string( (i / ancho)*tamVertice) + ",10," + std::to_string((i % ancho)*tamVertice);
//	compMap.insert((std::pair<std::string, std::string>(s1, s2)));
//	s1 = "rotation";
//	s2 = "0,0,0"; 
//	compMap.insert((std::pair<std::string, std::string>(s1, s2)));
//	s1 = "scale";
//	s2 = "1,1,1";
//	compMap.insert((std::pair<std::string, std::string>(s1, s2)));
//
//	ent->addComponent("transform", compMap);
//
//	compMap.clear();
//
//	s1= "mesh";
//	s2= "barril.mesh";
//	compMap.insert((std::pair<std::string, std::string>(s1, s2)));
//	s1 = "material";
//	s2 = "Azul"; //si hay otro color, lo cambiamos
//	compMap.insert((std::pair<std::string, std::string>(s1, s2)));
//	s1 = "visible";
//	s2 = "true"; 
//	compMap.insert((std::pair<std::string, std::string>(s1, s2)));
//
//	ent->addComponent("mesh", compMap);
//}
