#include "stdafx.h"
#include "Human.h"


Human::Human()
{
	this->age = 0;
	this->contract = 0;
	this->skill = 0;
	this->wage = 0;
}


Human::~Human()
{
}

void Human::setname(std::string set_name) {
	this->name = set_name;
}
void Human::setname(std::string set_name, std::string set_surname) {
	this->name = set_name;
	this->surname = set_surname;
}
Human::Human(unsigned int skill, unsigned int age, float contract, float wage, std::string name, std::string surname)
{
	this->age = age;
	this->contract = contract;
	this->skill = skill;
	this->wage = wage;
	this->setname(name, surname);

}
Human::Human(unsigned int skill, unsigned int age, float contract, float wage, std::string name) {
	this->age = age;
	this->contract = contract;
	this->skill = skill;
	this->wage = wage;
	this->setname(name);
}
