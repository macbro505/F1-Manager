#pragma once
#include "Part.h"
class Chassis :
	public Part
{
public:
	unsigned int tyre_wear_reduction;
	Chassis();
	~Chassis();
	Chassis(float price,unsigned int quality, unsigned int tyre_wear_reduction ,std::string name);
};

