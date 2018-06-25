// F1Manager2018.cpp: Definiuje punkt wejścia dla aplikacji konsolowej.
//
#include "stdafx.h"
#include "Driver.h"
#include "Car.h"
#include "Engine.h"
#include <iostream>
#include <vector>
#include "Racer.h"
#include "Database.h"
#include "Race.h"
#include "Tyres.h"
#include <ctime>
#include "Interface.h"
#include "Clickable_button.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
	srand(time(NULL));
	load_Engines();
	load_Racers();
	load_Teams();
	load_tracks();
	load_points();
	load_free_Racers();
	Team *MyTeam = NULL;
	Interface Main;
	Main.main_loop(MyTeam);
	return 0;
}

