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

#include "Bala.h"
#include "MoveBullet.h"


void RegistryGameComponents() {
	// Ejemplo
	//ComponenteRegistro::ComponenteRegistro<Mesh>("mesh");
	//ComponenteRegistro::ComponenteRegistro<LookatMouse>("lookatmouse");

	//ComponenteRegistro::ComponenteRegistro<GrafoConObstaculos>("grafoObstaculo");
	ComponenteRegistro::ComponenteRegistro<MoveBullet>("moveBullet");
	

	std::cout << "EM: " << Singleton<EntidadManager>::instance() << "\n";
	std::cout << "LR " << Singleton<LoadResources>::instance() << "\n";
	std::cout << "FMOD: " << Singleton<FMODAudioManager>::instance() << "\n";

	Singleton<EntidadManager>::instance()->addEntidad();

	Singleton<FMODAudioManager>::instance()->loadMusic(0, Singleton<LoadResources>::instance()->aud("blind_shift.mp3").c_str());

	Singleton<FMODAudioManager>::instance()->playMusic(0, true);

	

	std::cout << "GAME COMPONENTS REGISTRY CORRECTLY\n";
}

// Simulación de la función de carga
int LoadGame() {
	std::cout << "TRYING LOAD GAME\n";

	// Se registran los componentes
	RegistryGameComponents();
	MainMenu* m = new MainMenu();
	Bala* b = new Bala();
	b->creaBala();
	

	std::cout << "GAME LOAD CORRECTLY\n";
	return 0;
}