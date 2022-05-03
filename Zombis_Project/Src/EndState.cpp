#include "EndState.h"
#include <fstream>
#include <algorithm>
#include "utils\Singleton.h"
#include"LuaReader.h"
#include"LoadResources.h"
#include "OverlayManager.h"
#include "MainMenu.h"
#include "GameManager.h"
#include "InputManager.h"
#include "OgreManager.h"
#include "FMODAudioManager.h"


EndState::EndState()
{
	readFileMenus(Singleton<LoadResources>::instance()->scene("EndScene.lua"), "GetEndScene");
	Singleton<OverlayManager>::instance()->creaTexto(0.25, 0.2, "Your score is: "+std::to_string(GameManager::GetInstance()->getPoints()),"ScoreText", 0.1, "ScorePanel",0.6,0.3);
	Singleton<OverlayManager>::instance()->creaTexto(0, 0.5, "Pulsa 3 teclas con tu nombre para poder guardar el record o el boton derecho del raton para no guardar", "RecordText", 0.03, "RecordPanel", 1, 0.3);
	Singleton<OverlayManager>::instance()->setCallBackToButton("BackMenuPanel", backToMenu);
	Singleton<OgreManager>::instance()->update();
	arch();
}

EndState::~EndState()
{

}

void EndState::arch()
{
	readFile();
	std::pair<string, int>p;
	putName();
	if (saltar == false) {
		p.first = name;
		p.second = GameManager::GetInstance()->getPoints();
		bool añadido = compYOrdMaxPoints(p);
		if (añadido)
			writeFile();
	}
}

void EndState::backToMenu(Motor* m)
{
	Singleton<OverlayManager>::instance()->clear();
	Singleton<FMODAudioManager>::instance()->playMusic(1, false);

	// Para evitar pulsar el boton del otro menu
	ih().refresh();

	MainMenu* mainMenu = new MainMenu();
}
void EndState::readFile()
{
	ifstream file;
	string s = "../../Exes/Assets/maxScore.txt";
	//string s = "./Assets/maxScore.txt";	// Codigo para la entrega perdonanos Pedro P.
	file.open(s.c_str());
	if (file.is_open()) {
		string f;
		while (getline(file, f)) {
			pair<string, int>p;
			for (int i = 2;i < 5;i++) {
				p.first += f[i];
			}
			string n;
			for (int i = 6;i < f.size();i++) {
				n += f[i];
			}
			p.second = stoi(n);
			//compYOrdMaxPoints(p);
			maxPoints.push_back(p);
			//std::cout << maxPoints.back().first << " " << maxPoints.back().second << std::endl;
		}
	}
	file.close();
}

bool sortPairs(const pair<string, int>& x, const pair<string, int>& y)
{
	return x.second > y.second;
}

bool EndState::compYOrdMaxPoints(std::pair<std::string, int>p)
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
			for (int i = 0;i < maxPoints.size();i++) {
				std::cout << maxPoints[i].first << " " << maxPoints[i].second << std::endl;
			}
			return true;
		}
	}
	return false;

}
void EndState::writeFile() {
	ofstream file;
	string s = "../../Exes/Assets/maxScore.txt";
	//string s = "./Assets/maxScore.txt";
	file.open(s.c_str());
	if (!file.is_open()) {
		std::cout << "Archivo no abierto" << std::endl;
	}
	else {
		//file <<"1."<<"PPP"<<"-"<< GameManager::GetInstance()->getPoints() << "\n";
		for (int i = 0;i < maxPoints.size();i++) {
			file <<i+1<< "." << maxPoints[i].first<< "-" << maxPoints[i].second << "\n";
		}
	}
	file.close();
}

void EndState::putName()
{
	int i = 0;
	while(i<3&& saltar==false){
		ih().refresh();
		if (ih().getMouseButtonState(ih().RIGHT)) {
			saltar = true;
		}
		else {
#pragma region alfabeth
			if (ih().isKeyDown(SDL_SCANCODE_A)) {
				name += "A";
				i++;
			}
			else if (ih().isKeyDown(SDL_SCANCODE_B)) {
				name += "B";
				i++;
			}
			else if (ih().isKeyDown(SDL_SCANCODE_C)) {
				name += "C";
				i++;
			}
			else if (ih().isKeyDown(SDL_SCANCODE_D)) {
				name += "D";
				i++;
			}
			else if (ih().isKeyDown(SDL_SCANCODE_E)) {
				name += "E";
				i++;
			}
			else if (ih().isKeyDown(SDL_SCANCODE_F)) {
				name += "F";
				i++;
			}
			else if (ih().isKeyDown(SDL_SCANCODE_G)) {
				name += "G";
				i++;
			}
			else if (ih().isKeyDown(SDL_SCANCODE_H)) {
				name += "H";
				i++;
			}
			else if (ih().isKeyDown(SDL_SCANCODE_I)) {
				name += "I";
				i++;
			}
			else if (ih().isKeyDown(SDL_SCANCODE_J)) {
				name += "J";
				i++;
			}
			else if (ih().isKeyDown(SDL_SCANCODE_K)) {
				name += "K";
				i++;
			}
			else if (ih().isKeyDown(SDL_SCANCODE_L)) {
				name += "L";
				i++;
			}
			else if (ih().isKeyDown(SDL_SCANCODE_M)) {
				name += "M";
				i++;
			}
			else if (ih().isKeyDown(SDL_SCANCODE_N)) {
				name += "N";
				i++;
			}
			else if (ih().isKeyDown(SDL_SCANCODE_O)) {
				name += "O";
				i++;
			}
			else if (ih().isKeyDown(SDL_SCANCODE_P)) {
				name += "P";
				i++;
			}
			else if (ih().isKeyDown(SDL_SCANCODE_Q)) {
				name += "Q";
				i++;
			}
			else if (ih().isKeyDown(SDL_SCANCODE_R)) {
				name += "R";
				i++;
			}
			else if (ih().isKeyDown(SDL_SCANCODE_S)) {
				name += "S";
				i++;
			}
			else if (ih().isKeyDown(SDL_SCANCODE_T)) {
				name += "T";
				i++;
			}
			else if (ih().isKeyDown(SDL_SCANCODE_U)) {
				name += "U";
				i++;
			}
			else if (ih().isKeyDown(SDL_SCANCODE_V)) {
				name += "V";
				i++;
			}
			else if (ih().isKeyDown(SDL_SCANCODE_W)) {
				name += "W";
				i++;
			}
			else if (ih().isKeyDown(SDL_SCANCODE_X)) {
				name += "X";
				i++;
			}
			else if (ih().isKeyDown(SDL_SCANCODE_Y)) {
				name += "Y";
				i++;
			}
			else if (ih().isKeyDown(SDL_SCANCODE_Z)) {
				name += "Z";
				i++;
			}
#pragma endregion
		}
	}
}
