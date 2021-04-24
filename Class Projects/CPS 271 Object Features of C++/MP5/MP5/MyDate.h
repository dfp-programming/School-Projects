#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "getNumbers.h"

class MyDate
{
	int year, month, day;
	std::string hour[2];
	bool taken;

public:

	MyDate();
	void getDay(); //will use the getNumbers class to get a day, and checks against the calendar if the day enterd is valid
	void setDate(); //Will use getDay() method, and getNumbers class to set the date. 
	void setTime();	//sets the Opening and Closing time, and sets the "taken" variable
	void resetTime(); // resets the time, and frees up the taken variable. 
	void printDate(); //prints date
	void printTime();  //prints the time
	bool busyOrFree(); //getter for for "taken"
	};

