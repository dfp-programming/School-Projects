#include "getNumbers.h"

int getNumbers::getInt()
{
	int numb(-1);

	while (1)
	{
		try {

			std::cin >> numb;

			if (!std::cin.good())
			{
				throw 1;
			}

			std::cin.clear();
			return numb;

		}
		catch (int error)
		{

			if (error == 1)
			{
				std::cout << "INVALID DATA" << std::endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				numb = -1;
				continue;
				continue;
			}

		}
	}

}

int getNumbers::getInt(int lowRange, int highRange)
{
	int numb(-1);

	while (1)
	{
		numb = getInt();

		if (numb < lowRange || numb > highRange)
		{
			std::cout << "VALUE OUT OF RANGE" << std::endl;
			numb = -1;
			continue;
		}

		if (numb >= lowRange && numb <= highRange)
		{
			return numb;
		}
		continue;
	}
}

double long getNumbers::getDouble()
{
	double long decimalNum(0);

	while (1)
	{
		try {

			std::cin >> decimalNum;

			if (!std::cin.good())
			{
				throw 1;
			}

			std::cin.clear();
			return decimalNum;

		}
		catch (int error)
		{
			if (error == 1)
			{
				std::cout << "INVALID DATA" << std::endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				decimalNum = -1;
				continue;
			}
		}
	}


}

double long getNumbers::getDouble(double lowRange, double highRange)
{
	double decimalNum(0);

	while (1)
	{
		decimalNum = getDouble();
		
		if (decimalNum < lowRange || decimalNum > highRange)
		{
		std::cout << "VALUE OUT OF RANGE" << std::endl;
		decimalNum = -1;
		continue;
		}

		if (decimalNum >= lowRange && decimalNum <= highRange)
		{
			return decimalNum;
		}
		continue;
	}
}
