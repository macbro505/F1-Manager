#pragma once
#include <iostream>
class Human
{
public:
	std::string name;
	std::string surname;
	unsigned int skill;
	unsigned int age;
	float contract;
	float wage;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void setname(std::string set_name);
	void setname(std::string set_name, std::string set_surname);
	Human(unsigned int skill, unsigned int age, float contract, float wage, std::string name, std::string surname);
	Human(unsigned int skill, unsigned int age, float contract, float wage, std::string name);
	Human();
	~Human();
};
