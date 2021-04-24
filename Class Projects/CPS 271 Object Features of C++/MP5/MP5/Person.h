#pragma once
#include <iostream>
#include <string>
#include "MyDate.h"
#include "getNumbers.h"

const int indentation = 25;

class Person
{
	std::string fullName, phoneNumber, email;
	MyDate birthday;

public:
	Person();

	void setData();
	void printData();

};

