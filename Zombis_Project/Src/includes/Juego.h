#pragma once
#ifdef JUEGO_EXPORTS
#define JUEGO_API __declspec(dllexport)
#else
#define JUEGO_API __declspec(dllimport)
#endif

/// <summary>
/// FUNCI�N PRINCIPAL PARA CARGAR EL JUEGO, LOS JUEGOS NECESITAR�N ESTA FUNCION OBLIGATORIAMENTE PARA QUE EL MOTOR PUEDA LLAMAR A LA LIBRER�A DIN�MICA
/// </summary>
extern "C" JUEGO_API int LoadGame();
extern "C" JUEGO_API void deleteGame();



