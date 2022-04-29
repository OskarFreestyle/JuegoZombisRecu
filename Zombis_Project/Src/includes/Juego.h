#pragma once
#ifdef JUEGO_EXPORTS
#define JUEGO_API __declspec(dllexport)
#else
#define JUEGO_API __declspec(dllimport)
#endif
class MainMenu;

/// <summary>
/// Aquí se registran los componentes únicos de cada juego que por tanto no conoce el motor
/// </summary>
void RegistryGameComponents();

/// <summary>
/// FUNCIÓN PRINCIPAL PARA CARGAR EL JUEGO
/// </summary>
extern "C" JUEGO_API int LoadGame();


