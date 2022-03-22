#pragma once
#ifdef JUEGO_EXPORTS
#define JUEGO_API __declspec(dllexport)
#else
#define JUEGO_API __declspec(dllimport)
#endif

extern "C" JUEGO_API int LoadGame();
extern "C" JUEGO_API int AnotherFunction();
extern "C" JUEGO_API void CreateEntity();
void FuncionSinC();

