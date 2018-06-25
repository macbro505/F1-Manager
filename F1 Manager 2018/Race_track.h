#pragma once
#include "Tyres.h"
class Race_track
{
public:
	std::string track_name;
	unsigned int NR;
	unsigned int Downforce_level;
	unsigned int Powertrain_level;
	unsigned int tyre_wear;
	unsigned int rain_probability;
	unsigned int no_laps;
	int lap_time_max;
	Compounds t_softer;
	Compounds t_medium;
	Compounds t_harder;
	Race_track(std::string track_name, unsigned int Downforce_level, unsigned int Powertrain_level, unsigned int tyre_wear, unsigned int rain_probability, unsigned int no_laps,int lap_time_max, Compounds t_softer, Compounds t_medium, Compounds t_harder, unsigned int NR);
	Race_track();
	~Race_track();
};

