#pragma once
#include "Componente.h"
#include <SDL.h>

class InputManager;

class LookatMouse : public Componente
{
public:
	LookatMouse();
	virtual ~LookatMouse();

	bool init(const std::map<std::string, std::string>& mapa);

	void debugMousePos();
	void rotateToMouse2D();
	void init() {};
	void update();


private:
	bool test;
	std::pair<double, double> MP;
};
