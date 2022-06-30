#pragma once
#include "Componente.h"

const int NUM_MAXRECORDS = 5;
const int LONG_NAME = 3;

class SaveRecord : public Componente
{
public:
	SaveRecord() {};
	~SaveRecord();
	bool init(const std::map<std::string, std::string>& mapa) override;
	void update();

private:
	std::pair<std::string, int>p;
	//std::string name;
	std::string recordsFileName;
	// Almacena los records leidos del fichero
	std::vector<std::pair<std::string, int>> maxPoints;
	bool keyUse = false;

	void readFile();
	bool compYOrdMaxPoints(std::pair<std::string, int>p);
	void writeFile();
};

