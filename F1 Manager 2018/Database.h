#pragma once
#include <vector>
#include "Racer.h"
#include "Engine.h"
#include "Aerodynamics.h"
#include "Chassis.h"
#include "Team.h"
#include "Manager.h"
#include "Race_track.h"

#define Engine_factor_divisor 1000000000.0
#define Chassis_factor_divisor 100000.0 
#define Max_wear 100
#define Max_wear_d 100.0
#define Little_rain 20
#define Aero_factor_divisor 10000000.0
#define Max_random 400
#define Half_random 200
#define Engine_impact 0.05
#define Chassis_impact 0.03
#define Aero_impact 0.03
#define Part_impact 0.02
#define Tyre_impact 0.01
#define Max_whole_time 99999999
#define Pit_in_time 20000
#define Max_random_race 800
#define Half_random_race 400
#define Less_power_not_maunfacturer_factor 10

class Database
{
public:
	static int points[22];
	static std::vector<Racer*> Racer_List; 
	static std::vector<Engine> Engine_List;
	static std::vector<Team*> Team_List;
	static std::vector<Race_track> Track_List;
	static std::vector<Racer*> Free_Racers_List;
	Database();
	~Database();
};
void load_Racers();
void load_Engines();
void load_Teams();
void load_tracks();
void load_points();
void load_free_Racers();


