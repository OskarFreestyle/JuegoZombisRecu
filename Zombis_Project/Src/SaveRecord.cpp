#include "SaveRecord.h"
#include "GameManager.h"
#include "InputManager.h"
#include "TextComponent.h"
#include "SceneManager.h"


using namespace std;

SaveRecord::~SaveRecord()
{

}

bool SaveRecord::init(const std::map<std::string, std::string>& mapa)
{
	if (mapa.find("recordsFileName") == mapa.end()) return false;

	_recordsFileName = mapa.at("recordsFileName");

	// Lee el archivo de records
	readRecordsFile();
	// Guarda el record actual para compararlo con los demas
	_p.second = GameManager::GetInstance()->getLastGamePoints();
	
	_inicializado = true;

	return _inicializado;
}

void SaveRecord::update() {
	// Queriamos haberte preguntado cuál es la solución para no tener que poner esta ristra de if else en la tutoría
	if (!_keyUse) {
		if (ih().isKeyDown(SDL_SCANCODE_A)) {
			_p.first += "A";
			_keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_B)) {
			_p.first += "B";
			_keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_C)) {
			_p.first += "C";
			_keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_D)) {
			_p.first += "D";
			_keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_E)) {
			_p.first += "E";
			_keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_F)) {
			_p.first += "F";
			_keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_G)) {
			_p.first += "G";
			_keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_H)) {
			_p.first += "H";
			_keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_I)) {
			_p.first += "I";
			_keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_J)) {
			_p.first += "J";
			_keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_K)) {
			_p.first += "K";
			_keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_L)) {
			_p.first += "L";
			_keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_M)) {
			_p.first += "M";
			_keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_N)) {
			_p.first += "N";
			_keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_O)) {
			_p.first += "O";
			_keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_P)) {
			_p.first += "P";
			_keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_Q)) {
			_p.first += "Q";
			_keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_R)) {
			_p.first += "R";
			_keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_S)) {
			_p.first += "S";
			_keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_T)) {
			_p.first += "T";
			_keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_U)) {
			_p.first += "U";
			_keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_V)) {
			_p.first += "V";
			_keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_W)) {
			_p.first += "W";
			_keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_X)) {
			_p.first += "X";
			_keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_Y)) {
			_p.first += "Y";
			_keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_Z)) {
			_p.first += "Z";
			_keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_BACKSPACE)) {
			if(!_p.first.empty()) _p.first.pop_back();
			_keyUse = true;
		}
		Entidad* e = SceneManager::GetInstance()->getEntityByName("SaveRecordText");
		if (e) e->getComponent<TextComponent>()->setTexto("YOUR NAME: " + _p.first);
	}

	if (ih().isKeyUp(SDL_SCANCODE_A) || ih().isKeyUp(SDL_SCANCODE_B) || ih().isKeyUp(SDL_SCANCODE_C) || ih().isKeyUp(SDL_SCANCODE_D) || ih().isKeyUp(SDL_SCANCODE_E) ||
		ih().isKeyUp(SDL_SCANCODE_F) || ih().isKeyUp(SDL_SCANCODE_G) || ih().isKeyUp(SDL_SCANCODE_H) || ih().isKeyUp(SDL_SCANCODE_I) || ih().isKeyUp(SDL_SCANCODE_J) || 
		ih().isKeyUp(SDL_SCANCODE_K) || ih().isKeyUp(SDL_SCANCODE_L) || ih().isKeyUp(SDL_SCANCODE_M) || ih().isKeyUp(SDL_SCANCODE_N) || ih().isKeyUp(SDL_SCANCODE_O) ||
		ih().isKeyUp(SDL_SCANCODE_P) || ih().isKeyUp(SDL_SCANCODE_Q) || ih().isKeyUp(SDL_SCANCODE_R) || ih().isKeyUp(SDL_SCANCODE_S) || ih().isKeyUp(SDL_SCANCODE_T) ||
		ih().isKeyUp(SDL_SCANCODE_U) || ih().isKeyUp(SDL_SCANCODE_V) || ih().isKeyUp(SDL_SCANCODE_W) || ih().isKeyUp(SDL_SCANCODE_X) || ih().isKeyUp(SDL_SCANCODE_Y) ||
		ih().isKeyUp(SDL_SCANCODE_Z) || ih().isKeyUp(SDL_SCANCODE_BACKSPACE)) {
		_keyUse = false;
	}

	// Cuando se ha escrito el nombre
	if (_p.first.size() >= LONG_NAME) {
		// Escribe el record si entra en el Top
		if (compYOrdMaxPoints(_p)) {
			writeRecordsFile();
			// Actualizamos el texto para dar feedback de que el record se ha guardado
			SceneManager::GetInstance()->getEntityByName("SaveRecordText")->getComponent<TextComponent>()->setTexto("CONGRATULATIONS " + _p.first + "\nYOUR RECORD HAS BEEN SAVED");
		}
		else {
			SceneManager::GetInstance()->getEntityByName("SaveRecordText")->getComponent<TextComponent>()->setTexto("SORRY " + _p.first + "\nYOUR RECORD HASN'T BEEN SAVED");
		}

		// Mostramos el Top 5
		std::string top5text = "";
		
		for (int i = 0; i < _maxPoints.size(); i++)
		{
			top5text += to_string(i + 1) + "." + _maxPoints[i].first + " - " + to_string(_maxPoints[i].second) + "\n";
		}

		SceneManager::GetInstance()->getEntityByName("Top5Text")->getComponent<TextComponent>()->setTexto(top5text);

		// Mandamos borrar esta entidad
		SceneManager::GetInstance()->addEntityToRemove(_entity);
	}
}

void SaveRecord::readRecordsFile()
{
	ifstream file;
	file.open(_recordsFileName.c_str());
	if (file.is_open()) {
		string f;
		while (getline(file, f)) {
			pair<string, int>p;
			for (int i = 2; i < 5; i++) {
				p.first += f[i];
			}
			string n;
			for (int i = 6; i < f.size(); i++) {
				n += f[i];
			}
			p.second = stoi(n);
			//compYOrdMaxPoints(p);
			_maxPoints.push_back(p);
		}
	}
	file.close();
}

bool sortPairs(const pair<string, int>& x, const pair<string, int>& y)
{
	return x.second > y.second;
}

bool SaveRecord::compYOrdMaxPoints(std::pair<std::string, int>p)
{
	if (_maxPoints.size() < NUM_MAXRECORDS) {
		_maxPoints.push_back(p);
		sort(_maxPoints.begin(), _maxPoints.end(), sortPairs);
		return true;
	}
	else {
		if (p.second > _maxPoints[_maxPoints.size() - 1].second) {
			_maxPoints.pop_back();
			_maxPoints.push_back(p);
			sort(_maxPoints.begin(), _maxPoints.end(), sortPairs);
			for (int i = 0; i < _maxPoints.size(); i++) {
				std::cout << _maxPoints[i].first << " " << _maxPoints[i].second << std::endl;
			}
			return true;
		}
	}
	return false;
}

void SaveRecord::writeRecordsFile() {
	ofstream file;
	file.open(_recordsFileName.c_str());
	if (!file.is_open()) {
		std::cout << "Archivo no abierto" << std::endl;
	}
	else {
		for (int i = 0; i < _maxPoints.size(); i++) {
			file << i + 1 << "." << _maxPoints[i].first << "-" << _maxPoints[i].second << "\n";
		}
	}
	file.close();
}