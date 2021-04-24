#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

const double pi = 3.14159265359;
const int MAX_DECIMALS = 4;

class pointType
{
public:
	float x, y;

	pointType();


	float getNumber();
	void setCoordinates();
	void printCoordinates();
};

