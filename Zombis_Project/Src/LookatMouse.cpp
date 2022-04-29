/*#include "LookatMouse.h"
#include "InputManager.h"
#include "Transform.h"
#include "Entidad.h"

//#include <OgreVector3.h>

LookatMouse::LookatMouse() {}*/
/*@ - 14, 6 + 14, 7 @@ */
/*LookatMouse::~LookatMouse() {}

bool LookatMouse::init(const std::map<std::string, std::string>& mapa)
{

	//si alguna de las variables que estamos buscando est� al final del archivo de texto, es el final y lo marcamos como que vmos a salir
	//poner entre "" los nombres de las variables que estamos asignando del archivo .lua encontrado en Assets->Scenes

/*@ - 30, 22 + 31, 29 @@ */
//}
		/*bool LookatMouse::init(const std::map<std::string, std::string>&mapa)*/

/*void LookatMouse::debugMousePos()
{
	if (im != nullptr) {
		std::cout << im->getMousePos().first << ", " << im->getMousePos().second; //creo que esta cogiendo algo vacio
	}
	else {
		std::cout << "INPUT MANAGER POINTER NULL IN LOOKATMOUSE";
	}

	std::cout << Singleton<InputManager>::instance()->getMousePos().first << ", " << Singleton<InputManager>::instance()->getMousePos().second << "\n";

}

void LookatMouse::rotateToMouse2D()
{
	debugMousePos();
	MP = Singleton<InputManager>::instance()->getMousePos();

	if (entity_->hasComponent<Transform>())

		//rotate object about rotationAxis by rotationAngle
		//entity_->getComponent<Transform>()->translate(MP.first, MP.second, -10);
		//entity_->getComponent<Transform>()->setPosY(entity_->getComponent<Transform>()->getPos().getY() + 10.0f);

		entity_->getComponent<Transform>()->setPosition(MP.first, MP.second, 0);
}

void LookatMouse::update()
{
	if (entity_->hasComponent<Transform>() && Singleton<InputManager>::instance()->isKeyDown(SDL_KeyCode(SDLK_1)))
	{
		debugMousePos();
		rotateToMouse2D();
	}

}*/
