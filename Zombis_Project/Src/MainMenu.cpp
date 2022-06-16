#include "MainMenu.h"
#include "utils\Singleton.h"
#include "OverlayManager.h"
#include <Motor.h>
#include "Options.h"
#include "LuaReader.h"
#include "LoadResources.h"
#include "GameManager.h"
#include "AudioManager.h"

MainMenu::MainMenu() {
	// Pone la foto de fondo
	Singleton<OverlayManager>::instance()->creaPanel(0.0f, 0.0f, "MainMenuBGPanel", "MainMenuBG", 1.0f, 1.0f);

	// Crea los botones de la escena
	readFileMenus(Singleton<LoadResources>::instance()->scene("MainMenuScene.lua" ), "GetMainMenu");
	Singleton<OverlayManager>::instance()->setCallBackToButton("NewGamePanel", newGame);
	Singleton<OverlayManager>::instance()->setCallBackToButton("OptionsPanel", option);
	Singleton<OverlayManager>::instance()->setCallBackToButton("ExitPanel", exit);

#if (defined _DEBUG)
	std::cout << "MAIN MENU CORRECTO\n";
#endif
}

MainMenu::~MainMenu()
{
}

void MainMenu::newGame(Motor* m)
{
	Singleton<OverlayManager>::instance()->clear();
	AudioManager::GetInstance()->playMusic(1, false);

	readFile(Singleton<LoadResources>::instance()->scene("PlayScene.lua"));

	GameManager::GetInstance()->initGame();
}

void MainMenu::option(Motor* m)
{
	Singleton<OverlayManager>::instance()->clear();
	AudioManager::GetInstance()->playMusic(1, false);
	Options* o = new Options();
}

void MainMenu::exit(Motor* m)
{
	Singleton<OverlayManager>::instance()->getMotor()->setStop(true);
	AudioManager::GetInstance()->playMusic(1, false);
}
