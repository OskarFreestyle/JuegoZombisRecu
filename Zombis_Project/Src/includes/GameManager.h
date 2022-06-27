#pragma once

const int INIT_LIVES = 3;

class GameManager {
public:
	// Tipos de escenas en las que podemos encontrarnos
	typedef enum class GameScene {
		MAIN_MENU, PLAY_SCENE, PAUSE, OPTIONS, END_SCENE 
	} GameScene;

	~GameManager() {}

	/// <summary>
	/// Devuelve una instancia de la clase. La crea si no existe.
	/// </summary>
	static GameManager* GetInstance();

	/// <summary>
	/// Inicializa la clase GameManager con los parametros dados si no se ha inicializado antes.
	/// Devuelve true si se inicializa por primera vez y false si ya hab�a sido inicializada.
	/// </summary>
	static bool Init();

	// Getters
	inline int getLives() const { return _lives; }
	inline int getPoints() const { return _points; }
	inline int getLastGamePoints() const { return _lastGamePoints; }
	inline int getRound()const { return _round; }

	// Setters
	void setLives(const int l) { _lives = l; }
	void setPoints(const int p) { _points = p; }
	void setLastGamePoints(const int p) { _lastGamePoints = p; }

	// Other functions
	void removeLive();
	void onZombieKilled();
	void increaseNumZombies();

protected:
	static GameManager* _singleton;

	GameManager();

private:
	// Rounds
	int _round = 1;
	int _lastGameRound = 1;

	// Current points during the game
	int _points = 0;

	// Points at the end of the game
	int _lastGamePoints = 0;

	// Current lives during the game
	int _lives = INIT_LIVES;

	int _zombiesSpawnThisRound = 0;
	int _zombiesKilledThisRound = 0;
	int _maxRoundZombies = 2;

	// Current zombis killed during the game 
	int _zombiesKilled = 0;

	// Zombis killed at the end of the game
	int _lastGameZombiesKilled = 0;

	GameScene currScene;
};