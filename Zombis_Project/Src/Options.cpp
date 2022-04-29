#include "Options.h"
#include "MainMenu.h"
#include "utils\Singleton.h"
#include "OverlayManager.h"
#include <Motor.h>
#include "FMODAudioManager.h"


Options::Options()
{
	Singleton<OverlayManager>::instance()->getMotor()->loadMenu("Options.lua", "GetOptions");
	Singleton<OverlayManager>::instance()->setCallBackToButton("VolumePanel", volume);
	Singleton<OverlayManager>::instance()->setCallBackToButton("ReturnPanel", backToMenu);
}

Options::~Options()
{
}
void Options::volume(Motor* m)
{
	if(Singleton<FMODAudioManager>::instance()->getMute() == false)
		Singleton<FMODAudioManager>::instance()->setMute(true);
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
	//Singleton<OverlayManager>::instance()->getMotor()->loadMenu("Options.lua","GetOptions");
	MainMenu* mainMenu = new MainMenu();
}
