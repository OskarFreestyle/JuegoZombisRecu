#pragma once
#include <vector>
#include <string>
class OverlayManager;
class Motor;
class MainMenu;
class LuaReader;
class LoadResources;
class GameManager;
class OgreManager;

using CallBackOnClick = void(Motor* m);
const int NUM_MAXRECORDS = 5;
class EndState
{
private:
	static void backToMenu(Motor* m);
	bool saltar = false;
	std::string name;
	void readFile();
	bool compYOrdMaxPoints(std::pair<std::string,int>p);
	void writeFile();
	void putName();
	std::vector<std::pair<std::string, int>>maxPoints;
public:
	EndState();
	~EndState();
	void arch();
	
};

