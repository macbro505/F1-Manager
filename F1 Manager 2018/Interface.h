#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Database.h"
#include "Race.h"
#include "Validation.h"

class Interface
{
public:
	sf::Text Racer_Name;
	sf::Text Racer_Surname;
	sf::Text Lap_time;
	sf::Text Whole_time;
	sf::Text Team_Name;
	sf::RenderWindow *window;
	sf::Font *font;
	std::string temp;
	std::string tempa;
	std::string tempb;
	std::string tempc;
	std::string tempd;

	Interface();
	Interface(sf::RenderWindow *window);
	~Interface();
	void display_time_of_racer(Racer *R1);
	void get_font();
	void main_loop(Team *MyTeam);
	void loop_data(Team *MyTeam);
	void draw_background(sf::RenderWindow *window, std::string text);
	void get_string(sf::RenderWindow *window, sf::Event event, std::string *Text_string, bool *done);
	void getting_string_loop(std::string *temp_text, sf::Vector2f Vector);
	void draw_getting_text();
	void loop_parts(Team *MyTeam);
	void draw_getting_parts();
	void draw_free_racers();
	void draw_engines();
	void loop_race();
	void display_header();
	void getting_string_loop2(std::string *temp_text, sf::Vector2f Vector);
	void draw_text(std::string string_to_draw, sf::Color text_color, float x, float y, int size);
	void check_racer_box(sf::Event event, Team *MyTeam, Clickable_button &button, sf::Vector2f mousepos, bool &allracers, int &first_racer_no, int &second_racer_no, int nr_of_box);
	void check_engine_box(sf::Event event, Clickable_button &button, sf::Vector2f mousepos, std::string &temp, std::string nr_of_box);
	void classificate();
	void display_racer_classification();
	void display_team_classification();
	void draw_classyfication_header();
};

