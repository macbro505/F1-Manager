#pragma once
#include "Part.h"
class Aerodynamics :
	public Part
{
public:
	Aerodynamics();
	~Aerodynamics();
	Aerodynamics(float price,unsigned int quality, std::string name);
};

