#include "cylinderType.h"

bool stay()
{
	std::string choice(" ");

	while (1)
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX,'\n');
		std::cout << "\nCalculate another one? Y/N " << std::endl;
		std::getline(std::cin, choice);
		
		if (choice[0] == 'N' || choice[0] == 'n')
		{
			std::cout << "Good bye!" << std::endl;
			return false;
		}

		if (choice[0] == 'Y' || choice[0] == 'y')
		{
			return true;
		}

		if (choice[0] != 'N'|| choice[0] != 'Y')
		{
			std::cout << "Let's try that again." << std::endl;
			continue;
		}
	}
}


int main() 
{
	cylinderType myCylinder;
	std::cout << "Welcome to MP4, a program used to calculate a circles and cylinders\n" << std::endl;
	while (1)
	{
		myCylinder.setCylinder();
		myCylinder.calculateCylinder();
		myCylinder.printCylinder();
		
		if (stay() == false) return 0;
		else continue;
	}
}