#include "ScoreInGameText.h"
#include "GameManager.h"


ScoreInGameText::~ScoreInGameText()
{
}

bool ScoreInGameText::init(const std::map<std::string, std::string>& mapa)
{
	TextComponent::init(mapa);
	setTexto(getTextoIni() + std::to_string(GameManager::GetInstance()->getPoints()));

	_inicializado = true;

	return _inicializado;
}

std::string ScoreInGameText::getTexto()
{
	return TextComponent::getTexto();
}

std::string ScoreInGameText::getTextoIni()
{
	return TextComponent::getTextoIni();
}

void ScoreInGameText::setTexto(const std::string& s)
{
	TextComponent::setTexto(s);
}


