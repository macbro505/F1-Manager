#pragma once
#include "WearingParts.h"
#include <iostream>
#define Engine_wear_factor 200.0
#define Half_random_E 200
#define Max_random_E 400
enum manufacturer {
	NONE,
	Mercedes,
	Ferrari,
	Renault,
	Honda,
	BMW,
	Toyota,
	Cosworth
};
class Engine :
	public Wearing_parts
{
public:
	manufacturer provider;
	friend std::ostream& operator<<(std::ostream & os, const Engine & engine);
	Engine(float price,unsigned int quality, std::string name, double wear, unsigned int durability, manufacturer provider);
	void calculate_wear(unsigned int track_powertrain_level);
	Engine();
	~Engine();
};

