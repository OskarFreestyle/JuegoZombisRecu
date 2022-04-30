#pragma once
#ifdef JUEGO_EXPORTS
#define JUEGO_API __declspec(dllexport)
#else
#define JUEGO_API __declspec(dllimport)
#endif
class OverlayManager;
class Motor;
class Options;
class LuaReader;
class LoadResources;
using CallBackOnClick = void(Motor* m);
JUEGO_API class MainMenu
{
private:
	static void newGame(Motor* m);
	static void option(Motor* m);
	static void exit(Motor* m);
	
public:
	MainMenu();
	~MainMenu();
};

