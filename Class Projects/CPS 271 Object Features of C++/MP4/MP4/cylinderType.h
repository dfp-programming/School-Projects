#pragma once
#include "circleType.h"


class cylinderType :
	public circleType
{
public:
	float height, volume, cylinderArea;

	cylinderType();

	void setCylinder();
	void calculateCylinder();
	void printCylinder();

};

