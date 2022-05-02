#include "EndState.h"
#include "utils\Singleton.h"
#include"LuaReader.h"
#include"LoadResources.h"
#include "OverlayManager.h"
#include "MainMenu.h"
#include "GameManager.h"

EndState::EndState()
{
	readFileMenus(Singleton<LoadResources>::instance()->scene("EndScene.lua"), "GetEndScene");
	Singleton<OverlayManager>::instance()->creaTexto(0.25, 0.2, "Your score is: "+std::to_string(GameManager::GetInstance()->getPoints()),"ScoreText", 0.1, "ScorePanel",0.6,0.3);
	Singleton<OverlayManager>::instance()->setCallBackToButton("BackMenuPanel", backToMenu);
}

EndState::~EndState()
{
}
void EndState::backToMenu(Motor* m)
{
	Singleton<OverlayManager>::instance()->clear();
	//Singleton<OverlayManager>::instance()->getMotor()->loadMenu("Options.lua","GetOptions");
	MainMenu* mainMenu = new MainMenu();
}
