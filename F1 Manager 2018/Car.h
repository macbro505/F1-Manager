#pragma once
#include <iostream>
#include "Aerodynamics.h"
#include "Chassis.h"
#include "Engine.h"
#include "Tyres.h"
class Car
{
public:
	Engine * current_engine;
	Tyres* current_tyres;
	Chassis* current_chassis;
	Aerodynamics* current_aero;
	std::string car_name;
	///////////////////////////////////////////////////////////////////////
	void setname(std::string set_name);
	void change_tyres(Compounds compound);
	Car(Engine *current_engine, Tyres* current_tyres, Chassis* current_chassis, Aerodynamics* current_aero, std::string set_name);
	Car();
	virtual ~Car();
};

