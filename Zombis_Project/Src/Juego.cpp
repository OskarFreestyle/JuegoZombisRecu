#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include "Juego.h"

#include <iostream>
#include "Motor.h"
#include "Juego.h"
#include "Entidad.h"
#include "EntidadManager.h"

// Simulación de la función de carga
int LoadGame() {
	std::cout << "TRYING LOAD GAME\n";
	AnotherFunction();
	CreateEntity();
	FuncionSinC();
	std::cout << "GAME LOAD CORRECTLY\n";
	return 0;
}

int AnotherFunction() {
	std::cout << "ANOTHER FUNCTION READ\n";
	return 0;
}

// Prueba con el código del Motor
void CreateEntity() {
	//Entidad* ent = new Entidad();
	//EntidadManager* man = new EntidadManager();
	//ent->setEntityMngr(man);

	std::cout << "ENTITY CREATED\n";
}

void FuncionSinC()
{
	std::cout << "No hace falta extern C\n";
}
