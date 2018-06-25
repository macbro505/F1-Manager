#pragma once
#include "Human.h"
class Manager :
	public Human
{
public:
	int Budget;
	Manager(unsigned int skill, unsigned int age, float contract, float wage, std::string name, std::string surname);
	Manager(unsigned int skill, unsigned int age, float contract, float wage, std::string name, std::string surname, int Budget);
	Manager();
	~Manager();
};

