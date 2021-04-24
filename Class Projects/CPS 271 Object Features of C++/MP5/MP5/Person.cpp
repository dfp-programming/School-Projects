#include "Person.h"

Person::Person()
{
	fullName = "invalid name";
	phoneNumber = "0-000-000-0000";
	email = "no email on file";
}

void Person::setData()
{
	std::cout << "Full Name: ";
	getline(std::cin, fullName);
	std::cout << "Date of Birth: ";
	birthday.setDate();
	std::cin.clear();
	std::cin.ignore();
	std::cout << "Telephone Number: ";
	getline(std::cin, phoneNumber);
	std::cout << "Email Address ";
	getline(std::cin, email);
}

void Person::printData()
{
	std::cout << std::setw(indentation) << std::left << "Full Name: " << fullName << std::endl;
	std::cout << std::setw(indentation) << std::left << "Date of Birth: ";
	birthday.printDate();
	std::cout << std::setw(indentation) << std::left << "Telephone Number: " << phoneNumber << std::endl;
	std::cout << std::setw(indentation) << std::left << "Email Address: " << email << std::setw(0) << std::endl;

}
