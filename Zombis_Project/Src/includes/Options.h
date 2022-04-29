#pragma once
class OverlayManager;
class Motor;
class MainMenu;
class FMODAudioManager;
using CallBackOnClick = void(Motor* m);
class Options
{
private:
	static void volume(Motor* m);
	static void backToMenu(Motor* m);
public :
	Options();
	~Options();
};

