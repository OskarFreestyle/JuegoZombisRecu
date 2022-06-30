#pragma once
#include "TextComponent.h"

// Muestra los puntos al acabar la partida
class ScoreTextComponent : public TextComponent
{
public:
	ScoreTextComponent() {};
	~ScoreTextComponent();
	bool init(const std::map<std::string, std::string>& mapa) override;
	std::string getTexto();
	
	void setTexto(const std::string& s);
};

