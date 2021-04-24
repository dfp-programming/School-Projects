#pragma once
#include "stringPattern.h"

class baseConverter
{
	int number, base, tempNumber;
	char baseArray[16]; //this one is necessary so that when you output the numbers, the value will match the type of base.
	std::stack<int> reminder;
	std::string conversion;

public:

	baseConverter()
	{
		number = 0;
		base = 0;
		tempNumber = 0;
		conversion.empty();

		//filling the array.  This loop is easier to type than hard coding the array. 
		for (int i = 0; i < 16; i++)
		{
			if (i < 10)
				baseArray[i] = i + 48;
			if (i >= 10)
				baseArray[i] = i + 55;
		}
	}

	int static getInteger(int lowRange, int highRange);
	void multibaseOutput();

};

