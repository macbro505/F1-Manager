#include "stdafx.h"
#include "WearingParts.h"


Wearing_parts::Wearing_parts():Part()
{
	this->durability = 0;
	this->wear = 0;
}

Wearing_parts::~Wearing_parts()
{
}
Wearing_parts::Wearing_parts(float price, unsigned int quality, std::string name, double wear, unsigned int durability) :Part(price, quality, name) {
	this->wear = wear;
	this->durability = durability;
}