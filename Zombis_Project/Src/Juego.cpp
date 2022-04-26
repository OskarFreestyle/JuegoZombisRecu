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

extern EntidadManager* en = Singleton<EntidadManager>::instance();

void RegistryGameComponents() {
	// Ejemplo
	//ComponenteRegistro::ComponenteRegistro<Mesh>("mesh");
	ComponenteRegistro::ComponenteRegistro<LookatMouse>("lookatmouse");

	ComponenteRegistro::ComponenteRegistro<GrafoConObstaculos>("grafoObstaculo");

	std::cout << "GAME COMPONENTS REGISTRY CORRECTLY\n";
}

// Simulación de la función de carga
int LoadGame() {
	std::cout << "TRYING LOAD GAME\n";

	// Se registran los componentes
	RegistryGameComponents();
	std::cout << "-------" << en << std::endl;

	std::cout << "GAME LOAD CORRECTLY\n";
	return 0;
}