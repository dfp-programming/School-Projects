#include "Employee.h"

Employee::Employee()
{
	salary = 0;
}

void Employee::setData()
{
	Person::setData();

	std::cout << "Salary: $";
	salary = getNumbers::getDouble(0,150000); //HR determined no employee can make more than 150k/year
	std::cout << "Date of hire: ";
	DateOfHire.setDate();
	std::cin.clear();
	std::cin.ignore();
}

void Employee::printData()
{
	Person::printData();

	std::cout << std::setw(indentation-1) << std::left << "Salary: " << "$" << std::setprecision(2) << salary << std::endl;
	std::cout << std::setw(indentation) << std::left << "Date of hire: " << std::setw(0);
	DateOfHire.printDate();
}
