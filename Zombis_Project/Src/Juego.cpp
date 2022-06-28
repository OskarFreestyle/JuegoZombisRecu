#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include <iostream>

// Motor
#include <Transform.h>
#include "ComponenteRegistro.h"
#include "Entidad.h"
#include "SceneManager.h"
#include "AudioManager.h"
#include "LoadResources.h"

// Juego
#include "Juego.h"
#include "GameManager.h"

// Componentes
#include "MoveBullet.h"
#include "Shoot.h"
#include "ExitOnPlay.h"
#include "Jugador.h"
#include "LookatMouse.h"
#include "zombieMove.h"
#include "SpawnZombis.h"
#include "SaveRecord.h"
#include "MuteCross.h"

#include "Entidad.h"
#include "ScoreTextComponent.h"
#include "ScoreInGameText.h"
#include "RoundText.h"

int LoadGame() {
#if (defined _DEBUG)
	std::cout << "---------- TRYING LOAD GAME ----------\n";
#endif
	// Se registran los componentes
	try {
		ComponenteRegistro::ComponenteRegistro<ExitOnPlay>("exitOnPlay");
		ComponenteRegistro::ComponenteRegistro<Jugador>("jugador");
		ComponenteRegistro::ComponenteRegistro<LookatMouse>("lookatMouse");
		ComponenteRegistro::ComponenteRegistro<MoveBullet>("moveBullet");
		ComponenteRegistro::ComponenteRegistro<MuteCross>("muteCross");
		ComponenteRegistro::ComponenteRegistro<RoundText>("roundText");
		ComponenteRegistro::ComponenteRegistro<SaveRecord>("saveRecord");
		ComponenteRegistro::ComponenteRegistro<ScoreInGameText>("scoreInGameText");
		ComponenteRegistro::ComponenteRegistro<ScoreTextComponent>("scoreText");
		ComponenteRegistro::ComponenteRegistro<Shoot>("shoot");
		ComponenteRegistro::ComponenteRegistro<SpawnZombis>("spawnZombis");
		ComponenteRegistro::ComponenteRegistro<ZombieMove>("zombieMove");
	}
	catch (...) {
		std::cerr << "ERROR CARGANDO LOS COMPONENTES DEL JUEGO\n";
	}

#if (defined _DEBUG)
	std::cout << "---------- GAME COMPONENTES CARGADOS ----------\n";
#endif

	// Se crea el game manager, lo cual arranca el menu principal
	GameManager::Init();

#if (defined _DEBUG)
	std::cout << "---------- GAME MANAGER CORRECTLY ----------\n";
#endif
	return 0;
}

void deleteGame()
{
	if (GameManager::GetInstance()) delete GameManager::GetInstance();
}
