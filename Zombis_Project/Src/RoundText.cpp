#include "RoundText.h"
#include "GameManager.h"


RoundText::~RoundText()
{
}

bool RoundText::init(const std::map<std::string, std::string>& mapa)
{
	TextComponent::init(mapa);
	setTexto ( getTexto()+std::to_string(GameManager::GetInstance()->getRound()));


	_inicializado = true;

	return _inicializado;
}

std::string RoundText::getTexto()
{
	return TextComponent::getTexto();
}

std::string RoundText::getTextoIni()
{
	return TextComponent::getTextoIni();
}



void RoundText::setTexto(const std::string& s)
{
	TextComponent::setTexto(s);
}


