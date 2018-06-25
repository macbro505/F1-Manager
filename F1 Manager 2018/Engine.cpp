#include "stdafx.h"
#include "Engine.h"


Engine::Engine():Wearing_parts()
{
	this->provider=NONE;
}


Engine::~Engine()
{
}
void Engine::calculate_wear(unsigned int track_powertrain_level) {
	this->wear = this->wear + double(track_powertrain_level) / Engine_wear_factor* (1000.0 - double((rand() % Max_random_E) - Half_random_E))/1000;
}

Engine::Engine(float price,unsigned int quality, std::string name, double wear, unsigned int durability, manufacturer provider):Wearing_parts(price, quality,name, wear, durability) {
	this->provider = provider;
}

std::ostream & operator <<(std::ostream & os, const Engine & engine)
{
	os << engine.part_name;  
	return os;
}
