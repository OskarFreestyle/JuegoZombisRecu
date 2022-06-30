#pragma once
#include "Componente.h"

const int NUM_MAXRECORDS = 5;
const int LONG_NAME = 3;

// Componente para guardar el record
class SaveRecord : public Componente
{
public:
	SaveRecord() {};
	~SaveRecord();
	bool init(const std::map<std::string, std::string>& mapa) override;
	void update();

private:
	std::pair<std::string, int>_p;
	//std::string name;
	std::string _recordsFileName;
	// Almacena los records leidos del fichero
	std::vector<std::pair<std::string, int>> _maxPoints;
	bool _keyUse = false;

	void readRecordsFile();
	bool compYOrdMaxPoints(std::pair<std::string, int>p);
	void writeRecordsFile();
};

