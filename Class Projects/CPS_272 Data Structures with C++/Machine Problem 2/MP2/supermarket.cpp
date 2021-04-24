#include "supermarket.h"

std::string supermarket::timeStamp()
{
	//time stamp using the chrono's class system clock, stores into a time_point objet, then converted to a time_t object, which is then converter to a string using the ctime() function. 
	std::chrono::time_point<std::chrono::system_clock> _now = std::chrono::system_clock::now();
	std::time_t _time = std::chrono::system_clock::to_time_t(_now);
	return ctime(&_time);
}


void supermarket::customersArrive()
{
	int temp = 0;

	while (simulate)
	{
		temp = (rand() % timer1 + 1);

		checkoutLine.push(rand()); //this is just to push a number into each place in the queue.  Not really significant to the simulation.  
		++arrivalsCount;

		//if other function is printing, wait until it releases the stream
		while (synch)
			std::this_thread::sleep_for(std::chrono::milliseconds(10));

		synch = true;
		std::cout << "Customer at checkout line  => " << timeStamp();
		std::cout << "Time until next customer = " << temp << " mins" << std::endl;
		std::cout << "Line length: " << checkoutLine.size() << "\n" << std::endl;
		synch = false;

		//this line of code only works with chrono.  The idea is to make the function wait temp amount of minutes until the next iteratoion, provided the simulation varible == true. 
		std::this_thread::sleep_for(std::chrono::minutes(temp));
	}



}

void supermarket::customersLeave()
{
	int temp = 0;

	while (simulate)
	{
		temp = (rand() % timer2 + 1);
		
		if (!checkoutLine.empty())
		{
			std::this_thread::sleep_for(std::chrono::minutes(temp)); // wait temp amount of mimutes before reducing the size of the queue
			checkoutLine.pop();
			++departuresCount;

			//if other function is printing, wait until it releases the stream
			while (synch)
				std::this_thread::sleep_for(std::chrono::milliseconds(10));

			synch = true;
			std::cout << std::setw(50) << " " << std::left << "Customer left => " << timeStamp();
			std::cout << std::setw(50) << " " << std::left << "Process Time = " << temp << " mins" << std::endl;
			std::cout << std::setw(50) << " " << std::left << "Line length: " << checkoutLine.size() << "\n" << std::endl;
			synch = false;

		}


	}
}
//function to get data from user
int supermarket::getInteger(int lowRange, int highRange)
{
	int myInt(0);

	try
	{
		std::cin >> myInt;
		if (std::cin.fail())
			throw ("Not an integer.\n");

		if (myInt < lowRange || myInt > highRange)
			throw ("Input out of range.\n");
	}
	catch (const char* message)
	{
		std::cin.ignore(INT_MAX, '\n');
		std::cin.clear();

		std::cout << message << std::endl;
		return 0;
	}

	return myInt;
}

void supermarket::stopSimulation()
{
	simulate = false;
}
int supermarket::getCustomerCount()
{
	return arrivalsCount;
}
int supermarket::getDeparturesCount()
{
	return departuresCount;
}
