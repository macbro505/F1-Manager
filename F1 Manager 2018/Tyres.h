#pragma once
#include "WearingParts.h"
#define Max_durability 100
#define Inter_and_wet_compound_factor 25
#define Max_quality 100
#define Dry_compound_factor 10
#define Virtualy_no_rain 10
#define Little_rain 20
#define Heavy_rain 50
#define Max_tyre_wear 100
#define Dry_compound_on_very_wet_factor -6.0
#define Dry_compound_time_factor 20
#define Dry_compound_on_wet_factor -2.5
#define Intermediate_factor 40
#define Wet_factor 20
#define Heavy_rain_intermediate_factor -80
#define Wet_ratio 2.5
#define Very_wet_ratio 2
#define Little_rain_wet_tyre_factor -200
#define Dry_intermediate_factor -100
#define Dry_wet_tyre_factor -300
#define Virtualy_no_rain_ratio 10
#define Half_random_T 200
#define Max_random_T 400
#define Max_random_Wear 150
#define Half_random_Wear 75
enum Compounds {
	Wet,
	Intermediate,
	Superhard,
	Hard,
	Medium,
	Soft,
	Supersoft,
	Ultrasoft,
	Hypersoft,
};

class Tyres :
	public Wearing_parts
{
public:
	Compounds compound;

	Tyres();
	~Tyres();
	Tyres(Compounds compound);
	void calculate_wear(unsigned int track_tyre_wear, unsigned int chassis_reduction);
	double calculate_ratio(int rain);
};

