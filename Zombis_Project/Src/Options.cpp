#include "Options.h"
#include "MainMenu.h"
#include "utils\Singleton.h"
#include "OverlayManager.h"
#include <Motor.h>
#include "AudioManager.h"
#include "LuaReader.h"
#include "LoadResources.h"
#include "InputManager.h"

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
	clock_t auxc = clock();
	if (auxc > lastClickVol + TIME_TO_CLICK) {
		lastClickVol = auxc;
		AudioManager::GetInstance()->playMusic(1, false);
		if (AudioManager::GetInstance()->getMute() == false)
			AudioManager::GetInstance()->setMute(true);
		else
			AudioManager::GetInstance()->setMute(false);
	}
}

void Options::backToMenu(Motor* m)
{
	Singleton<OverlayManager>::instance()->clear();
	AudioManager::GetInstance()->playMusic(1, false);
	MainMenu* mainMenu = new MainMenu();
}
