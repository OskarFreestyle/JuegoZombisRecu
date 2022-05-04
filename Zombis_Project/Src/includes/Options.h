#pragma once
#include <time.h>
class OverlayManager;
class Motor;
class MainMenu;
class FMODAudioManager;
class LuaReader;
class LoadResources;
using CallBackOnClick = void(Motor* m);

typedef long clock_t;


class Options
{
	

private:
	inline static clock_t lastClickVol = 0;
	static void volume(Motor* m);
	static void backToMenu(Motor* m);
public :
	Options();
	~Options();
};

