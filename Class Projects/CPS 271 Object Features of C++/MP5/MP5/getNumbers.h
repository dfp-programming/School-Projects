#pragma once
#include <iostream>


//This class was created with the sole purpose to get numbers without errors.
//I made the methods statics, so that they can be accessed without creating objects. 

class getNumbers
{
public:

	int static getInt();
	int static getInt(int, int);
	double long static getDouble();
	double long static getDouble(double, double);
};

