#include "stdafx.h"
#include "Manager.h"


Manager::Manager()
{
}
Manager::Manager(unsigned int skill, unsigned int age, float contract, float wage, std::string name, std::string surname):Human(skill, age, contract, wage, name, surname) {

}

Manager::Manager(unsigned int skill, unsigned int age, float contract, float wage, std::string name, std::string surname, int Budget) : Human(skill, age, contract, wage, name, surname) {
	this->Budget = Budget;
}

Manager::~Manager()
{
}
