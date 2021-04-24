#pragma once
#include <iostream>
#include <math.h>
#include <iomanip>

const double pi = 3.14159265359;

class pointType {
public:
	float x, y;

	pointType();
	pointType(float,float);

	void setCoordinates(float, float);
	float returnX();
	float returnY();
	void printCoordinates();
};

class circleType : public pointType 
{
public:
	float radious, area, perimeter;
	
	circleType();
	circleType(float);
	circleType(float, float, float);
	
	void setCircle(float);
	void calculateCircle();
	float returnRadious();
	float returnPerimeter();
	float returnArea();
	void printCircle();
};

class cylinderTypes : public circleType 
{
public:
	float height, volume;

	cylinderTypes();
	cylinderTypes(float,float);
	cylinderTypes(float,float,float,float);

	void setCylinder(float, float);
	void calculateCylinder();
	float returnHeight();
	void printCylinder();

};
