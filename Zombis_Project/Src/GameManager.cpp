#include "GameManager.h"
#include "OverlayManager.h"
#include <string>
#include "SceneManager.h"
#include "Entidad.h"

GameManager* GameManager::_singleton = nullptr;

GameManager* GameManager::GetInstance() {
	return _singleton;
}

bool GameManager::Init() {
	if (_singleton != nullptr) return false;

	_singleton = new GameManager(); 
	return true;
}

GameManager::GameManager()
{
	//currScene = GameScene::MAIN_MENU;

	// Inicia el juego en el menu principal
	SceneManager::GetInstance()->newScene("NewMainMenu.lua");
	_points = 0;
	_lastGamePoints = 0;
	_zombiesKilled = 0;
	_lastGameZombiesKilled = 0;
	_lives = INIT_LIVES;
}

void GameManager::removeLive()
{
	_lives--;
	std::cout << "Te quedan " << _lives << " vidas\n";

	// Si te quedas sin vidas
	if (_lives <= 0) {
		// Guarda los puntos
		_lastGamePoints = _points;
		_points = 0;

		// Guarda los zombis muertos
		_lastGameZombiesKilled = _zombiesKilled;
		_zombiesKilled = 0;

		// Reinicia las vidas
		_lives = INIT_LIVES;

		// Cambia a la escena post-game
		SceneManager::GetInstance()->newScene("newEndState.lua");
	}
}
