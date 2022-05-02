#pragma once
class OverlayManager;
class Motor;
class MainMenu;
class LuaReader;
class LoadResources;
class GameManager;
using CallBackOnClick = void(Motor* m);
class EndState
{
private:
	static void backToMenu(Motor* m);
public:
	EndState();
	~EndState();
};

