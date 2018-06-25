#include "stdafx.h"
#include "Chassis.h"


Chassis::Chassis() :Part()
{
}


Chassis::~Chassis()
{
}

Chassis::Chassis(float price,unsigned int quality, unsigned int tyre_wear_reduction, std::string name) :Part(price, quality, name) {
	this->tyre_wear_reduction = tyre_wear_reduction;
}