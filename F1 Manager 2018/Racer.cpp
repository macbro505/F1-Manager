#include "stdafx.h"
#include "Racer.h"

Racer::Racer() {
	this->driver_nr = 0;
	this->points = 0;
	this->current_lap_time = 0;
	this->whole_time = 0;
	this->DNF = false;
	this->NO_Pits = 0;
}
Racer::~Racer() {

}
Racer::Racer(unsigned int skill, unsigned int wet_skill, unsigned int age, float contract, float wage, std::string name, std::string surname, Engine *current_engine, Tyres* current_tyres, Chassis* current_chassis, Aerodynamics* current_aero, std::string set_name, unsigned int driver_nr, std::string team_name) :Driver(wet_skill, skill, age, contract, wage, name, surname), Car(current_engine, current_tyres, current_chassis, current_aero, set_name)
{
	this->driver_nr = driver_nr;
	this->points = 0;
	this->current_lap_time = 0;
	this->DNF = false;
	this->whole_time = 0;
	this->NO_Pits = 0;
	this->team_name = team_name;
}
Racer::Racer(unsigned int skill, unsigned int wet_skill, unsigned int age, float contract, float wage, std::string name, Engine *current_engine, Tyres* current_tyres, Chassis* current_chassis, Aerodynamics* current_aero, std::string set_name, unsigned int driver_nr, std::string team_name) : Driver(wet_skill, skill, age, contract, wage,name) , Car(current_engine, current_tyres, current_chassis, current_aero, set_name)
{
	this->driver_nr = driver_nr;
	this->points = 0;
	this->current_lap_time = 0;
	this->DNF = false;
	this->whole_time = 0;
	this->NO_Pits = 0;
	this->team_name = team_name;
}
Racer::Racer(unsigned int skill, unsigned int wet_skill, unsigned int age, float contract, float wage, std::string name, std::string surname, Engine *current_engine, Tyres* current_tyres, Chassis* current_chassis, Aerodynamics* current_aero, std::string set_name) : Driver(wet_skill, skill, age, contract, wage, name, surname), Car(current_engine, current_tyres, current_chassis, current_aero, set_name)
{
	this->driver_nr = 0;
	this->points = 0;
	this->current_lap_time = 0;
	this->DNF = false;
	this->whole_time = 0;
	this->NO_Pits = 0;
}
Racer::Racer(unsigned int skill, unsigned int wet_skill, unsigned int age, float contract, float wage, std::string name, Engine *current_engine, Tyres* current_tyres, Chassis* current_chassis, Aerodynamics* current_aero, std::string set_name) : Driver(wet_skill, skill, age, contract, wage, name), Car(current_engine, current_tyres, current_chassis, current_aero, set_name)
{
	this->points = 0;
	this->driver_nr = 0;
	this->current_lap_time = 0;
	this->DNF = false;
	this->whole_time = 0;
	this->NO_Pits = 0;
}
Racer::Racer(const Racer & racer1): Driver(racer1), Car(racer1) {
	this->current_aero = racer1.current_aero;
	this->current_engine = racer1.current_engine;
	this->current_chassis = racer1.current_chassis;
	this->current_lap_time = 0;
	this->DNF = false;
	this->whole_time = 0;
	this->NO_Pits = 0;

}
void Racer::set_driver_nr(unsigned int driver_nr) {
	//if (search_racer_by_driver_nr==false) {
		this->driver_nr = driver_nr;
	//}
}
void Racer::set_DNF_true() {
	this->DNF = true;
}
void Racer::set_DNF_false() {
	this->DNF = false;
}
void Racer::show_time_whole() {

}
std::string Racer::show_time(int time) {
	int temp = time;
	int minutes=0;
	int seconds=0;
	int last_digits=0;
	std::string minute;
	std::string second;
	std::string milisecond;
	std::string whole_time;
	do {
		if (temp > 60000) {
			minutes += 1;
			temp -= 60000;
		}
		if (temp < 60000) {
			seconds = temp / 1000;
			temp -= (seconds * 1000);
			last_digits = temp ;
			temp -= last_digits;
		}
	} while (temp!=0);
	minute = std::to_string(minutes);
	second = std::to_string(seconds);
	milisecond= std::to_string(last_digits);
	if (second.size() == 0) {
		second = "00";
	}
	else if (second.size() == 1) {
		second = "0" + second;
	}
	if (milisecond.size() == 0) {
		milisecond = "000";
	}
	else if (milisecond.size() == 1) {
		milisecond = "00" + milisecond;
	}
	else if (milisecond.size() == 2) {
		milisecond = "0" + milisecond;
	}
	whole_time = minute + "." + second + ":" + milisecond;
	return  whole_time;
}
int Racer::get_whole_time() {
	return this->whole_time;
}
void Racer::choose_tyres(int number_of_laps ,int current_lap, Compounds hard, Compounds med, Compounds soft, int current_rain, int track_tyre_wear) {
	double temp;
		int temp_skill = this->current_aero->quality*this->current_engine->quality*this->current_chassis->quality*this->skill;
		if(current_rain<Virtualy_no_rain){
			if (current_lap == Quali) {
				if (temp_skill > Good_Racer) {
					this->change_tyres(med);
				}
				else {
					this->change_tyres(soft);
				}
			}
			else {
				temp = double(track_tyre_wear) / double(Max_durability - (soft * Dry_compound_factor))*(1000.0 - double((rand() % Max_random_T) - Half_random_T)) / 1000;
				if (number_of_laps - current_lap * temp < 50) {
					this->change_tyres(soft);
				}
				else {
					temp = double(track_tyre_wear) / double(Max_durability - (med * Dry_compound_factor))*(1000.0 - double((rand() % Max_random_T) - Half_random_T)) / 1000;
					int temp_t = temp_skill * ((1000 + ((rand() % Max_random_Skill) + Half_random_Skill)) / 1000);
					if (number_of_laps - current_lap * temp < 50 || temp_t >= OK_Racer) {
						this->change_tyres(med);
					}
					else {
						this->change_tyres(hard);
					}
				}
			}
		}
		else if (current_rain>Virtualy_no_rain && current_rain<Heavy_rain) {
			this->change_tyres(Intermediate);
		}
		else {
			this->change_tyres(Wet);
		}
}


bool Racer::wants_to_change_tyres() {
	double temp = this->current_tyres->wear;
	if ((temp*(1000.0 - double((rand() % Max_random_T) - Half_random_T)) / 1000) > 65) {
		return true;
	}
	else {
		return false;
	}
}

bool sortbytime(Racer *R1, Racer *R2) {
	if ((R1->whole_time)<(R2->whole_time))
		return true;
	else
		return false;
}
bool sortbypoints_racer(Racer *R1, Racer *R2) {
	if ((R1->points)>(R2->points))
		return true;
	else
		return false;
}

void Racer::get_ready_for_race() {
	this->current_lap_time = 0;
	this->NO_Pits = 0;
	this->whole_time = 0;
	if (this->current_engine->wear >= 50) {
		this->current_engine->wear = 0;
	}
}

void Racer::set_team_name(std::string name) {
	this->team_name = name;
}
void Racer::add_points(int points) {
	this->points += points;
}