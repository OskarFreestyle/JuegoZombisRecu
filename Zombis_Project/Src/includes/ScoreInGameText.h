#pragma once
#include "Componente.h"

class ScoreInGameText :public Componente
{
public:
	ScoreInGameText() {};
	~ScoreInGameText();
	bool init(const std::map<std::string, std::string>& mapa) override;
	std::string getTexto();
	std::string getTextoIni();

	void setTexto(const std::string& s);


private:
	float posX;
	float posY;
	std::string texto;
	std::string textoIni;
	std::string nombreTexto;
	float tamLetra;
	std::string nombrePanel;
	float dimX;
	float dimY;
	std::string color;//Solo puede ser Red o Black
};

