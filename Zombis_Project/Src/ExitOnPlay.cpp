#include "ExitOnPlay.h"
#include "GameManager.h"

ExitOnPlay::~ExitOnPlay()
{

}

bool ExitOnPlay::init(const std::map<std::string, std::string>& mapa)
{
	std::cout << "Button Virtual init \n";
	// Se inicia igual que cualquier boton
	return Button::init(mapa);
}

void ExitOnPlay::onClick()
{
	std::cout << "Boton virtual click\n";
	GameManager::GetInstance()->onFinishGame();
	Button::onClick();
}
