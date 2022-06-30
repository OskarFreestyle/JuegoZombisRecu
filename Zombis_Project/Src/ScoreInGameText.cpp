#include "ScoreInGameText.h"
#include "OverlayManager.h"
#include "GameManager.h"


ScoreInGameText::~ScoreInGameText()
{
}

bool ScoreInGameText::init(const std::map<std::string, std::string>& mapa)
{
	if (mapa.find("positionX") == mapa.end() || mapa.find("positionY") == mapa.end() || mapa.find("texto") == mapa.end() || mapa.find("nombreTexto") == mapa.end() ||
		mapa.find("tamLetra") == mapa.end() || mapa.find("nombrePanel") == mapa.end() || mapa.find("dimensionX") == mapa.end() || mapa.find("dimensionY") == mapa.end() ||
		mapa.find("color") == mapa.end()) return false;

	std::string s = mapa.at("positionX");
	posX = std::stof(s);
	s = mapa.at("positionY");
	posY = std::stof(s);

	s = mapa.at("texto");
	texto = s;
	textoIni = texto;

	s = mapa.at("nombreTexto");
	nombreTexto = s;
	s = mapa.at("tamLetra");
	tamLetra = std::stof(s);
	s = mapa.at("nombrePanel");
	nombrePanel = s;

	s = mapa.at("dimensionX");
	dimX = std::stof(s);
	s = mapa.at("dimensionY");
	dimY = std::stof(s);
	s = mapa.at("color");
	color = s;

	texto += std::to_string(GameManager::GetInstance()->getPoints());

	OverlayManager::GetInstance()->creaTexto(posX, posY, texto, nombreTexto, tamLetra, nombrePanel, dimX, dimY);
	OverlayManager::GetInstance()->changeTextColor(nombrePanel, nombreTexto, color);

	_inicializado = true;

	return _inicializado;
}

std::string ScoreInGameText::getTexto()
{
	return texto;
}

std::string ScoreInGameText::getTextoIni()
{
	return textoIni;
}

void ScoreInGameText::setTexto(const std::string& s, const std::string& textName, const std::string& panelName)
{
	texto = s;
	Ogre::TextAreaOverlayElement* t = OverlayManager::GetInstance()->getTexto(panelName, textName);
	if (t != nullptr)t->setCaption(texto);
}


