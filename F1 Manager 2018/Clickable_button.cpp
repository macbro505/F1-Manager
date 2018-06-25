#include "stdafx.h"
#include "Clickable_button.h"


Clickable_button::Clickable_button()
{
}


Clickable_button::~Clickable_button()
{
}

Clickable_button::Clickable_button(std::string text, sf::Vector2f location, sf::Font *font, std::string filename1, std::string filename2, int width, int height){
	
	if (!normal_t.loadFromFile(filename1))
	{
		std::cout << "error" << std::endl;
	}
	if (!clicked_t.loadFromFile(filename2))
	{
		std::cout << "error" << std::endl;
	}
	normal_s =new sf::Sprite(normal_t);
	clicked_s = new sf::Sprite(clicked_t);
	current = false;
	this->normal_s->setTextureRect(sf::IntRect(0, 0, width, height));
	this->clicked_s->setTextureRect(sf::IntRect(0, 0, width, height));
	this->normal_s->setPosition(location);
	this->clicked_s->setPosition(location);
	text_button.setString(text);
	text_button.setFont(*font);
	text_button.setPosition(location.x + (width/2) - (14 * text.size()/2) , location.y + (height / 2));
	text_button.setCharacterSize(14);
	text_button.setFillColor(sf::Color::Black);
	currentSpr = normal_s;
	this->heihgt = height;
	this->width = width;
}
bool Clickable_button::checkClick(sf::Vector2f mousePos) {
	if (mousePos.x >= currentSpr->getPosition().x 
		&& mousePos.x <= currentSpr->getPosition().x + width
		&& mousePos.y >= currentSpr->getPosition().y
		&& mousePos.y <= currentSpr->getPosition().y + heihgt)
	{
			setState(current);
			return true;
	}
	return false;
}
void Clickable_button::setState(bool which) {
	current = !which;
	if (current) {
		currentSpr = clicked_s;
		return;
	}
	currentSpr = normal_s;
}

void Clickable_button::draw(sf::RenderWindow *window) {
	window->draw(*currentSpr);
	window->draw(text_button);
}
bool Clickable_button::checkState() {
	return current;
}
void Clickable_button::changeText(std::string text) {
	text_button.setString(text);
}
