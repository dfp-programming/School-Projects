#include <iostream>
#include "Student.h"
#include "Office.h"
#include "Faculty.h"
#include "Staff.h"
#include "getNumbers.h"
#include <vector>

int main()
{
	std::cout << "Welcome to MP5, a program meant to store and collect data on people, that will probably be sold to marketing companies." << std::endl;
	std::cout << "You will have no say in the matter, but I will make money from you anyways. I hope you enjoy it!!\n" << std::endl;

	int *choice(new int);

	Student* studentPtr = new Student;
	Faculty* facultyPtr = new Faculty;
	Staff* staffPtr = new Staff;

	std::vector <Student> WCC_Students{ 1 };
	std::vector <Faculty> WCC_Faculty { 1 };
	std::vector <Staff> WCC_Staff{ 1 };
	Office secondFloorOffices(2, 10);//10 offices in the second floor

	while (1)
	{
		std::cout << "\n1. New Student   2. New Faculty   3. New Staff   4. Print All   5. Quit" << std::endl;

		*choice = getNumbers::getInt(1, 5);
		std::cin.clear();
		std::cin.ignore();

		switch (*choice)
		{
		case 1:
			WCC_Students[WCC_Students.size() - 1].setData();
			WCC_Students.push_back(*studentPtr); //add one blank student
			break;
		case 2:
			WCC_Faculty[WCC_Faculty.size() - 1].setData(secondFloorOffices); // add an office while supplies last. 
			WCC_Faculty.push_back(*facultyPtr); // add one blan faculty member
			break;
		case 3:
			WCC_Staff[WCC_Staff.size() - 1].setData();
			WCC_Staff.push_back(*staffPtr); // add one blank staff member
			break;
		case 4:

			for (int i = 0; i < (WCC_Students.size()-1); i++)
			{
				WCC_Students[i].printData();
			}

			for (int i = 0; i < (WCC_Faculty.size()-1); i++)
			{
				WCC_Faculty[i].printData(secondFloorOffices);
			}

			for (int i = 0; i < (WCC_Staff.size()-1); i++)
			{
				WCC_Staff[i].printData();
			}
			break;
		case 5:

			return 0;
		}
	}
}
