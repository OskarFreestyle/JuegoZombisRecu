#include "LookatMouse.h"
#include "InputManager.h"
#include "Entidad.h"

#include <Transform.h>
#include <OgreVector3.h>
#include <tgmath.h>

LookatMouse::LookatMouse() : test(false)/*, tr_(nullptr)*/ {
}

LookatMouse::~LookatMouse() {

}

bool LookatMouse::init(const std::map<std::string, std::string>& mapa)
{	
	if (mapa.find("test") == mapa.end())
		return false;

	Transform* tr = entity_->getComponent<Transform>();
	if (tr == nullptr)
		return false;
	tr_ = tr;
	//std::string me = mapa.at("mesh");
	//setMesh(me);

	/*std::string ma = mapa.at("material");
	if (ma != "") setMaterial(ma);

	std::string vi = mapa.at("visible");
	if (vi == "true") setVisible(true);
	else if (vi == "false") setVisible(false);
	else return false;*/

	/*_nodo->setPosition(tr->getPosition().getX(), tr->getPosition().getY(), tr->getPosition().getZ());
	_nodo->setScale(tr->getScale().getX(), tr->getScale().getY(), tr->getScale().getZ());
	_nodo->setOrientation(tr->getRotation());*/

	inicializado_ = true;

	return true;
}


void LookatMouse::debugMousePos()
{
	//if (im != nullptr) {
	//	std::cout << im->getMousePos().first << ", " << im->getMousePos().second; //creo que esta cogiendo algo vacio
	//}
	//else {
	//	std::cout << "INPUT MANAGER POINTER NULL IN LOOKATMOUSE";
	//}

	std::cout << Singleton<InputManager>::instance()->getMousePos().first << ", " << Singleton<InputManager>::instance()->getMousePos().second << "\n";

}

void LookatMouse::rotateToMouse2D()
{
	MP = Singleton<InputManager>::instance()->getMousePosInGame();


	//tr_->setPosition(MP.first, 0, MP.second);

	//var startingScreenPos = mainCamera.WorldToScreenPoint(player.position);
	//playerPos
	std::pair<int, int> auxRaton = MP;

	auxRaton.first -= tr_->getPosition().getX();
	auxRaton.second -= tr_->getPosition().getY();
	//double angle = Mathf.Atan2(mouseScreenPos.y, mouseScreenPos.x) * Mathf.Rad2Deg;
	auxRaton.first -= entity_->getComponent<Transform>()->getPosition().getX();
	auxRaton.second -= entity_->getComponent<Transform>()->getPosition().getY();
	double angle_ = atan2(auxRaton.first, auxRaton.second);
	Vectola3D v(0, angle_, 0) ;
	Quaterniola x(1, v);
	//player.rotation = Quaternion.Euler(new Vector3(0, 0, angle));
	
	entity_->getComponent<Transform>()->setRotation(x);
	std::cout << angle_ << std::endl;

	
}

void LookatMouse::update()
{
	if (entity_->hasComponent<Transform>())
	{
		//debugMousePos();
		rotateToMouse2D();
	}

}
