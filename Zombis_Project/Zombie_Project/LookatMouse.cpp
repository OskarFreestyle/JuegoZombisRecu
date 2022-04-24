#include "LookatMouse.h"

LookatMouse::LookatMouse() :
	mouseX(0), mouseY(0), e(SDL_Event())
{
}

LookatMouse::~LookatMouse()
{
}

bool LookatMouse::init(const std::map<std::string, std::string>& mapa)
{
	return false;
}

std::pair<int, int> LookatMouse::returnMousePos()
{
	//SDL_GetGlobalMouseState(&mouseX, &mouseY);
	return std::pair<int, int>(mouseX, mouseY);
}
