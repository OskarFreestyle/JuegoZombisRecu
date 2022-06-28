#include "ExitOnPlay.h"
#include "GameManager.h"

ExitOnPlay::~ExitOnPlay()
{

}

bool ExitOnPlay::init(const std::map<std::string, std::string>& mapa)
{
	// Se inicia igual que cualquier boton
	return Button::init(mapa);
}

void ExitOnPlay::onClick()
{
	GameManager::GetInstance()->onFinishGame();
	Button::onClick();
}
