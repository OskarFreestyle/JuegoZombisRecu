#pragma once
#ifdef JUEGO_EXPORTS
#define JUEGO_API __declspec(dllexport)
#else
#define JUEGO_API __declspec(dllimport)
#endif

/// <summary>
/// FUNCIÓN PRINCIPAL PARA CARGAR EL JUEGO
/// </summary>
int LoadGame();

/// <summary>
/// Aquí se registran los componentes únicos de cada juego que por tanto no conoce el motor
/// </summary>
void RegistryGameComponents();

