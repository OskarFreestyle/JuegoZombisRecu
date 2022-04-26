#include "LookatMouse.h"
#include "InputManager.h"
#include "Transform.h"
#include "Entidad.h"


LookatMouse::LookatMouse()
{
}

LookatMouse::~LookatMouse()
{
}

bool LookatMouse::init(const std::map<std::string, std::string>& mapa)
{
	//si alguna de las variables que estamos buscando está al final del archivo de texto, es el final y lo marcamos como que vmos a salir
	//poner entre "" los nombres de las variables que estamos asignando del archivo .lua encontrado en Assets->Scenes

	if (mapa.find("test") == mapa.end()) return false; 

	Transform* tr = entity_->getComponent<Transform>();
	if (tr == nullptr)
		return false;

	std::cout << "COMPONENTE INICIALIZADO";

	return true;
}

void LookatMouse::debugMousePos()
{
	if (im != nullptr) {
		std::cout << im->getMousePos().first << ", " << im->getMousePos().second; //creo que esta cogiendo algo vacio
	}
	else {
		std::cout << "INPUT MANAGER POINTER NULL IN LOOKATMOUSE";
	}
	
}

void LookatMouse::update()
{
	debugMousePos();

	if (entity_->hasComponent<Transform>())
	{
		debugMousePos();
	}
	
}
