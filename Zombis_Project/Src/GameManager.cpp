#include "GameManager.h"
#include "OverlayManager.h"
#include <string>
#include "SceneManager.h"
#include "Entidad.h"
#include "SpawnZombis.h"
#include "ImageComponent.h"

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
	// Inicia el juego en el menu principal
	//SceneManager::GetInstance()->newScene("NewMainMenu.lua");
	SceneManager::GetInstance()->newScene("PruebaVacia.lua");
	_points = 0;
	_lastGamePoints = 0;
	_zombiesKilled = 0;
	_lastGameZombiesKilled = 0;
	_lives = INIT_LIVES;
	_round = 0;
}

void GameManager::removeLive()
{
	SceneManager::GetInstance()->getEntityByName("Heart" + std::to_string(_lives))->getComponent<ImageComponent>()->setActive(false);

	_lives--;
	std::cout << "Te quedan " << _lives << " vidas\n";

	// Si te quedas sin vidas
	if (_lives <= 0) {
		// Guarda la ronda a la que se llegó
		_lastGameRound = _round;
		_round = 1;

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

void GameManager::onZombieKilled()
{
	// Se aumenta en 1 el numero de zombis que se matan
	_zombiesKilled++;
	_zombiesKilledThisRound++;
	// Feisimo
	_points += 10;

	if (_zombiesKilledThisRound >= _maxRoundZombies) {
		// Busca el SpawnZombies y lo vuelve a activar
		SceneManager::GetInstance()->getEntityByName("SpanwZombies")->getComponent<SpawnZombis>()->setActive(true);
		_maxRoundZombies += 2;
		_zombiesKilledThisRound = 0;
		_zombiesSpawnThisRound = 0;
		_round++;
	}
}

void GameManager::increaseNumZombies()
{
	// Incrementa en 1 el numero de zombis esta ronda
	_zombiesSpawnThisRound++;

	// Si ya han spawneado todos los zombis de esta ronda devuelve true y pausa el spawn
	if (_zombiesSpawnThisRound >= _maxRoundZombies) {
		SceneManager::GetInstance()->getEntityByName("SpanwZombies")->getComponent<SpawnZombis>()->setActive(false);
	}
}
