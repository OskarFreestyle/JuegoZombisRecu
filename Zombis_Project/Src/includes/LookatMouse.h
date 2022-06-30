#pragma once
#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#include "Componente.h"


class Transform;

// Intenta hacer que se mire al ratón
class LookatMouse : public Componente
{
public:
	LookatMouse();
	virtual ~LookatMouse();

	bool init(const std::map<std::string, std::string>& mapa);

	void rotateToMouse2D();
	void init() {};
	void update();

private:
	bool _test;
	std::pair<double, double> MP;
	Transform *_transform;
	double _angle = 0;
};
