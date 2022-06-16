#include "Options.h"
#include "MainMenu.h"
#include "OverlayManager.h"
#include <Motor.h>
#include "AudioManager.h"
#include "LuaReader.h"
#include "LoadResources.h"
#include "InputManager.h"

Options::Options()
{
	// Pone la foto de fondo
	OverlayManager::GetInstance()->creaPanel(0.0f, 0.0f, "OptionsBGPanel", "OptionsMenuBG", 1.0f, 1.0f);

	readFileMenus(LoadResources::GetInstance()->scene("Options.lua"), "GetOptions");

	OverlayManager::GetInstance()->setCallBackToButton("VolumePanel", volume);
	OverlayManager::GetInstance()->setCallBackToButton("ReturnPanel", backToMenu);
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
	OverlayManager::GetInstance()->clear();
	AudioManager::GetInstance()->playMusic(1, false);
	MainMenu* mainMenu = new MainMenu();
}
