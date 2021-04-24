#include "MyDate.h"

MyDate::MyDate()
{
	year = 0,
	month = 0;
	day = 0;
	hour[0] = "00:00";
	hour[1] = "00:00";
	taken = false;
}

void MyDate::getDay()
{
	//Not all months have 31 days, This this method does not check for leap year, and it is up to the user.
	if (month == 2)
	{
		std::cout << "Month = " << month << std::endl;
		day = getNumbers::getInt(1, 29);
	}

	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		std::cout << "Month = " << month << std::endl;
		day = getNumbers::getInt(1, 30);
	}

	else day = getNumbers::getInt(1, 31);
}

void MyDate::setDate()
{

	std::cout << "Year ";
	year = getNumbers::getInt(0,2020);

	std::cout << "Month ";
	month = getNumbers::getInt(1,12);

	std::cout << "Day ";
	getDay();
}

void MyDate::setTime()
{
	int tempHour(0), tempMin(0);

	std::cout << "Opening Hour(0-23) ";
	tempHour = getNumbers::getInt(0, 23);

	std::cout << "Minutes (0-59)";
	tempMin = getNumbers::getInt(0, 59);

	if (tempHour <= 9) 
	{
		hour[0] = "0" + std::to_string(tempHour) + ":";
	}
	if (tempHour > 9)
	{
		hour[0] = std::to_string(tempHour) + ":";
	}
	if (tempMin <= 9)
	{
		hour[0] += "0" + std::to_string(tempMin);
	}
	if (tempMin > 9)
	{
		hour[0] += std::to_string(tempMin);
	}
		
	//hour[0] = std::to_string(tempHour)+ ":" + std::to_string(tempMin);
	
	std::cout << "Closing Hour(0-23) ";
	tempHour = getNumbers::getInt(0, 23);

	std::cout << "Minutes (0-59)";
	tempMin = getNumbers::getInt(0, 59);

	if (tempHour <= 9)
	{
		hour[1] = "0" + std::to_string(tempHour) + ":";
	}
	if (tempHour > 9)
	{
		hour[1] = std::to_string(tempHour) + ":";
	}
	if (tempMin <= 9)
	{
		hour[1] += "0" + std::to_string(tempMin);
	}
	if (tempMin > 9)
	{
		hour[1] += std::to_string(tempMin);
	}

	//hour[1] = std::to_string(tempHour) + ":" + std::to_string(tempMin);

	taken = true;

}

//use this method only if you wan to free up the time.  
void MyDate::resetTime()
{
	hour[0] = "--:--";
	hour[1] = "--:--";
	taken = false;
}

void MyDate::printDate()
{
	std::cout << std::setw(2) << std::setfill('0') << std::right << day << std::setw(0) << "/" << std::setw(2) << month << std::setw(0) << "/" << std::setw(4) <<  year << std::setw(0) << " ";
	std::cout << "_dd/mm/yyyy " << std::setfill(' ') << std::endl;
}

void MyDate::printTime()
{
	std::cout << " Opens " << hour[0] << " Closes " << hour[1]  << " hh:mm ";
}

bool MyDate::busyOrFree()
{
	return taken;
}
