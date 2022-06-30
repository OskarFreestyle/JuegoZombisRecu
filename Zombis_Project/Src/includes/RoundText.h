#pragma once
#include "TextComponent.h"

class RoundText :public TextComponent
{
public:
	RoundText() {};
	~RoundText();
	bool init(const std::map<std::string, std::string>& mapa) override;
	std::string getTexto();
	std::string getTextoIni();

	void setTexto(const std::string& s);

};

