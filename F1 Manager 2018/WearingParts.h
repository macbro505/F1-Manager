#pragma once
#include "Part.h"
class Wearing_parts:
	public Part
{
public:
	Wearing_parts(float price, unsigned int quality, std::string name, double wear, unsigned int durability);
	Wearing_parts();
	~Wearing_parts();

	double wear;
	unsigned int durability;
};


