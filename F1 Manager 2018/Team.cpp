#include "stdafx.h"
#include "Team.h"


Team::Team()
{
	this->Racer_no_1 = NULL;
	this->Racer_no_2 = NULL;
	this->Team_manager = NULL;
	this->MyAero = NULL;
	this->MyChassis = NULL;
	this->MyEngine = NULL;
}

Team::Team(Racer *Racer_no_1, Racer* Racer_no_2, std::string team_name, Manager * Team_manager) {
	this->Racer_no_1 = Racer_no_1;
	this->Racer_no_2 = Racer_no_2;
	this->team_name = team_name;
	this->Team_manager = Team_manager;
	this->points_team = 0;
	this->MyAero = NULL;
	this->MyChassis = NULL;
	this->MyEngine = NULL;
}

Team::~Team()
{
	if (this->Racer_no_1 != NULL) {
		delete this->Racer_no_1;
	}
	if (this->Racer_no_2 != NULL) {
		delete this->Racer_no_2;
	}
	if (this->Team_manager != NULL) {
		delete this->Team_manager;
	}
}
void Team::setname(std::string set_name) {
	this->team_name = set_name;
}
void Team::add_points(int points) {
	this->points_team += points;
}
bool sortbypoints_team(Team *T1, Team *T2) {
	if ((T1->points_team)>(T2->points_team))
		return true;
	else
		return false;
}
