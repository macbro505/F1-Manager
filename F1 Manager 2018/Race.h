#pragma once
#include "Database.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Clickable_button.h"

class Race
{
public:
	Race_track Track;
	unsigned int current_lap;
	unsigned int current_rain;

	Race();
	~Race();
	Race(Race_track Track);

	void simulate_lap();
	void simulate_race(sf::RenderWindow *window, sf::Event *event, sf::Font *font);
	void display_lap(sf::RenderWindow *window, sf::Font *font, std::string mode);
	void display_header(sf::RenderWindow *window, sf::Font *font, std::string mode);
	void draw_classyfication_header(sf::RenderWindow *window);
	void draw_track_picture(sf::RenderWindow *window);
};
