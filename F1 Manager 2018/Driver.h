#pragma once
#include <iostream>
#include "Human.h"

class Driver : public Human {
public:
	unsigned int wet_skill;
	Driver();
	~Driver();
	Driver(unsigned int wet_skill ,unsigned int skill, unsigned int age, float contract, float wage, std::string name, std::string surname);
	Driver(unsigned int wet_skill, unsigned int skill, unsigned int age, float contract, float wage, std::string name);
};
