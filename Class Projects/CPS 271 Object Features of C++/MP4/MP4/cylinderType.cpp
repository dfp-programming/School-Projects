#include "cylinderType.h"


cylinderType::cylinderType()
{
	x = 0;
	y = 0;
	radious = 0;
	circleArea = 0;
	perimeter = 0;
	height = 0;
	volume = 0;
	cylinderArea = 0;
}


void cylinderType::setCylinder()
{
	setCircle();
	std::cout << "Enter the cylinder height" << std::endl;
	height = getNumber();
}

void cylinderType::calculateCylinder()
{
	calculateCircle();
	volume = circleArea * height;
	cylinderArea = (perimeter * height)+(2*circleArea);
}

void cylinderType::printCylinder()
{
	printCircle();
	std::cout << "       Height => " << std::fixed << std::setprecision(MAX_DECIMALS) << height << std::endl;
	std::cout << "       Volume => " << std::fixed << std::setprecision(MAX_DECIMALS) << volume << std::endl;
	std::cout << "Cylinder Area => " << std::fixed << std::setprecision(MAX_DECIMALS) << cylinderArea << std::endl;
}
