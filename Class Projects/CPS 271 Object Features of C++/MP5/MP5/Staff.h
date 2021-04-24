#pragma once
#include "Employee.h"
class Staff :
	public Employee
{
	std::string title;

public:

	Staff();

	void setData();
	void printData();
	
};

