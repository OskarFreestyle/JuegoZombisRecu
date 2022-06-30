#include "ScoreTextComponent.h"
#include "GameManager.h"


ScoreTextComponent::~ScoreTextComponent()
{
}

bool ScoreTextComponent::init(const std::map<std::string, std::string>& mapa)
{
	TextComponent::init(mapa);
	setTexto(getTextoIni() + std::to_string(GameManager::GetInstance()->getLastGamePoints()));

	_inicializado = true;

	return _inicializado;
}

std::string ScoreTextComponent::getTexto()
{
	return TextComponent::getTexto();
}



void ScoreTextComponent::setTexto(const std::string& s)
{
	TextComponent::setTexto(s);
}


