#include "circleType.h"

circleType::circleType()
{
	radious = 0;
	circleArea = 0;
	perimeter = 0;
}

void circleType::setCircle()
{
	setCoordinates();
	std::cout << "Enter the circle radious" << std::endl;
	radious = getNumber();
}

void circleType::calculateCircle()
{
	circleArea = pi * pow(radious, 2);
	perimeter = radious * 2 * pi;
}

void circleType::printCircle()
{
	printCoordinates();
	std::cout << "      Radious => " << std::fixed << std::setprecision(MAX_DECIMALS) << radious << std::endl;
	std::cout << "         Area => " << std::fixed << std::setprecision(MAX_DECIMALS) << circleArea << std::endl;
	std::cout << "    Perimeter => " << std::fixed << std::setprecision(MAX_DECIMALS) << perimeter << std::endl;
}

