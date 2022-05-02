#include "GameManager.h"
#include "OverlayManager.h"
#include <string>

GameManager* GameManager::_singleton = nullptr;

GameManager* GameManager::GetInstance() {
	return _singleton;
}

bool GameManager::Init() {
	if (_singleton != nullptr) return false;
	_singleton = new GameManager(); return true;
}

void GameManager::initGame()
{	
	// Crea un texto de puntuacion y un fondo
	Singleton<OverlayManager>::instance()->creaPanel(0, 0, "PuntosPanel", "Blanco", 0.25f, 0.08f);
	Singleton<OverlayManager>::instance()->creaTexto(0.0f, -0.08f, "POINTS:", "PuntosTexto", 0.05f, "PuntosTextoPanel",0.25,0.25);

	// Guarda el texto de puntuacion para que luego sea más facil obtenerlo
	Ogre::TextAreaOverlayElement* p = Singleton<OverlayManager>::instance()->getTexto("PuntosTextoPanel", "PuntosTexto");

	// Si encuentra el texto
	if (p != nullptr) p->setCaption("POINTS: " + std::to_string(points));

}

int GameManager::getPoints()
{
	return points;
}

void GameManager::updatePointsText()
{
	Ogre::TextAreaOverlayElement* p = Singleton<OverlayManager>::instance()->getTexto("PuntosTextoPanel", "PuntosTexto");
	if (p != nullptr) p->setCaption("POINTS: " + std::to_string(points));
}

void GameManager::setPoints(int totalPoints)
{
	points = totalPoints;
	updatePointsText();
}

void GameManager::addPoints(int pointsToAdd)
{
	points += pointsToAdd;
	updatePointsText();
}

