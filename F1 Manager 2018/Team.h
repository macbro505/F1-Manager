#pragma once
#include "Racer.h"
#include "Manager.h"

class Team
{
public:
	int points_team;
	std::string team_name;
	Racer * Racer_no_1;
	Racer * Racer_no_2;
	Manager * Team_manager;
	Engine* MyEngine;
	Chassis *MyChassis;
	Aerodynamics* MyAero;
	Team(Racer *Racer_no_1, Racer* Racer_no_2, std::string team_name, Manager* Team_manager);
	void setname(std::string set_name);
	void add_points(int points);
	Team();
	~Team();
};
bool sortbypoints_team(Team *T1, Team *T2);
