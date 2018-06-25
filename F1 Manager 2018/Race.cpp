#include "stdafx.h"
#include "Race.h"
#include <ctime>
#include <algorithm>
#include "Clickable_button.h"
#include "Interface.h"

Race::Race()
{
}

Race::Race(Race_track Track)
{
	this->current_lap = 0;
	this->current_rain = 0;
	this->Track = Track;
}


void Race::simulate_lap() {
	this->current_rain = 0; //for further development of this progam, here instead of 0 should be algorithm for calculating current rain level
	double temp_factor_engine = 0;
	double temp_factor_chassis = 0;
	double temp_factor_aero = 0;
	double temp_skill;
	Tyres *temp_tyre;
	Engine *temp_engine;
	Chassis temp_chassis;
	Aerodynamics temp_aero;
	for (std::vector<Racer*>::iterator it = Database::Racer_List.begin(); it != Database::Racer_List.end(); it++) {
		temp_tyre = (*it)->current_tyres;
		temp_engine = (*it)->current_engine;
		temp_chassis = (*(*it)->current_chassis);
		temp_aero = (*(*it)->current_aero);
		if (temp_tyre->wear < Max_wear && temp_engine->wear < Max_wear) {
			if (this->current_rain < Little_rain) {
				temp_skill = double((*it)->skill)*0.3;
			}
			else {
				temp_skill = double((*it)->wet_skill)*0.3;
			}
			temp_factor_engine = temp_skill * double(temp_engine->quality)*(Max_wear_d - temp_engine->wear)*double(this->Track.Powertrain_level) *(1000.0 - double((rand() % Max_random_race) - Half_random_race)) / Engine_factor_divisor;
			temp_factor_chassis = (temp_skill*double(temp_chassis.quality))*(1000.0 - double((rand() % Max_random_race) - Half_random_race)) / Chassis_factor_divisor;
			temp_factor_aero = (temp_skill*double(temp_aero.quality)*double(this->Track.Downforce_level))*(1000.0 - double((rand() % Max_random_race) - Half_random_race)) / Aero_factor_divisor;
			(*it)->current_lap_time = this->Track.lap_time_max - this->Track.lap_time_max * Part_impact * temp_factor_engine * Engine_impact - this->Track.lap_time_max * Part_impact * temp_factor_chassis*Chassis_impact - this->Track.lap_time_max * Part_impact * temp_factor_aero*Aero_impact - this->Track.lap_time_max * Tyre_impact*temp_tyre->calculate_ratio(this->current_rain)*Tyre_impact;
			(*it)->whole_time += (*it)->current_lap_time;
			temp_engine->calculate_wear(this->Track.Powertrain_level);
			temp_tyre->calculate_wear(this->Track.tyre_wear, (*it)->current_chassis->tyre_wear_reduction);
		}
		else {
			(*it)->set_DNF_true();
			(*it)->whole_time = Max_whole_time;
		}
	}
	std::sort(Database::Racer_List.begin(), Database::Racer_List.end(), sortbytime);
}
void Race::simulate_race(sf::RenderWindow *window, sf::Event *event, sf::Font *font) {
	Interface Interface_temp(window);
	sf::Time sleep_time(sf::seconds(2));
	bool done = false;
			sf::Vector2f Vector_start(1000, 500);
			sf::Vector2f Vector_Racer2(1000, 650);
			Clickable_button button_start("Begin Quali", Vector_start, font, "Button_white_small.png", "Button_blue_small.png", 340, 77);
			this->display_lap(window, font, "Before Quali");
			button_start.draw(window);
			window->display();
				this->current_lap = 0;
				int temp_pit_time = 0;
				int i = 1;
				for (std::vector<Racer*>::iterator it = Database::Racer_List.begin(); it != Database::Racer_List.end(); it++) {
					(*it)->get_ready_for_race();
					(*it)->choose_tyres(this->Track.no_laps, this->current_lap, this->Track.t_harder, this->Track.t_medium, this->Track.t_softer, this->current_rain, this->Track.tyre_wear);
				}
				//Quali
				bool Quali_done = false;
				while (window->isOpen() && done == false)
				{
					sf::Vector2f mousepos(sf::Mouse::getPosition(*window));
					sf::Event event;
					while (window->pollEvent(event))
					{
						Clickable_button button_start("Race", Vector_start, font, "Button_white_small.png", "Button_blue_small.png", 340, 77);
						if (event.type == sf::Event::MouseButtonPressed && button_start.checkClick(mousepos) == true && Quali_done == true) {
							//half of grid changes tyres, half not
							for (std::vector<Racer*>::iterator it = Database::Racer_List.begin() + ((Database::Racer_List.size()) / 2); it != Database::Racer_List.end(); it++) {
								(*it)->choose_tyres(this->Track.no_laps, this->current_lap, this->Track.t_harder, this->Track.t_medium, this->Track.t_softer, this->current_rain, this->Track.tyre_wear);
							}

							for (this->current_lap; this->current_lap <= this->Track.no_laps; this->current_lap++) {
								this->simulate_lap();
								this->display_lap(window, font, "Race");
								window->display();
								for (std::vector<Racer*>::iterator it = Database::Racer_List.begin(); it != Database::Racer_List.end(); it++) {
									if ((*it)->wants_to_change_tyres()) {
										(*it)->choose_tyres(this->Track.no_laps, this->current_lap, this->Track.t_harder, this->Track.t_medium, this->Track.t_softer, this->current_rain, this->Track.tyre_wear);
										temp_pit_time = (Pit_in_time * (1000 - (rand() % Max_random_T) - Half_random_T) / 1000);
										(*it)->whole_time += temp_pit_time;
										(*it)->current_lap_time += temp_pit_time;
										(*it)->NO_Pits++;
									}
								}
							}
							done = true;
						}
						if (event.type == sf::Event::MouseButtonPressed && button_start.checkClick(mousepos) == true && Quali_done == false) {
							this->simulate_lap();
							this->display_lap(window, font, "Qualification");					
							button_start.draw(window);
							window->display();
							this->current_lap += 1;
							for (std::vector<Racer*>::iterator it = Database::Racer_List.begin(); it != Database::Racer_List.end(); it++) {
								(*it)->get_ready_for_race();
							}
							Quali_done = true;
						}
							////////
						if (event.type == sf::Event::Closed) {
							window->close();
						}
					}
				}
				int j = 0;
				for (std::vector<Racer*>::iterator it_racer = Database::Racer_List.begin(); it_racer != Database::Racer_List.end(); it_racer++) {
					(*it_racer)->add_points(Database::points[j]);
					for (std::vector<Team*>::iterator it_team = Database::Team_List.begin(); it_team != Database::Team_List.end(); it_team++) {
						//dodawanie punktow
						if ((*it_racer)->team_name == (*it_team)->team_name) {
							(*it_team)->add_points(Database::points[j]);
						}

						//nie musi byæ
						(*it_racer)->get_ready_for_race();
					}
					j++;
				}
}
Race::~Race()
{
}

void Race::display_lap(sf::RenderWindow *window, sf::Font *font,std::string mode) {
	int i = 0;
	Interface Interface_temp(window);
	Interface_temp.draw_background(window, "background_race.png");
	draw_track_picture(window);
	display_header(window, font, mode);
	Interface temp_interface(window);
	for (std::vector<Racer*>::iterator it = Database::Racer_List.begin(); it != Database::Racer_List.end(); it++) {
		temp_interface.draw_text((*it)->name, sf::Color::Black, 50, 90 + (i * 31), 17);
		temp_interface.draw_text((*it)->surname, sf::Color::Black, 200, 90 + (i * 31), 17);
		temp_interface.draw_text((*it)->team_name, sf::Color::Black, 700, 90 + (i * 31), 17);
		temp_interface.draw_text(std::to_string((*it)->driver_nr), sf::Color::Black, 363, 90 + (i * 31), 17);
		temp_interface.draw_text(std::to_string(this->current_lap), sf::Color::Black, 616, 90 + (i * 31), 17);
		temp_interface.draw_text(std::to_string((*it)->NO_Pits), sf::Color::Black, 656, 90 + (i * 31), 17);
		temp_interface.draw_text(std::to_string(i + 1), sf::Color::Black, 10, 90 + (i * 31), 17);
		if ((*it)->DNF == false) {
			temp_interface.draw_text((*it)->show_time((*it)->current_lap_time), sf::Color::Black, 400, 90 + (i * 31), 17);
			temp_interface.draw_text((*it)->show_time((*it)->whole_time), sf::Color::Black, 515, 90 + (i * 31), 17);
		}
		else {
			temp_interface.draw_text("DNF", sf::Color::Black, 400, 90 + (i * 31), 17);
			temp_interface.draw_text("DNF", sf::Color::Black, 515, 90 + (i * 31), 17);
		}
		i++;
	}
}
void Race::display_header(sf::RenderWindow *window, sf::Font *font, std::string mode) {
	Interface temp(window);
	temp.draw_text(mode, sf::Color::White, 10, 10, 25);
	temp.draw_text(this->Track.track_name, sf::Color::White, 500, 10, 25);
	temp.draw_text("Name", sf::Color::White, 50, 55, 17);
	temp.draw_text("Surname", sf::Color::White, 200, 55, 17);
	temp.draw_text("Lap Time", sf::Color::White, 400, 55, 17);
	temp.draw_text("Time", sf::Color::White, 515, 55, 17);
	temp.draw_text("Team name", sf::Color::White, 700, 55, 17);
	temp.draw_text("Nr", sf::Color::White, 363, 55, 17);
	temp.draw_text("Lap", sf::Color::White, 616, 55, 17);
	temp.draw_text("PIT", sf::Color::White, 656, 55, 17);
	temp.draw_text("#", sf::Color::White, 10, 55, 17);
	temp.draw_text("Track layout", sf::Color::White, 1090, 60, 25);
}

void Race::draw_track_picture(sf::RenderWindow *window) {
	sf::Texture Race_track;
	std::string nr;
	nr = std::to_string(this->Track.NR);
	if (!Race_track.loadFromFile("track" + nr + ".png"))
	{
		std::cout << "error" << std::endl;
	}
	sf::Sprite track_spr(Race_track);
	track_spr.setTextureRect(sf::IntRect(0, 0, 380, 302));
	track_spr.setPosition(978, 110);
	window->draw(track_spr);
}

