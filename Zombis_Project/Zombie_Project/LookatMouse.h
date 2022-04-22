#pragma once
#include "Componente.h"
#include "SDL.h"

class LookatMouse : public Componente
{
public:
	LookatMouse();
	virtual ~LookatMouse();

	bool init(const std::map<std::string, std::string>& mapa);

	std::pair<int, int> returnMousePos();
	//deberiamos girar al padre cada frame para orientarlo
	void debugMousePos() { std::cout << mouseX << " " << mouseY; };
private:
	int mouseX, mouseY;
	SDL_Event e;
};

