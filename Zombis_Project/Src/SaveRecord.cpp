#include "SaveRecord.h"
#include "OverlayManager.h"
#include "GameManager.h"
#include "Entidad.h"
#include "InputManager.h"
#include "TextComponent.h"
#include "SceneManager.h"
#include <fstream>
#include <algorithm>

using namespace std;

SaveRecord::~SaveRecord()
{

}

bool SaveRecord::init(const std::map<std::string, std::string>& mapa)
{
	if (mapa.find("recordsFileName") == mapa.end()) return false;

	recordsFileName = mapa.at("recordsFileName");

	// Lee el archivo de records
	readFile();
	// Guarda el record actual para compararlo con los demas
	p.second = GameManager::GetInstance()->getLastGamePoints();
	
	_inicializado = true;

	return _inicializado;
}

void SaveRecord::update() {
	if (!keyUse) {
		if (ih().isKeyDown(SDL_SCANCODE_A)) {
			p.first += "A";
			keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_B)) {
			p.first += "B";
			keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_C)) {
			p.first += "C";
			keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_D)) {
			p.first += "D";
			keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_E)) {
			p.first += "E";
			keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_F)) {
			p.first += "F";
			keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_G)) {
			p.first += "G";
			keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_H)) {
			p.first += "H";
			keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_I)) {
			p.first += "I";
			keyUse = true;
		}

		else if (ih().isKeyDown(SDL_SCANCODE_J)) {
			p.first += "J";
			keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_K)) {
			p.first += "K";
			keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_L)) {
			p.first += "L";
			keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_M)) {
			p.first += "M";
			keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_N)) {
			p.first += "N";
			keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_O)) {
			p.first += "O";
			keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_P)) {
			p.first += "P";
			keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_Q)) {
			p.first += "Q";
			keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_R)) {
			p.first += "R";
			keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_S)) {
			p.first += "S";
			keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_T)) {
			p.first += "T";
			keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_U)) {
			p.first += "U";
			keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_V)) {
			p.first += "V";
			keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_W)) {
			p.first += "W";
			keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_X)) {
			p.first += "X";
			keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_Y)) {
			p.first += "Y";
			keyUse = true;
		}
		else if (ih().isKeyDown(SDL_SCANCODE_Z)) {
		p.first += "Z";
		keyUse = true;
		}
		Entidad* e = SceneManager::GetInstance()->getEntityByName("SaveRecordText");
		if (e) e->getComponent<TextComponent>()->setTexto("YOUR NAME: " + p.first, "RecordText", "RecordPanel");
	}

	if (ih().isKeyUp(SDL_SCANCODE_A)|| ih().isKeyUp(SDL_SCANCODE_B) || ih().isKeyUp(SDL_SCANCODE_C) || ih().isKeyUp(SDL_SCANCODE_D) || ih().isKeyUp(SDL_SCANCODE_E) ||
		ih().isKeyUp(SDL_SCANCODE_F) || ih().isKeyUp(SDL_SCANCODE_G) || ih().isKeyUp(SDL_SCANCODE_H) || ih().isKeyUp(SDL_SCANCODE_I) || ih().isKeyUp(SDL_SCANCODE_J) || 
		ih().isKeyUp(SDL_SCANCODE_K) || ih().isKeyUp(SDL_SCANCODE_L)|| ih().isKeyUp(SDL_SCANCODE_M) || ih().isKeyUp(SDL_SCANCODE_N) || ih().isKeyUp(SDL_SCANCODE_O) ||
		ih().isKeyUp(SDL_SCANCODE_P) || ih().isKeyUp(SDL_SCANCODE_Q) || ih().isKeyUp(SDL_SCANCODE_R) || ih().isKeyUp(SDL_SCANCODE_S) || ih().isKeyUp(SDL_SCANCODE_T) ||
		ih().isKeyUp(SDL_SCANCODE_U) || ih().isKeyUp(SDL_SCANCODE_V) || ih().isKeyUp(SDL_SCANCODE_W) || ih().isKeyUp(SDL_SCANCODE_X) || ih().isKeyUp(SDL_SCANCODE_Y) ||
		ih().isKeyUp(SDL_SCANCODE_Z)) {
		keyUse = false;
	}

	// Cuando se ha escrito el nombre
	if (p.first.size() >= LONG_NAME) {
		// Escribe el record si entra en el Top
		if (compYOrdMaxPoints(p)) {
			writeFile();
			// Actualizamos el texto para dar feedback de que el record se ha guardado
			SceneManager::GetInstance()->getEntityByName("SaveRecordText")->getComponent<TextComponent>()->setTexto("CONGRATULATIONS " + p.first + "\nYOUR RECORD HAS BEEN SAVED", "RecordText", "RecordPanel");
		}
		else {
			SceneManager::GetInstance()->getEntityByName("SaveRecordText")->getComponent<TextComponent>()->setTexto("SORRY " + p.first + "\nYOUR RECORD HASN'T BEEN SAVED", "RecordText", "RecordPanel");
		}

		// Mostramos el Top 5
		std::string top5text = "";
		
		for (int i = 0; i < maxPoints.size(); i++)
		{
			top5text += to_string(i + 1) + "." + maxPoints[i].first + " - " + to_string(maxPoints[i].second) + "\n";
		}

		SceneManager::GetInstance()->getEntityByName("Top5Text")->getComponent<TextComponent>()->setTexto(top5text, "TopText", "TopPanel");

		// Mandamos borrar esta entidad
		SceneManager::GetInstance()->addEntityToRemove(_entity);
	}
}

void SaveRecord::readFile()
{
	ifstream file;
	file.open(recordsFileName.c_str());
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
			maxPoints.push_back(p);
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
	if (maxPoints.size() < NUM_MAXRECORDS) {
		maxPoints.push_back(p);
		sort(maxPoints.begin(), maxPoints.end(), sortPairs);
		return true;
	}
	else {
		if (p.second > maxPoints[maxPoints.size() - 1].second) {
			maxPoints.pop_back();
			maxPoints.push_back(p);
			sort(maxPoints.begin(), maxPoints.end(), sortPairs);
			for (int i = 0; i < maxPoints.size(); i++) {
				std::cout << maxPoints[i].first << " " << maxPoints[i].second << std::endl;
			}
			return true;
		}
	}
	return false;
}

void SaveRecord::writeFile() {
	ofstream file;
	file.open(recordsFileName.c_str());
	if (!file.is_open()) {
		std::cout << "Archivo no abierto" << std::endl;
	}
	else {
		for (int i = 0; i < maxPoints.size(); i++) {
			file << i + 1 << "." << maxPoints[i].first << "-" << maxPoints[i].second << "\n";
		}
	}
	file.close();
}