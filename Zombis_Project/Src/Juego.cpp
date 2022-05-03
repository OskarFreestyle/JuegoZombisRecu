#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>

#include <Motor.h>
#include <Transform.h>
#include "ComponenteRegistro.h"

#include "Juego.h"
#include <iostream>
#include "Entidad.h"
#include "EntidadManager.h"
#include "LookatMouse.h"

#include "grafoConObstaculos.h"
#include "FMODAudioManager.h"
#include "LoadResources.h"
#include "MainMenu.h"

#include "EndState.h"


// Componentes
#include "MoveBullet.h"
#include "Shoot.h"
#include "SpawnZombis.h"
#include "Personaje.h"
#include "Jugador.h"
#include "GameManager.h"

void RegistryGameComponents() {
	try {
		ComponenteRegistro::ComponenteRegistro<MoveBullet>("moveBullet");
		ComponenteRegistro::ComponenteRegistro<Shoot>("shoot");
		ComponenteRegistro::ComponenteRegistro<Personaje>("personaje");
		ComponenteRegistro::ComponenteRegistro<Jugador>("jugador");
		ComponenteRegistro::ComponenteRegistro<LookatMouse>("lookatMouse");
		ComponenteRegistro::ComponenteRegistro<SpawnZombis>("spawnZombis");
	}
	catch (...) {
		std::cerr << "ERROR CARGANDO LOS COMPONENTES DEL JUEGO\n";
	}

	std::cout << "GAME COMPONENTS REGISTRY CORRECTLY\n";
}

void loadMusic() {
	try {
		// Se crea una entidad para la musica
		Singleton<EntidadManager>::instance()->addEntidad("music", 1);
		Singleton<FMODAudioManager>::instance()->loadMusic(0, Singleton<LoadResources>::instance()->aud("GameMusicShort.mp3").c_str());
		Singleton<FMODAudioManager>::instance()->playMusic(0, true);
	}
	catch (...) {
		std::cerr << "ERROR AL INICIAR LA MUSICA DEL JUEGO\n";
	}

}

// Simulación de la función de carga
int LoadGame() {
	std::cout << "TRYING LOAD GAME\n";

	// Se registran los componentes
	RegistryGameComponents();

	// Se crea el game manager
	GameManager::Init();
	std::cout << "GAME MANAGER CORRECTO\n";


	MainMenu* m = new MainMenu();
	//EndState* s = new EndState();
	
	
	//loadMusic();
	

	std::cout << "GAME LOAD CORRECTLY\n";
	return 0;
}