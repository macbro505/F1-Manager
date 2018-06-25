#include "stdafx.h"
#include "Part.h"
#include <iostream>
#include <string>

void Part::setname(std::string set_name) {
	this->part_name = set_name;
}

Part::Part()
{
	this->price = 0;
	this->quality = 0;
}


Part::~Part()
{
}

Part::Part(float price, unsigned int quality, std::string name) {
	this->price = price;
	this->quality = quality;
	this->setname(name);
}

std::ostream & operator <<(std::ostream & os, const Part & part)
{
	os << part.part_name;
	return os;
}
