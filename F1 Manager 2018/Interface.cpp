#include "stdafx.h"
#include "Interface.h"
#include "Database.h"
#include "Race.h"
#include "Clickable_button.h"
#include "Race_track.h"

Interface::Interface()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1360, 765), "F1 MANAGER 2018", sf::Style::Default);
	this->window->setFramerateLimit(60);
	this->get_font();
}
Interface::Interface(sf::RenderWindow *window) {
	this->window = window;	
	this->window->setFramerateLimit(60);
	this->get_font();
}

Interface::~Interface()
{
}
void Interface::get_font() {
	font = new sf::Font;
	if (!this->font->loadFromFile("Arial_Black.ttf"))
	{
		std::cout << "Font Error" << std::endl;
	}
}
void Interface::main_loop(Team *MyTeam) {
	while (this->window->isOpen())
	{
		sf::Event event;
		while (this->window->pollEvent(event))
		{
			sf::Vector2f mousepos(sf::Mouse::getPosition(*window));
			sf::Vector2f Vector(500, 500);
			Clickable_button button1("Play", Vector, font, "Button_white_small.png", "Button_blue_small.png", 340, 77);
			window->clear();
			draw_background(window, "backgroundTitleScreen.png");
			button1.draw(this->window);
			window->display();
			window->clear();
			if (event.type == sf::Event::MouseButtonPressed && button1.checkClick(mousepos)==true) {
				this->loop_data(MyTeam);
			}
			if (event.type == sf::Event::Closed) {
				window->close();
			}
		}
	}
}
void Interface::draw_background(sf::RenderWindow *window, std::string text) {
	sf::Texture texture;
	if (!texture.loadFromFile(text))
	{
		std::cout << "error" << std::endl;
	}
	sf::Sprite background(texture);
	background.setTextureRect(sf::IntRect(0, 0, 1360, 765));
	window->draw(background);
}
void Interface::get_string(sf::RenderWindow *window,sf::Event event, std::string *Text_string, bool *done) {
	if (event.text.unicode < 128)
	{
		std::string text1;
		if (event.text.unicode == 13) { //enter
			*done = true;
		}
		else if (event.text.unicode == 8) { // backspace
			if (Text_string->size() > 0) Text_string->resize(Text_string->size() - 1);
		}
		else {
			text1=(char)(event.text.unicode);
			*Text_string += text1;
		}
	}
}

void Interface::loop_data(Team *MyTeam) {
	while (window->isOpen())
	{
		std::string temp1;
		sf::Event event;
		while (window->pollEvent(event))
		{
			window->clear();
			draw_background(window, "backgroundMain.png");
			sf::Vector2f mousepos(sf::Mouse::getPosition(*window));
			sf::Vector2f Vector1(550, 200);
			sf::Vector2f Vector2(550, 300);
			sf::Vector2f Vector3(550, 400);
			sf::Vector2f Vector4(550, 500);
			sf::Vector2f Vector5(900, 600);
			draw_getting_text();
			Clickable_button button1(temp, Vector1, font, "textwindow.png", "textwindow.png", 700, 77);
			Clickable_button button2(tempa, Vector2, font, "textwindow.png", "textwindow.png", 700, 77);
			Clickable_button button3(tempb, Vector3, font, "textwindow.png", "textwindow.png", 700, 77);
			Clickable_button button4(tempc, Vector4, font, "textwindow.png", "textwindow.png", 700, 77);
			Clickable_button button5("Confirm", Vector5, font, "Button_white_small.png", "Button_blue_small.png", 340, 77);
			button1.draw(this->window);
			button2.draw(this->window);
			button3.draw(this->window);
			button4.draw(this->window);
			button5.draw(this->window);
			window->display();
			if (event.type == sf::Event::Closed) {
				window->close();
			}
			if (event.type == sf::Event::MouseButtonPressed && button1.checkClick(mousepos) == true) {
				temp = "";
				this->getting_string_loop(&temp1, Vector1);
				temp = temp1;
			}
			if (event.type == sf::Event::MouseButtonPressed && button2.checkClick(mousepos) == true) {
				tempa = "";
				this->getting_string_loop(&temp1, Vector2);
				tempa = temp1;
			}
			if (event.type == sf::Event::MouseButtonPressed && button3.checkClick(mousepos) == true) {
				tempb = "";
				this->getting_string_loop(&temp1, Vector3);
				tempb = temp1;
			}
			if (event.type == sf::Event::MouseButtonPressed && button4.checkClick(mousepos) == true) {
				tempc = "";
				this->getting_string_loop(&temp1, Vector4);
				tempc = temp1;
			}
			if (event.type == sf::Event::MouseButtonPressed && button5.checkClick(mousepos) == true) {
				std::regex age_pattern("([1-9])|([1-9][0-9]+)");
				std::regex team_pattern("([[:alnum:]]+)|([[:alnum:]]+\\s[[:alnum:]]+)|([[:alnum:]]+\\s[[:alnum:]]+\\s[[:alnum:]]+)");
				std::regex name_and_surname_pattern("[[:alpha:]]+");
				Validation Check_name_and_surname(name_and_surname_pattern);
				Validation Check_team_name(team_pattern);
				Validation Check_age(age_pattern);
				if (Check_age.check("Number", &temp) && Check_name_and_surname.check("Alpha", &tempa) && Check_name_and_surname.check("Alpha", &tempb) && Check_team_name.check("AlNum", &tempc)) {
					Manager *You = new Manager(50, std::stoi(temp), 10, 10000, tempa, tempb, 500000);
					Team *MyTeam = new Team(NULL, NULL, tempc, You);
					loop_parts(MyTeam);
				}
			}
			window->clear();
		}
	}
}

void Interface::getting_string_loop(std::string *temp_text, sf::Vector2f Vector) {
	bool done = false;
	while (window->isOpen() && done == false)
	{
		window->clear();
		draw_background(window, "backgroundMain.png");
		sf::Vector2f Vector1(550, 200);
		sf::Vector2f Vector2(550, 300);
		sf::Vector2f Vector3(550, 400);
		sf::Vector2f Vector4(550, 500);
		draw_getting_text();
		Clickable_button button1(temp, Vector1, font, "textwindow.png", "textwindow.png", 700, 77);
		Clickable_button button2(tempa, Vector2, font, "textwindow.png", "textwindow.png", 700, 77);
		Clickable_button button3(tempb, Vector3, font, "textwindow.png", "textwindow.png", 700, 77);
		Clickable_button button4(tempc, Vector4, font, "textwindow.png", "textwindow.png", 700, 77);
		sf::Text Text_string;
		Text_string.setFont(*font);
		Text_string.setPosition(Vector.x+20, Vector.y+20);
		Text_string.setCharacterSize(20);
		Text_string.setFillColor(sf::Color::Black);
		sf::Event event;
		while (window->pollEvent(event) && done == false)
		{
			Text_string.setString(*temp_text);
			draw_background(window, "backgroundMain.png");
			draw_getting_text();
			button1.draw(this->window);
			button2.draw(this->window);
			button3.draw(this->window);
			button4.draw(this->window);
			window->draw(Text_string);
			window->display();
			if (event.type == sf::Event::Closed) {
				window->close();
			}
			if (event.type == sf::Event::TextEntered)
			{
				this->get_string(window, event, temp_text, &done);
			}
		}
	}
}

void Interface::getting_string_loop2(std::string *temp_text, sf::Vector2f Vector) {
	bool done = false;
	while (window->isOpen() && done == false)
	{
		window->clear();
		draw_background(window, "backgroundMain.png");
		sf::Vector2f Vector1(25, 170);
		sf::Vector2f Vector2(25, 220);
		sf::Vector2f Vector3(25, 270);
		sf::Vector2f Vector4(25, 320);
		sf::Vector2f Vector6(25, 370);
		sf::Vector2f Vector7(550, 170);
		sf::Vector2f Vector8(550, 220);
		sf::Vector2f Vector9(550, 270);
		sf::Vector2f Vector10(550, 320);
		sf::Vector2f Vector11(550, 370);
		sf::Vector2f Vector12(550, 420);
		sf::Vector2f Vector13(550, 470);
		sf::Vector2f Vector14(930, 220);
		sf::Vector2f Vector15(930, 370);
		Clickable_button button1("", Vector1, font, "Button_white_small_square.png", "Button_blue_small_square.png", 40, 40);
		Clickable_button button2("", Vector2, font, "Button_white_small_square.png", "Button_blue_small_square.png", 40, 40);
		Clickable_button button3("", Vector3, font, "Button_white_small_square.png", "Button_blue_small_square.png", 40, 40);
		Clickable_button button4("", Vector4, font, "Button_white_small_square.png", "Button_blue_small_square.png", 40, 40);
		Clickable_button button6("", Vector6, font, "Button_white_small_square.png", "Button_blue_small_square.png", 40, 40);
		Clickable_button button7("", Vector7, font, "Button_white_small_square.png", "Button_blue_small_square.png", 40, 40);
		Clickable_button button8("", Vector8, font, "Button_white_small_square.png", "Button_blue_small_square.png", 40, 40);
		Clickable_button button9("", Vector9, font, "Button_white_small_square.png", "Button_blue_small_square.png", 40, 40);
		Clickable_button button10("", Vector10, font, "Button_white_small_square.png", "Button_blue_small_square.png", 40, 40);
		Clickable_button button11("", Vector11, font, "Button_white_small_square.png", "Button_blue_small_square.png", 40, 40);
		Clickable_button button12("", Vector12, font, "Button_white_small_square.png", "Button_blue_small_square.png", 40, 40);
		Clickable_button button13("", Vector13, font, "Button_white_small_square.png", "Button_blue_small_square.png", 40, 40);
		Clickable_button button14(tempa, Vector14, font, "textwindow_mid.png", "textwindow_mid.png", 340, 77);
		Clickable_button button15(tempb, Vector15, font, "textwindow_mid.png", "textwindow_mid.png", 340, 77);
		sf::Text Text_string;
		Text_string.setFont(*font);
		Text_string.setPosition(Vector.x + 20, Vector.y + 20);
		Text_string.setCharacterSize(20);
		Text_string.setFillColor(sf::Color::Black);
		sf::Event event;
		while (window->pollEvent(event) && done == false)
		{
			window->clear();
			Text_string.setString(*temp_text);
			draw_background(window, "backgroundMain.png");
			button1.draw(this->window);
			button2.draw(this->window);
			button3.draw(this->window);
			button4.draw(this->window);
			button6.draw(this->window);
			button7.draw(this->window);
			button8.draw(this->window);
			button9.draw(this->window);
			button10.draw(this->window);
			button11.draw(this->window);
			button12.draw(this->window);
			button13.draw(this->window);
			button14.draw(this->window);
			button15.draw(this->window);
			draw_getting_parts();
			window->draw(Text_string);
			window->display();
			if (event.type == sf::Event::Closed) {
				window->close();
			}
			if (event.type == sf::Event::TextEntered)
			{
				this->get_string(window, event, temp_text, &done);
			}
		}
	}
}

void Interface::draw_getting_text() {
	draw_text("Give information about yourself and your team", sf::Color::White, 300, 35, 30);
	draw_text("Your age:", sf::Color::Black, 300,225, 22);
	draw_text("Your name:", sf::Color::Black, 300, 325, 22);
	draw_text("Your surname:", sf::Color::Black, 300, 425, 22);
	draw_text("Yours team name:", sf::Color::Black, 300, 525, 22);
}
void Interface::loop_parts(Team *MyTeam) {
	int first_racer_no = 99;
	int second_racer_no = 99;
	temp = "";
	tempa = "";
	tempb = "";
	tempc = "";
	bool allracers = false;
	sf::Vector2f Vector1(25, 170);
	sf::Vector2f Vector2(25, 220);
	sf::Vector2f Vector3(25, 270);
	sf::Vector2f Vector4(25, 320);
	sf::Vector2f Vector6(25, 370);
	sf::Vector2f Vector5(1000, 570);
	sf::Vector2f Vector7(550, 170);
	sf::Vector2f Vector8(550, 220);
	sf::Vector2f Vector9(550, 270);
	sf::Vector2f Vector10(550, 320);
	sf::Vector2f Vector11(550, 370);
	sf::Vector2f Vector12(550, 420);
	sf::Vector2f Vector13(550, 470);
	sf::Vector2f Vector14(930, 220);
	sf::Vector2f Vector15(930, 370);
	Clickable_button button1("", Vector1, font, "Button_white_small_square.png", "Button_blue_small_square.png", 40, 40);
	Clickable_button button2("", Vector2, font, "Button_white_small_square.png", "Button_blue_small_square.png", 40, 40);
	Clickable_button button3("", Vector3, font, "Button_white_small_square.png", "Button_blue_small_square.png", 40, 40);
	Clickable_button button4("", Vector4, font, "Button_white_small_square.png", "Button_blue_small_square.png", 40, 40);
	Clickable_button button6("", Vector6, font, "Button_white_small_square.png", "Button_blue_small_square.png", 40, 40);
	Clickable_button button7("", Vector7, font, "Button_white_small_square.png", "Button_blue_small_square.png", 40, 40);
	Clickable_button button8("", Vector8, font, "Button_white_small_square.png", "Button_blue_small_square.png", 40, 40);
	Clickable_button button9("", Vector9, font, "Button_white_small_square.png", "Button_blue_small_square.png", 40, 40);
	Clickable_button button10("", Vector10, font, "Button_white_small_square.png", "Button_blue_small_square.png", 40, 40);
	Clickable_button button11("", Vector11, font, "Button_white_small_square.png", "Button_blue_small_square.png", 40, 40);
	Clickable_button button12("", Vector12, font, "Button_white_small_square.png", "Button_blue_small_square.png", 40, 40);
	Clickable_button button13("", Vector13, font, "Button_white_small_square.png", "Button_blue_small_square.png", 40, 40);
	Clickable_button button14(tempa, Vector14, font, "textwindow_mid.png", "textwindow_mid.png", 340, 77);
	Clickable_button button15(tempb, Vector15, font, "textwindow_mid.png", "textwindow_mid.png", 340, 77);
	Clickable_button button5("Confirm", Vector5, font, "Button_white_small.png", "Button_blue_small.png", 340, 77);
	while (window->isOpen())
	{
		std::string temp1;
		sf::Event event;
		while (window->pollEvent(event))
		{
			window->clear();
			draw_background(window, "backgroundMain.png");
			sf::Vector2f mousepos(sf::Mouse::getPosition(*window));
			button14.changeText(tempa);
			button15.changeText(tempb);
			button1.draw(this->window);
			button2.draw(this->window);
			button3.draw(this->window);
			button4.draw(this->window);
			button6.draw(this->window);
			button5.draw(this->window);
			button7.draw(this->window);
			button8.draw(this->window);
			button9.draw(this->window);
			button10.draw(this->window);
			button11.draw(this->window);
			button12.draw(this->window);
			button13.draw(this->window);
			button14.draw(this->window);
			button15.draw(this->window);
			draw_text(tempc, sf::Color::Black, 200, 570, 22);
			draw_getting_parts();
			window->display();
			if (event.type == sf::Event::Closed) {
				window->close();
			}
			check_racer_box(event, MyTeam, button1, mousepos, allracers, first_racer_no, second_racer_no, 0);
			check_racer_box(event, MyTeam, button2, mousepos, allracers, first_racer_no, second_racer_no, 1);
			check_racer_box(event, MyTeam, button3, mousepos, allracers, first_racer_no, second_racer_no, 2);
			check_racer_box(event, MyTeam, button4, mousepos, allracers, first_racer_no, second_racer_no, 3);
			check_racer_box(event, MyTeam, button6, mousepos, allracers, first_racer_no, second_racer_no, 4);
			check_engine_box(event, button7, mousepos, temp, "0");
			check_engine_box(event, button8, mousepos, temp, "1");
			check_engine_box(event, button9, mousepos, temp, "2");
			check_engine_box(event, button10, mousepos, temp, "3");
			check_engine_box(event, button11, mousepos, temp, "4");
			check_engine_box(event, button12, mousepos, temp, "5");
			check_engine_box(event, button13, mousepos, temp, "6");
			if (event.type == sf::Event::MouseButtonPressed && button14.checkClick(mousepos) == true) {
				tempa = "";
				this->getting_string_loop2(&temp1, Vector14);
				tempa = temp1;
			}
			if (event.type == sf::Event::MouseButtonPressed && button15.checkClick(mousepos) == true) {
				tempb = "";
				this->getting_string_loop2(&temp1, Vector15);
				tempb = temp1;
			}

			if (event.type == sf::Event::MouseButtonPressed && button5.checkClick(mousepos) == true) {
				tempc = "";
				std::regex aero_and_chassis_pattern("([1-9])|([1-9][0-9]+)");
				Validation aero_and_chassis(aero_and_chassis_pattern);
				Validation engine_and_racers(temp, MyTeam->Racer_no_1, MyTeam->Racer_no_2);
				if (aero_and_chassis.check("Number", &tempb) && aero_and_chassis.check("Number", &tempa) && engine_and_racers.check(&tempc)) {
					Aerodynamics *current_aero = new Aerodynamics();
					Chassis *current_chassis = new Chassis();
					MyTeam->Racer_no_1->set_team_name(MyTeam->team_name);
					MyTeam->Racer_no_2->set_team_name(MyTeam->team_name);
					MyTeam->Racer_no_1->current_chassis = current_chassis;
					MyTeam->Racer_no_1->current_aero = current_aero;
					MyTeam->Racer_no_2->current_chassis = current_chassis;
					MyTeam->Racer_no_2->current_aero = current_aero;
					MyTeam->Racer_no_1->current_aero->quality = stoi(tempb);
					MyTeam->Racer_no_2->current_aero->quality = stoi(tempb);
					MyTeam->Racer_no_1->current_chassis->quality = stoi(tempa);
					MyTeam->Racer_no_2->current_chassis->quality = stoi(tempa);
					MyTeam->Racer_no_1->current_chassis->tyre_wear_reduction = stoi(tempa);
					MyTeam->Racer_no_2->current_chassis->tyre_wear_reduction = stoi(tempa);
					Engine *racer1 = new Engine(Database::Engine_List[stoi(temp)].price, Database::Engine_List[stoi(temp)].quality, Database::Engine_List[stoi(temp)].part_name, Database::Engine_List[stoi(temp)].wear,Database::Engine_List[stoi(temp)].durability, Database::Engine_List[stoi(temp)].provider);
					Engine *racer2 = new Engine(Database::Engine_List[stoi(temp)].price, Database::Engine_List[stoi(temp)].quality, Database::Engine_List[stoi(temp)].part_name, Database::Engine_List[stoi(temp)].wear, Database::Engine_List[stoi(temp)].durability, Database::Engine_List[stoi(temp)].provider);
					MyTeam->Racer_no_1->current_engine = racer1;
					MyTeam->Racer_no_2->current_engine = racer2;
					Database::Racer_List.push_back(MyTeam->Racer_no_1);
					Database::Racer_List.push_back(MyTeam->Racer_no_2);
					Database::Team_List.push_back(MyTeam);
					//
					loop_race();
					//
				}
			}
		}
	}
}

void Interface::loop_race() {
	bool end_race = false;
	std::vector<Race_track>::iterator it_end = Database::Track_List.end()-1;
	std::vector<Race_track>::iterator it = Database::Track_List.begin();
	sf::Vector2f Vector1(1000, 450);
	sf::Vector2f Vector2(1000, 550);
	Clickable_button button2("Race", Vector1, font, "Button_white_small.png", "Button_blue_small.png", 340, 77);
	Clickable_button button3("Quit", Vector2, font, "Button_white_small.png", "Button_blue_small.png", 340, 77);
	window->clear();
	classificate();
	button2.draw(this->window);
	button3.draw(this->window);
	window->display();
	while (window->isOpen())
	{
		sf::Event event;
				sf::Vector2f mousepos(sf::Mouse::getPosition(*window));
				while (window->pollEvent(event))
				{
					if (event.type == sf::Event::MouseButtonPressed && button2.checkClick(mousepos) == true && end_race==false) {
						Race Race_temp(*it);
						Race_temp.simulate_race(this->window, &event, font);
						window->clear();
						classificate();
						if ((*it).NR==(*it_end).NR) {
							end_race = true;
							draw_text("No races to simulate", sf::Color::Black, 1000, 450, 22);
						}
						else {
							it++;
							button2.setState(button2.checkState());
							button2.draw(this->window);
						}
						button3.draw(this->window);
						window->display();
					}
					if (event.type == sf::Event::MouseButtonPressed && button3.checkClick(mousepos) == true) {
						window->close();
					}
					if (event.type == sf::Event::Closed) {
						window->close();
					}
					
				}
	}
}

void Interface::draw_getting_parts() {
	draw_text("Choose 2 drivers, 1 engine and write quality value from 1 to 99 of Aero and Chassis", sf::Color::White, 50, 35, 25);
	draw_text("Chassis", sf::Color::Black, 1060, 180, 18);
	draw_text("Aero", sf::Color::Black, 1080, 330, 18);
	display_header();
	draw_engines();
	draw_free_racers();
}
void Interface::draw_free_racers() {
	sf::Text Racer_Surname;
	sf::Text Skill;
	sf::Text Wage;
	std::string temp;
	int i = 0;
	for (std::vector<Racer*>::iterator it = Database::Free_Racers_List.begin(); it != Database::Free_Racers_List.end(); it++) {
		draw_text((*it)->name, sf::Color::Black, 70, 180 + (i * 50), 17);
		draw_text((*it)->surname, sf::Color::Black, 210, 180 + (i * 50), 17);
		draw_text(std::to_string((*it)->skill), sf::Color::Black, 363, 180 + (i * 50), 17);
		draw_text(std::to_string((int)((*it)->wage)), sf::Color::Black, 423, 180 + (i * 50), 17);
		i++;
	}
}
void Interface::draw_engines() {

	int i = 0;
	for (std::vector<Engine>::iterator it = Database::Engine_List.begin(); it != Database::Engine_List.end(); it++) {
		draw_text(std::to_string((int)(*it).price), sf::Color::Black, 780, 180 + (i * 50), 17);
		draw_text((*it).part_name, sf::Color::Black, 600, 180 + (i * 50), 17);
		draw_text(std::to_string((*it).quality), sf::Color::Black, 700, 180 + (i * 50), 17);
		i++;
	}
}
void Interface::display_header() {
	draw_text("Name", sf::Color::Black, 70, 140, 17);
	draw_text("Surname", sf::Color::Black, 210, 140, 17);
	draw_text("Quality", sf::Color::Black, 700, 140, 17);
	draw_text("Skill", sf::Color::Black, 363, 140, 17);
	draw_text("Wage", sf::Color::Black, 423, 140, 17);
	draw_text("Name", sf::Color::Black, 600, 140, 17);
	draw_text("Price", sf::Color::Black, 780, 140, 17);
}

void Interface::draw_text( std::string string_to_draw, sf::Color text_color, float x, float y, int size) {
	sf::Text Text_to_draw;
	Text_to_draw.setFont(*font);
	Text_to_draw.setString(string_to_draw);
	Text_to_draw.setPosition(x, y);
	Text_to_draw.setCharacterSize(size);
	Text_to_draw.setFillColor(text_color);
	window->draw(Text_to_draw);
}

void Interface::check_racer_box(sf::Event event, Team *MyTeam, Clickable_button &button, sf::Vector2f mousepos, bool &allracers, int &first_racer_no, int &second_racer_no, int nr_of_box) {
	if (event.type == sf::Event::MouseButtonPressed && button.checkClick(mousepos) == true) {
		if (button.checkState() == false) {//if the button was clicked before user clicked it 
			if (MyTeam->Racer_no_1 == Database::Free_Racers_List[nr_of_box]) {
				MyTeam->Racer_no_1 = NULL;
				allracers = false;
			}
			else if (MyTeam->Racer_no_2 == Database::Free_Racers_List[nr_of_box]) {
				MyTeam->Racer_no_2 = NULL;
				allracers = false;
			}
			else {
				std::cout << "blad" << std::endl;
			}
		}
		else {
			if(allracers==true){
				button.setState(button.checkState());
			}
			else {
				if (MyTeam->Racer_no_1 == NULL)
				{
					MyTeam->Racer_no_1 = Database::Free_Racers_List[nr_of_box];
					first_racer_no = nr_of_box;
				}
				else {
					MyTeam->Racer_no_2 = Database::Free_Racers_List[nr_of_box];
					second_racer_no = nr_of_box;
				}
				if (MyTeam->Racer_no_1 != NULL && MyTeam->Racer_no_2 != NULL) {
					allracers = true;
				}
			}
		}
	}
}
void Interface::check_engine_box (sf::Event event, Clickable_button &button, sf::Vector2f mousepos, std::string &temp, std::string nr_of_box){
	if (event.type == sf::Event::MouseButtonPressed && button.checkClick(mousepos) == true) {
		if (button.checkState() == false) {//if the button was clicked before user clicked it 
			temp = "";
		}
		else {
			if (temp != "") {
				button.setState(button.checkState());
			}
			else {
				temp = nr_of_box;
			}
		}
	}
}
void Interface::classificate() {
	std::sort(Database::Team_List.begin(), Database::Team_List.end(), sortbypoints_team);
	std::sort(Database::Racer_List.begin(), Database::Racer_List.end(), sortbypoints_racer);
	draw_background(window, "background_classyfication.png");
	draw_classyfication_header();
	display_racer_classification();
	display_team_classification();
}
void Interface::display_racer_classification() {
	int i = 0;
	for (std::vector<Racer*>::iterator it = Database::Racer_List.begin(); it != Database::Racer_List.end(); it++) {
		draw_text((*it)->name, sf::Color::Black, 50, 90 + (i * 31), 17);
		draw_text((*it)->surname, sf::Color::Black, 200, 90 + (i * 31), 17);
		draw_text(std::to_string((*it)->driver_nr), sf::Color::Black, 363, 90 + (i * 31), 17);
		draw_text(std::to_string((*it)->points), sf::Color::Black, 400, 90 + (i * 31), 17);
		draw_text(std::to_string(i + 1), sf::Color::Black, 10, 90 + (i * 31), 17);
		i++;
	}
}
void Interface::display_team_classification() {
	int i = 0;
	for (std::vector<Team*>::iterator it = Database::Team_List.begin(); it != Database::Team_List.end(); it++) {
		draw_text((*it)->team_name, sf::Color::Black, 620, 90 + (i * 31), 17);
		draw_text((*it)->Team_manager->name, sf::Color::Black, 965, 90 + (i * 31), 17);
		draw_text((*it)->Team_manager->surname, sf::Color::Black, 1160, 90 + (i * 31), 17);
		draw_text(std::to_string((*it)->points_team), sf::Color::Black, 905, 90 + (i * 31), 17);
		draw_text(std::to_string(i + 1), sf::Color::Black, 590, 90 + (i * 31), 17);
		i++;
	}
}
void Interface::draw_classyfication_header() {
	Interface temp(window);
	temp.draw_text("Classyfication", sf::Color::White, 500, 10, 25);
	temp.draw_text("#", sf::Color::White, 10, 55, 17);
	temp.draw_text("Name", sf::Color::White, 50, 55, 17);
	temp.draw_text("Surname", sf::Color::White, 200, 55, 17);
	temp.draw_text("Nr", sf::Color::White, 363, 55, 17);
	temp.draw_text("Pts", sf::Color::White, 400, 55, 17);

	temp.draw_text("#", sf::Color::White, 590, 55, 17);
	temp.draw_text("Team name", sf::Color::White, 620, 55, 17);
	temp.draw_text("Pts", sf::Color::White, 905, 55, 17);
	temp.draw_text("Owner Name", sf::Color::White, 965, 55, 17);
	temp.draw_text("Surname", sf::Color::White, 1160, 55, 17);

}