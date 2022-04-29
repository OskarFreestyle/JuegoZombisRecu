#include "MainMenu.h"
#include "utils\Singleton.h"
#include "OverlayManager.h"
#include <Motor.h>

MainMenu::MainMenu() {
	Singleton<OverlayManager>::instance()->getMotor()->loadMenu("MainMenuScene.lua", "GetMainMenu");
	Singleton<OverlayManager>::instance()->setCallBackToButton("NewGamePanel", newGame);
	Singleton<OverlayManager>::instance()->setCallBackToButton("OptionsPanel", options);
	Singleton<OverlayManager>::instance()->setCallBackToButton("ExitPanel", exit);
	std::cout << Singleton<OverlayManager>::instance()->getMotor()<<std::endl;
}

MainMenu::~MainMenu()
{
}
void MainMenu::newGame(Motor* m)
{
	//Singleton<OverlayManager>::close();
	Singleton<OverlayManager>::instance()->clear();
	Singleton<OverlayManager>::instance()->getMotor()->loadScene("TestScene.lua");
}

void MainMenu::options(Motor* m)
{
	//Singleton<OverlayManager>::close();
	Singleton<OverlayManager>::instance()->clear();
	Singleton<OverlayManager>::instance()->getMotor()->loadMenu("Options.lua","GetOptions");
}
void MainMenu::exit(Motor* m)
{
	Singleton<OverlayManager>::instance()->getMotor()->setStop(true);
}
