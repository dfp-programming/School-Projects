#include "Student.h"

Student::Student()
{
	rank = 0;
	GPA = 0;
}

void Student::setData()
{
	Person::setData();
	
	std::cout << "Rank  1.Freshman  2.Sophomore  3.Junior  4.Senior" << std::endl;
	rank = getNumbers::getInt(1,4);
	std::cout << "GPA ";
	GPA = getNumbers::getDouble(0, 4.5);
}

void Student::printData()
{
	std::cout << "STUDENT" << std::endl;
	Person::printData();

	std::cout << std::setw(indentation) << std::left << "Rank: ";
	
	switch (rank)
	{
	case 1:
		std::cout << "Freshman" << std::endl;
		break;
	case 2:
		std::cout << "Sophomore" << std::endl;
		break;
	case 3:
		std::cout << "Junior" << std::endl;
		break;
	case 4:
		std::cout << "Senior" << std::endl;
		break;
	default:
		std::cout << "No Rank" << std::endl;
		break;
	}

	std::cout << std::setw(indentation) << std::left << "GPA: " << std::fixed << std::setprecision(2) << GPA << std::endl;

	std::cout << "*****************************************************" << std::endl;
}


