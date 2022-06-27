#include "GameManager.h"
#include "OverlayManager.h"
#include <string>
#include "SceneManager.h"
#include "Entidad.h"
#include "SpawnZombis.h"
#include "ImageComponent.h"
#include "ScoreInGameText.h"
#include "RoundText.h"
#include "AudioSource.h"
#include "AudioManager.h"

// Componentes del juego


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
	SceneManager::GetInstance()->newScene("MainMenuScene.lua");
	
	_points = 0;
	_lastGamePoints = 0;
	_zombiesKilled = 0;
	_lastGameZombiesKilled = 0;
	_lives = INIT_LIVES;
	_round = 1;
}

void GameManager::removeLive()
{
	SceneManager::GetInstance()->getEntityByName("Heart" + std::to_string(_lives))->getComponent<ImageComponent>()->setActive(false);

	_lives--;

	SceneManager::GetInstance()->getEntityByName("SpanwZombies")->getComponent<AudioSource>()->play();

	// Si te quedas sin vidas
	if (_lives <= 0) {
		// Actualiza las variables al terminar el juego
		onFinishGame();

		// Cambia a la escena post-game
		SceneManager::GetInstance()->newScene("EndScene.lua");
	}
}

void GameManager::onZombieKilled(int pointsToAdd)
{
	// Se aumenta en 1 el numero de zombis que se matan
	_zombiesKilled++;
	_zombiesKilledThisRound++;

	// Se añaden los puntos correspondientes segun el tipo de zombie
	_points += pointsToAdd;
	_lastGamePoints = _points;

	Entidad* e = SceneManager::GetInstance()->getEntityByName("Score");
	if (e) e->getComponent<ScoreInGameText>()->setTexto(e->getComponent<ScoreInGameText>()->getTextoIni() + std::to_string(_points), "ScoreText", "ScorePanel");

	// Cuando se pasa una ronda
	if (_zombiesKilledThisRound >= _maxRoundZombies) {
		_round++;
		_zombiesKilledThisRound = 0;
		_zombiesSpawnThisRound = 0;

		// Busca el SpawnZombies y lo vuelve a activar
		SceneManager::GetInstance()->getEntityByName("SpanwZombies")->getComponent<SpawnZombis>()->setActive(true);

		// Calcula los zombies de la nueva ronda 
		_maxRoundZombies = calculateZombies();

		// Actualiza el texto de la ronda
		Entidad* e = SceneManager::GetInstance()->getEntityByName("Round");
		if (e) e->getComponent<RoundText>()->setTexto(e->getComponent<RoundText>()->getTextoIni() + std::to_string(_round), "RoundText", "RoundPanel");
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

void GameManager::onFinishGame()
{
	// Guarda la ronda a la que se llegó
	_lastGameRound = _round;
	_round = 1;

	// Guarda los puntos
	_lastGamePoints = _points;
	_points = 0;

	// Guarda los zombis muertos
	_lastGameZombiesKilled = _zombiesKilled;
	_zombiesKilled = 0;
	_maxRoundZombies = calculateZombies();
	_zombiesKilledThisRound = 0;
	_zombiesSpawnThisRound = 0;

	// Reinicia las vidas
	_lives = INIT_LIVES;
	AudioManager::GetInstance()->stopAllChannels();
}

// Similar a Fibonacci
int GameManager::calculateZombies()
{
	int a = 1;
	int b = 1;
	int c = 2;

	for (int i = 1; i <= _round; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}

	std::cout << "ZOMBIES num: " << c << "\n";

	return c;
}
