#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include <iostream>

// Motor
#include <Motor.h>
#include <Transform.h>
#include "ComponenteRegistro.h"
#include "Entidad.h"
#include "SceneManager.h"
#include "AudioManager.h"
#include "LoadResources.h"

// Juego
#include "Juego.h"
#include "GameManager.h"
#include "EndState.h"

// Componentes
#include "MoveBullet.h"
#include "Shoot.h"
#include "Personaje.h"
#include "Jugador.h"
#include "LookatMouse.h"
#include "zombieMove.h"
#include "SpawnZombis.h"

void RegistryGameComponents() {
	try {
		ComponenteRegistro::ComponenteRegistro<MoveBullet>("moveBullet");
		ComponenteRegistro::ComponenteRegistro<Shoot>("shoot");
		ComponenteRegistro::ComponenteRegistro<Personaje>("personaje");
		ComponenteRegistro::ComponenteRegistro<Jugador>("jugador");
		ComponenteRegistro::ComponenteRegistro<ZombieMove>("zombieMove");
		ComponenteRegistro::ComponenteRegistro<LookatMouse>("lookatMouse");
		ComponenteRegistro::ComponenteRegistro<SpawnZombis>("spawnZombis");
	}
	catch (...) {
		std::cerr << "ERROR CARGANDO LOS COMPONENTES DEL JUEGO\n";
	}
#if (defined _DEBUG)
	std::cout << "---------- GAME COMPONENTES CARGADOS ----------\n";
#endif
}

void loadMusic() {
	try {
		// Se crea una entidad para la musica
		//SceneManager::GetInstance()->addEntity(new Entidad("music", 1));
		//Singleton<EntidadManager>::instance()->addEntidad("music", 1);
		AudioManager::GetInstance()->loadMusic(0, LoadResources::GetInstance()->aud("GameMusicShort.mp3").c_str());
		AudioManager::GetInstance()->playMusic(0, true);
		AudioManager::GetInstance()->loadMusic(1, LoadResources::GetInstance()->aud("click.mp3").c_str());
		AudioManager::GetInstance()->loadMusic(2, LoadResources::GetInstance()->aud("disparo_1.mp3").c_str());
		AudioManager::GetInstance()->loadMusic(3, LoadResources::GetInstance()->aud("golpes_1.mp3").c_str());//Para colision entre zombi y jugador
		AudioManager::GetInstance()->loadMusic(4, LoadResources::GetInstance()->aud("walkingsound.mp3").c_str());
		AudioManager::GetInstance()->loadMusic(5, LoadResources::GetInstance()->aud("zombieSound.mp3").c_str());
	}
	catch (...) {
		std::cerr << "ERROR AL INICIAR LA MUSICA DEL JUEGO\n";
	}

}

int LoadGame() {
#if (defined _DEBUG)
	std::cout << "---------- TRYING LOAD GAME ----------\n";
#endif

	// Se registran los componentes
	RegistryGameComponents();
	//loadMusic();

	// Se crea el game manager
	GameManager::Init();

#if (defined _DEBUG)
	std::cout << "GAME MANAGER CORRECTO\n";
#endif

	//SceneManager::GetInstance()->newScene("NewMainMenu.lua");
	SceneManager::GetInstance()->newScene("NewMainMenu.lua");

	// Probar a quitar luego a ver que pasa
	//SceneManager::GetInstance()->loadEntities();

	

#if (defined _DEBUG)
	std::cout << "GAME LOAD CORRECTLY\n";
#endif
	return 0;
}