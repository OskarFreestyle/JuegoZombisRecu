#pragma once
#include "Componente.h"

class ScoreTextComponent :public Componente
{
public:
	ScoreTextComponent() {};
	~ScoreTextComponent();
	bool init(const std::map<std::string, std::string>& mapa) override;
	std::string getTexto();
	void setTexto(const std::string& s, const std::string& textName, const std::string& panelName);


private:
	float posX;
	float posY;
	std::string texto;
	std::string nombreTexto;
	float tamLetra;
	std::string nombrePanel;
	float dimX;
	float dimY;
	std::string color;//Solo puede ser Red o Black
};

