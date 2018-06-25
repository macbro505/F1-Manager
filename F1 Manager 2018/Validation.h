#pragma once
#include <regex>
#include <string>
#include <iostream>
#include "Racer.h"
#include "Engine.h"
class Validation
{
private:
	std::string engine_check;
	Racer* racer_check1;
	Racer* racer_check2;
	std::regex pattern;
public:
	Validation();
	~Validation();
	Validation(const std::regex &pattern);
	bool check(std::string option, std::string *temp);
	Validation(std::string engine, Racer* racer_check1, Racer* racer_check2);
	bool check(std::string *temp);

};
class Exception
{
public:
	virtual const char* what() = 0;
};

class Exception_Only_Letters :Exception
{
public:
	const char* what() { return "You can only use letters"; }
};

class Exception_Not_Enough_Money : Exception
{
public:
	const char* what() { return "You don't have enough money to do that"; }
};

class Exception_Only_Numbers: Exception
{
public:
	const char* what() { return "You can only use numbers"; }
};
class Exception_Max_Three: Exception
{
public:
	const char* what() { return "You can only use three words"; }
};
class Exception_Max_99 : Exception
{
public:
	const char* what() { return "Value must be between 1 and 99"; }
};
class Exception_No_Engine : Exception
{
public:
	const char* what() { return "You have to choose engine"; }
};
class Exception_Not_Enough_drivers : Exception
{
public:
	const char* what() { return "You have to choose two drivers"; }
};


