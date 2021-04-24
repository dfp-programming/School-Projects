

//this class is used to simulate a supermarket cashier line, and see how different time variables affect the line lenght. 
//this class is meant to be run using threads in main which call the customersArrive and customersLeave functions. 
//Diego F. Perez CPS272 29SEP2020



#pragma once
#include <iostream>
#include <thread>
#include <queue>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <time.h>




class supermarket
{

	std::queue<int> checkoutLine;
	bool simulate, synch; //simulate is used to terminate the simulation, and synch is to keep two functions from printing at the same time. 
	int timer1, timer2, arrivalsCount, departuresCount;  
	
	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;

public:

	supermarket(int &x, int &y)
	{
		simulate = true;
		synch = false;
		timer1 = x;
		timer2 = y;
		arrivalsCount = 0;
		departuresCount = 0;
	}

	std::string timeStamp(); //used to return a string with the current time
	void customersLeave(); //customers leave the queue if not empty
	void customersArrive(); //add customers
	int static getInteger(int,int);  //gathers data from the user for simulation purposes
	void stopSimulation(); 
	int getCustomerCount();
	int getDeparturesCount();

};

