#include "Options.h"
#include "MainMenu.h"
#include "utils\Singleton.h"
#include "OverlayManager.h"
#include <Motor.h>
#include "FMODAudioManager.h"
#include "LuaReader.h"
#include "LoadResources.h"


Options::Options()
{
	// Pone la foto de fondo
	Singleton<OverlayManager>::instance()->creaPanel(0.0f, 0.0f, "OptionsBGPanel", "OptionsMenuBG", 1.0f, 1.0f);

	readFileMenus(Singleton<LoadResources>::instance()->scene("Options.lua"), "GetOptions");

	Singleton<OverlayManager>::instance()->setCallBackToButton("VolumePanel", volume);
	Singleton<OverlayManager>::instance()->setCallBackToButton("ReturnPanel", backToMenu);
}

Options::~Options()
{
}

void Options::volume(Motor* m)
{
	Singleton<FMODAudioManager>::instance()->playMusic(1, false);
	if (Singleton<FMODAudioManager>::instance()->getMute() == false) {
		Singleton<FMODAudioManager>::instance()->setMute(true);
		Singleton<OverlayManager>::instance()->changeTextColor("", "ScoreText", "Red");
	}
	else 
		Singleton<FMODAudioManager>::instance()->setMute(false);
	for (int i = 0;i < Singleton<FMODAudioManager>::instance()->getCont();i++) {
		if (Singleton<FMODAudioManager>::instance()->getMute() == false) {
			Singleton<FMODAudioManager>::instance()->setVolume(i, 1);
			

		}
		else {
			Singleton<FMODAudioManager>::instance()->setVolume(i, 0);
			
		}
	}
}

void Options::backToMenu(Motor* m)
{
	Singleton<OverlayManager>::instance()->clear();
	Singleton<FMODAudioManager>::instance()->playMusic(1, false);
	//Singleton<OverlayManager>::instance()->getMotor()->loadMenu("Options.lua","GetOptions");
	MainMenu* mainMenu = new MainMenu();
}
