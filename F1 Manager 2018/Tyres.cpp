#include "stdafx.h"
#include "Tyres.h"


Tyres::Tyres() :Wearing_parts()
{
}


Tyres::~Tyres()
{
}

Tyres::Tyres(Compounds compound) :Wearing_parts() {
	this->compound = compound;
	int value = compound;
	if (value < 2) {
		this->durability = Max_durability - (value * Inter_and_wet_compound_factor);
		this->quality = Max_quality;
	}
	else {
		this->durability = Max_durability - (value * Dry_compound_factor);
		this->quality = value * Dry_compound_factor;
	}
}
////POPRAWIC WET DLA OPON !!!!!!!!!!!
double Tyres::calculate_ratio(int rain) {
	double temp;
	if (this->compound == Intermediate || this->compound == Wet) {
		if (rain <= Virtualy_no_rain) {
			if (this->compound == Intermediate) {
				temp = Dry_intermediate_factor + (rain*Virtualy_no_rain_ratio);
			}
			else {
				temp = Dry_wet_tyre_factor + (rain*Virtualy_no_rain_ratio);
			}
		}
		else if (rain > Virtualy_no_rain && rain <= Heavy_rain) {
			if (this->compound == Intermediate) {
				temp = Intermediate_factor;
			}
			else {
				temp = Little_rain_wet_tyre_factor + (rain*Wet_ratio);
			}
		}
		else if (rain > Heavy_rain) {
			if (this->compound == Intermediate) {
				temp = Heavy_rain_intermediate_factor - (rain*Very_wet_ratio);
			}
			else {
				temp = Wet_factor;
			}
		}
	}
	else {
		//sprawdziæ
		if (rain <= Virtualy_no_rain) {
			temp = compound * Dry_compound_time_factor;
		}
		else if (rain > Virtualy_no_rain && rain <= Heavy_rain) {
			temp = compound * (Dry_compound_on_wet_factor)*rain;
		}
		else if (rain > Heavy_rain) {
			temp = compound * (Dry_compound_on_very_wet_factor)*rain;
		}
	}
	if (temp > 0) {
		temp = temp * (Max_tyre_wear - this->wear) / Max_tyre_wear;
	}
	else {
		temp = temp * (Max_tyre_wear + this->wear) / Max_tyre_wear;
	}
	return temp;
}
void Tyres::calculate_wear(unsigned int track_tyre_wear,unsigned int chassis_reduction) {
	this->wear = this->wear + double(track_tyre_wear*100) / (double(this->durability)*double(chassis_reduction)*(1000.0 - double((rand() % Max_random_Wear) - Half_random_Wear))/1000);
}
