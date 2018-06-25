#include "stdafx.h"
#include "Race_track.h"


Race_track::Race_track()
{
}

Race_track::Race_track(std::string track_name, unsigned int Downforce_level, unsigned int Powertrain_level, unsigned int tyre_wear, unsigned int rain_probability, unsigned int no_laps, int lap_time_max, Compounds t_softer, Compounds t_medium, Compounds t_harder, unsigned int NR)
{
	this->Downforce_level = Downforce_level;
	this->Powertrain_level = Powertrain_level;
	this->rain_probability = rain_probability;
	this->track_name = track_name;
	this->tyre_wear = tyre_wear;
	this->no_laps = no_laps;
	this->t_harder = t_harder;
	this->t_medium = t_medium;
	this->t_softer = t_softer;
	this->lap_time_max = lap_time_max;
	this->NR = NR;
}

Race_track::~Race_track()
{
}
