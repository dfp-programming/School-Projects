#include "Geo.h"


pointType::pointType()
{
	x=0; 
	y=0;
}

pointType::pointType(float a, float b) : x(a), y(b) {}

void pointType::setCoordinates(float a, float b)
{
	x = a;
	y = b;
}

float pointType::returnX() 
{
	return x;
}

float pointType::returnY() 
{
	return y;
}

void pointType::printCoordinates() 
{
	std::cout << "Coordinates = " << "(" << x << "," << y << ")" << std::endl;
}




circleType::circleType()
{
	radious = 0;
	area = 0;
	perimeter = 0;
}

circleType::circleType(float r)
{
	radious = r;
	area = 0;
	perimeter = 0;
}

circleType::circleType(float a, float b, float r)
{
	x = a;
	y = b;
	radious = r;
	area = 0;
	perimeter = 0;
}

void circleType::setCircle(float r)
{
	radious = r;
}

void circleType::calculateCircle()
{
	area = pi * pow(radious,2);
	perimeter = radious * 2 * pi;
}

float circleType::returnRadious()
{
	return radious;
}

float circleType::returnPerimeter()
{
	return perimeter;
}

float circleType::returnArea()
{
	return area;
}

void circleType::printCircle() 
{
	std::cout << "Radious = " << std::setprecision(5) << radious <<  std::endl;
	std::cout << "Area = " << std::setprecision(5) << area << std::endl;
	std::cout << "Perimeter = " << std::setprecision(5) << perimeter << std::endl;
}







cylinderTypes::cylinderTypes()
{
	x = 0;
	y = 0;
	radious = 0;
	area = 0;
	perimeter = 0;
	height = 0;
	volume = 0;
}

cylinderTypes::cylinderTypes(float r, float h)
{
	x = 0;
	y = 0;
	radious = r;
	area = 0;
	perimeter = 0;
	height = h;
	volume = 0;
}

cylinderTypes::cylinderTypes(float a, float b, float r, float h)
{
	x = a;
	y = b;
	radious = r;
	area = 0;
	perimeter = 0;
	height = h;
	volume = 0;
}

void cylinderTypes::setCylinder(float r, float h)
{
	radious = r;
	height = h;
}

void cylinderTypes::calculateCylinder()
{
	calculateCircle();
	volume = area * height;
}

void cylinderTypes::printCylinder()
{
	printCoordinates();
	printCircle();
	std::cout << "Height = " << std::setprecision(3) << height << std::endl;
	std::cout << "Volume = " << std::setprecision(10) << volume << std::endl;
}

float cylinderTypes::returnHeight()
{
	return height;
}
