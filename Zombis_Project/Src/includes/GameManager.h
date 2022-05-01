#pragma once

class GameManager {
public:
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

	void initGame();


	// Funciones de puntos
	void updatePointsText();
	int getPoints();
	void setPoints(int totalPoints);
	void addPoints(int pointsToAdd);

protected:
	static GameManager* _singleton;

	int points = 9999;
};