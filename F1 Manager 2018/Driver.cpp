#include "stdafx.h"
#include "Driver.h"


Driver::Driver() :Human()
{
	this->wet_skill = 0;
}


Driver::~Driver()
{
}

Driver::Driver(unsigned int wet_skill, unsigned int skill, unsigned int age, float contract, float wage, std::string name, std::string surname):Human(skill, age, contract, wage, name, surname)
{
	this->wet_skill = wet_skill;
}
Driver::Driver(unsigned int wet_skill, unsigned int skill, unsigned int age, float contract, float wage, std::string name) : Human(skill, age, contract, wage, name) {
	this->wet_skill = wet_skill;
}
