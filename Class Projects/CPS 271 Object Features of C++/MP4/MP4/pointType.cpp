#include "pointType.h"

pointType::pointType()
{
	x = 0;
	y = 0;
}

float pointType::getNumber()
{
	float n = 0;

	while (1) {
		try
		{
			std::cin >> n;

			if (std::cin.fail())
			{
				throw(1);
			}

			break;
		}
		catch (int error)
		{
			if (error == 1)
			{
				std::cout << "\tNOT A NUMBER" << std::endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				continue;
			}
		}
	}
	return n;
}

void pointType::setCoordinates()
{
		std::cout << "Enter the X coordinate" << std::endl;
		x = getNumber();
			
		std::cout << "Enter the Y coordinate" << std::endl;
		y = getNumber();
					
}

void pointType::printCoordinates()
{
	std::cout << "        (X,Y) => " << "(" << std::fixed << std::setprecision(MAX_DECIMALS) << x << "," << std::setprecision(MAX_DECIMALS) << y << ")" << std::endl;
}
