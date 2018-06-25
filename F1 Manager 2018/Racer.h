#pragma once
#include "Car.h"
#include "Driver.h"
#include <vector>
#define Good_Racer 30000000
#define OK_Racer 13500000
#define Quali 0
#define Half_random_Skill 250
#define Max_random_Skill 500

class Racer :public Driver, public Car {
public:
	std::string team_name;
	unsigned int driver_nr;
	unsigned int points;
	int current_lap_time;
	int whole_time;
	bool DNF;
	int NO_Pits;
	Racer();
	~Racer();
	Racer(const Racer & racer1);
	Racer(unsigned int skill, unsigned int wet_skill, unsigned int age, float contract, float wage, std::string name, std::string surname, Engine *current_engine, Tyres* current_tyres, Chassis* current_chassis, Aerodynamics* current_aero, std::string set_name, unsigned int driver_nr, std::string team_name);
	Racer(unsigned int skill, unsigned int wet_skill, unsigned int age, float contract, float wage, std::string name, Engine *current_engine, Tyres* current_tyres, Chassis* current_chassis, Aerodynamics* current_aero, std::string set_name, unsigned int driver_nr, std::string team_name);
	Racer(unsigned int skill, unsigned int wet_skill, unsigned int age, float contract, float wage, std::string name, std::string surname, Engine *current_engine, Tyres* current_tyres, Chassis* current_chassis, Aerodynamics* current_aero, std::string set_name);
	Racer(unsigned int skill, unsigned int wet_skill, unsigned int age, float contract, float wage, std::string name, Engine *current_engine, Tyres* current_tyres, Chassis* current_chassis, Aerodynamics* current_aero, std::string set_name);
	void set_driver_nr(unsigned int driver_nr);
	void show_time_whole();
	std::string show_time(int time);
	int get_whole_time();
	void set_DNF_true();
	void set_DNF_false();
	void choose_tyres(int number_of_laps, int current_lap, Compounds hard, Compounds med, Compounds soft, int current_rain, int track_tyre_wear);
	bool wants_to_change_tyres();
	void get_ready_for_race();
	void set_team_name(std::string name);
	void add_points(int points);
};
bool sortbytime(Racer *R1, Racer *R2);
bool sortbypoints_racer(Racer *R1, Racer *R2);