#include "Options.h"
#include "MainMenu.h"
#include "utils\Singleton.h"
#include "OverlayManager.h"
#include <Motor.h>
#include "FMODAudioManager.h"
#include "LuaReader.h"
#include "LoadResources.h"
#include "InputManager.h"


const clock_t TIME_TO_CLICK = 500;

Options::Options()
{
	readFileMenus(Singleton<LoadResources>::instance()->scene("Options.lua"), "GetOptions");
	Singleton<OverlayManager>::instance()->setCallBackToButton("VolumePanel", volume);
	Singleton<OverlayManager>::instance()->setCallBackToButton("ReturnPanel", backToMenu);

}

Options::~Options()
{
}
void Options::volume(Motor* m)
{
	clock_t auxc = clock();
	if (auxc > lastClickVol + TIME_TO_CLICK) {

		lastClickVol = auxc;
		Singleton<FMODAudioManager>::instance()->playMusic(1, false);
		if (Singleton<FMODAudioManager>::instance()->getMute() == false)
			Singleton<FMODAudioManager>::instance()->setMute(true);
		else
			Singleton<FMODAudioManager>::instance()->setMute(false);
	}
	
	
}

void Options::backToMenu(Motor* m)
{
	Singleton<OverlayManager>::instance()->clear();
	Singleton<FMODAudioManager>::instance()->playMusic(1, false);
	//Singleton<OverlayManager>::instance()->getMotor()->loadMenu("Options.lua","GetOptions");
	MainMenu* mainMenu = new MainMenu();
}
