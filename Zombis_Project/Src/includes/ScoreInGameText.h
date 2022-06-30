#pragma once
#include "TextComponent.h"

class ScoreInGameText :public TextComponent
{
public:
	ScoreInGameText() {};
	~ScoreInGameText();
	bool init(const std::map<std::string, std::string>& mapa) override;
	std::string getTexto();
	std::string getTextoIni();

	void setTexto(const std::string& s);
};

