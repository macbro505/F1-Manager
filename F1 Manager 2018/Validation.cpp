#include "stdafx.h"
#include "Validation.h"


Validation::Validation()
{
}


Validation::~Validation()
{
}

bool Validation::check(std::string option, std::string *temp) {
	if (option == "Number") {
		try
		{
			if (!std::regex_match(*temp, this->pattern))
			{
				throw Exception_Only_Numbers();
			}
			else {
				if (temp->size() >= 3) {
					throw Exception_Max_99();
				}
			}
		}
		catch (Exception_Only_Numbers x)
		{
			*temp = x.what();
		}
		catch (Exception_Max_99 x) {
			*temp = x.what();
		}
	}
	else if ( option == "Alpha") {
		try
		{
			if (!std::regex_match(*temp, this->pattern))
			{
				throw Exception_Only_Letters();
			}
		}
		catch (Exception_Only_Letters x)
		{
			*temp = x.what();
		}
	}
	else if (option == "AlNum") {
		try
		{
			if (!std::regex_match(*temp, this->pattern))
			{
				throw Exception_Max_Three();
			}
		}
		catch (Exception_Max_Three x)
		{
			*temp = x.what();
		}
	}
	return std::regex_match(*temp, this->pattern);
}
bool Validation::check(std::string *temp) {
	bool value_to_return = true;
		try
		{
			if (this->engine_check=="")
			{
				value_to_return = false;
				throw Exception_No_Engine();
			}
			else {
				if (this->racer_check1==NULL || this->racer_check2 == NULL) {
					value_to_return = false;
					throw Exception_Not_Enough_drivers();
				}
			}
		}
		catch (Exception_No_Engine x)
		{
			*temp = x.what();
		}
		catch (Exception_Not_Enough_drivers x) {
			*temp = x.what();
		}
	return value_to_return;
}
Validation::Validation(const std::regex &pattern) :pattern(pattern) {
	engine_check = "";
	racer_check1 = NULL;
	racer_check2 = NULL;
}
Validation::Validation(std::string engine, Racer* racer_check1, Racer* racer_check2){
	this->engine_check = engine;
	this->racer_check1 = racer_check1;
	this->racer_check2 = racer_check2;
}