#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Clickable_button
{
public:
	Clickable_button();
	~Clickable_button();
	Clickable_button(std::string, sf::Vector2f location, sf::Font *font, std::string filename1, std::string filename2, int width, int height);
	bool checkClick(sf::Vector2f);
	void setState(bool);
	void draw(sf::RenderWindow *window);
	bool checkState();
	void changeText(std::string text);

	sf::Text text_button;
	sf::Texture normal_t;
	sf::Texture clicked_t;
	sf::Sprite *normal_s;
	sf::Sprite *clicked_s;
	sf::Sprite* currentSpr;
	int width;
	int heihgt;
	bool current;
};
