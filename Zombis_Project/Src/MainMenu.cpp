#include "MainMenu.h"
#include "OverlayManager.h"
#include <Motor.h>
#include "Options.h"
#include "LuaReader.h"
#include "LoadResources.h"
#include "GameManager.h"
#include "AudioManager.h"

MainMenu::MainMenu() {
	
	// Pone la foto de fondo
	OverlayManager::GetInstance()->creaPanel(0.0f, 0.0f, "MainMenuBGPanel", "MainMenuBG", 1.0f, 1.0f);
	// Crea los botones de la escena
	LuaReader::GetInstance()->readFileMenus(LoadResources::GetInstance()->scene("MainMenuScene.lua" ), "GetMainMenu");
	//OverlayManager::GetInstance()->setCallBackToButton("NewGamePanel", newGame);
	//OverlayManager::GetInstance()->setCallBackToButton("OptionsPanel", option);
	//OverlayManager::GetInstance()->setCallBackToButton("ExitPanel", exit);

#if (defined _DEBUG)
	std::cout << "MAIN MENU CORRECTO\n";
#endif
}

MainMenu::~MainMenu()
{
}

/*void MainMenu::newGame(Motor* m)
{
	OverlayManager::GetInstance()->clear();
	AudioManager::GetInstance()->playMusic(1, false);

	LuaReader::GetInstance()->readFile(LoadResources::GetInstance()->scene("PlayScene.lua"));

	GameManager::GetInstance()->initGame();
}

void MainMenu::option(Motor* m)
{
	OverlayManager::GetInstance()->clear();
	AudioManager::GetInstance()->playMusic(1, false);
	Options* o = new Options();
}

void MainMenu::exit(Motor* m)
{
	OverlayManager::GetInstance()->getMotor()->setStop(true);
	AudioManager::GetInstance()->playMusic(1, false);
}*/
