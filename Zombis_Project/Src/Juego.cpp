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


void RegistryGameComponents() {
	// Ejemplo
	//ComponenteRegistro::ComponenteRegistro<Mesh>("mesh");
	ComponenteRegistro::ComponenteRegistro<LookatMouse>("lookatmouse");


	std::cout << "GAME COMPONENTS REGISTRY CORRECTLY\n";
}

// Simulación de la función de carga
int LoadGame() {
	std::cout << "TRYING LOAD GAME\n";

	// Se registran los componentes
	RegistryGameComponents();
	std::cout << Singleton<EntidadManager>::instance() << std::endl;


	std::cout << "GAME LOAD CORRECTLY\n";
	return 0;
}