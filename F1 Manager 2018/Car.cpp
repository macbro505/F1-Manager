#include "stdafx.h"
#include "Car.h"


Car::Car()
{
	this->current_aero = NULL;
	this->current_chassis = NULL;
	this->current_tyres = NULL;
	this->current_engine = NULL;
}


Car::~Car()
{
	if (this->current_aero != NULL) {
		delete this->current_aero;
	}
	if (this->current_chassis != NULL) {
		delete this->current_chassis;
	}
	if (this->current_tyres != NULL) {
		delete this->current_tyres;
	}
	if (this->current_engine != NULL) {
		delete this->current_engine;
	}
}
void Car::setname(std::string set_name) {
	this->car_name = set_name;
}
Car::Car(Engine *current_engine, Tyres* current_tyres, Chassis* current_chassis, Aerodynamics* current_aero, std::string set_name) {
	this->current_aero = current_aero;
	this->current_chassis = current_chassis;
	this->current_engine = current_engine;
	this->current_tyres = current_tyres;
	this->setname(set_name);
}
void Car::change_tyres(Compounds compound) {
	if (current_tyres != NULL) {
		delete this->current_tyres;
	}
	Tyres *new_tyres=new Tyres(compound);
	this->current_tyres = new_tyres;
}

//std::ostream & operator <<(std::ostream & os, const Car & car)
//{
//	os << car.name;
//	return os;
//}
