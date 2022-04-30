#include "MainMenu.h"
#include "utils\Singleton.h"
#include "OverlayManager.h"
#include <Motor.h>
#include "Options.h"
#include "LuaReader.h"
#include "LoadResources.h"

MainMenu::MainMenu() {
	readFileMenus(Singleton<LoadResources>::instance()->scene("MainMenuScene.lua" ), "GetMainMenu");
	Singleton<OverlayManager>::instance()->setCallBackToButton("NewGamePanel", newGame);
	Singleton<OverlayManager>::instance()->setCallBackToButton("OptionsPanel", option);
	Singleton<OverlayManager>::instance()->setCallBackToButton("ExitPanel", exit);
	//std::cout << Singleton<OverlayManager>::instance()->getMotor()<<std::endl;
}

MainMenu::~MainMenu()
{
	/*if (o != nullptr) {
		delete o;
		o = nullptr;
	}*/
}
void MainMenu::newGame(Motor* m)
{
	//Singleton<OverlayManager>::close();
	Singleton<OverlayManager>::instance()->clear();
	readFile(Singleton<LoadResources>::instance()->scene("TestScene.lua"));
}

void MainMenu::option(Motor* m)
{
	//Singleton<OverlayManager>::close();
	Singleton<OverlayManager>::instance()->clear();
	//Singleton<OverlayManager>::instance()->getMotor()->loadMenu("Options.lua","GetOptions");
	Options* o = new Options();

}
void MainMenu::exit(Motor* m)
{
	Singleton<OverlayManager>::instance()->getMotor()->setStop(true);
}
