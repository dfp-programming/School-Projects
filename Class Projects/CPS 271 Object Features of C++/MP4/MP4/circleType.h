#pragma once
#include "pointType.h"

class circleType :
	public pointType
{
public:
	float radious, circleArea, perimeter;

	circleType();

	void setCircle();
	void calculateCircle();
	//float returnRadious();
	//float returnPerimeter();
	//float returnArea();
	void printCircle();
};

