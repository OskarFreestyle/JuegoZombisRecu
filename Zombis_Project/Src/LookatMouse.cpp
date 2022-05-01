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

	tr_ = entity_->getComponent<Transform>();
	if (tr_ == nullptr)
		return false;

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

	std::pair<int, int> auxRaton = MP;

	auxRaton.first -= tr_->getPosition().getX();
	auxRaton.second -= tr_->getPosition().getY();
	//double angle = Mathf.Atan2(mouseScreenPos.y, mouseScreenPos.x) * Mathf.Rad2Deg;
	double angle_ = atan2(auxRaton.first, auxRaton.second)/* * (360 / (3.14 ))*/;
	Vectola3D v(0, angle_, 0) ;
	Quaterniola x(1, v);


	entity_->getComponent<Transform>()->setRotation(x);
	//Vectola3D playerPos = entity_->getComponent<Transform>()->getPosition();
	////Vector2 playerShipPosition; // x, y position of your ship
	////Vector2 touchPosition; // x, y position of where your finger touched the screen
	//Vectola3D diff = Vectola3D(MP.first, MP.second,0) - playerPos; // difference vector
	//float angle = atan2f(-diff.getY(), diff.getX()); // find the angle in radians as +/- PI

	////Quaterniola x(eulerToQuat(0, angle, 0));
	//int yaw, pitch, roll;
	//pitch = angle;
	//roll = yaw = 0;
	//double cy = cos(yaw * 0.5);
	//double sy = sin(yaw * 0.5);
	//double cp = cos(pitch * 0.5);
	//double sp = sin(pitch * 0.5);
	//double cr = cos(roll * 0.5);
	//double sr = sin(roll * 0.5);

	//Quaterniola q(cr * cp * cy + sr * sp * sy, sr * cp * cy - cr * sp * sy, cr * sp * cy + sr * cp * sy, cr * cp * sy - sr * sp * cy);
	// 
	//std::cout << angle_ << std::endl;

	
}

void LookatMouse::update()
{
	if (entity_->hasComponent<Transform>())
	{
		//debugMousePos();
		rotateToMouse2D();
	}

}

//Quaterniola LookatMouse::eulerToQuat(int yaw, int pitch, int roll)
//{
//	// Abbreviations for the various angular functions
//	double cy = cos(yaw * 0.5);
//	double sy = sin(yaw * 0.5);
//	double cp = cos(pitch * 0.5);
//	double sp = sin(pitch * 0.5);
//	double cr = cos(roll * 0.5);
//	double sr = sin(roll * 0.5);
//
//	Quaterniola q(cr * cp * cy + sr * sp * sy, sr * cp * cy - cr * sp * sy, cr * sp * cy + sr * cp * sy, cr * cp * sy - sr * sp * cy);
//	//q.w = cr * cp * cy + sr * sp * sy;
//	//q.x = sr * cp * cy - cr * sp * sy;
//	//q.y = cr * sp * cy + sr * cp * sy;
//	//q.z = cr * cp * sy - sr * sp * cy;
//	std::cout << "<<<<<<<<<<<<<<<<<<";
//
//	return q;
//}
