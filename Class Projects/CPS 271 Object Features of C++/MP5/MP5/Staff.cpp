#include "Staff.h"

Staff::Staff()
:title("No title assigned"){}

void Staff::setData()
{
	Employee::setData();

	std::cout << "Title: ";
	getline(std::cin, title);
	std::cin.clear();
}

void Staff::printData()
{
	std::cout << "STAFF" << std::endl;
	Employee::printData();
	std::cout << std::setw(indentation) << std::left << "Title: " << title << std::endl;
	std::cout << "*****************************************************" << std::endl;
}
