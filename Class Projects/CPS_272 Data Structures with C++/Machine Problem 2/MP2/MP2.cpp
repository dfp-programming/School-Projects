#include "supermarket.h"

//This is a program to simulate customers arriving to a checkut line at random intervals, and then being serviced at random intervals as well. 
//The idea is to allow the program to run for X out of time and see how cashier performance affect line lenght.  
//To achieve this simulation, I created a supermarket class that simulates customer's arriving and leaving by calling respective functions.  
//The functions are then called through a threads and executed in realtime. 
// Diego F. Perez CPS 272 29SEP2020



//This function is used to get data for simulation lenght and other parameters. 
void getData(int &time, int &timeInterval1, int &timeInterval2) 
{
		std::cout << "Welcome to the supermarket checkout line simulation\n";
		std::cout << "Please choose the simulation runtime. min=5 max=1000 mins. - An invalid input will abort the program\n";
		time = supermarket::getInteger(5, 1000);
		if (time == 0)
			exit(0);

		std::cout << "What is the checkout line variation interval? min=1 max=10 mins - An invalid input will abort the program\n";
			timeInterval1 = supermarket::getInteger(1, 1000);
			if (timeInterval1 == 0)
				exit(0);

			std::cout << "What is the cashier service time variation interval? min=1 max=10 mins - An invalid input will abort the program\n";
			timeInterval2 = supermarket::getInteger(1, 1000);
			if (timeInterval2 == 0)
				exit(0);
				
		std::cout << "\n****************************************** SIMULATION START ***********************************************\n\n" << std::endl;
}


int main()
{
	int timer = 0, timeInterval1 = 0, timeInterval2 = 0;
	
	getData(timer, timeInterval1, timeInterval2);

	//seeding the rand()
	srand(time(0));

	//creating the function pointers
	supermarket* PTR1 = new supermarket(timeInterval1, timeInterval2);
		
	//It took me a while to find this syntax: thread( &class::function, pointer_to_the_class, arguments_if_any). 
	std::thread thread1(&supermarket::customersArrive, PTR1);
	std::thread thread2(&supermarket::customersLeave, PTR1);
	
	std::this_thread::sleep_for(std::chrono::minutes(timer));
	PTR1->stopSimulation(); //This function does not stop the simulation on its tracks, but allows the respective functions to come to an end properly. 
		
	thread1.join();  // if you forget to do this, the program will not run right for no apparent reason.  Timers wont work, etc. 
	thread2.join();

	std::cout << "\n****************************************** SIMULATION END ***********************************************\n\n" << std::endl;
	std::cout << "Total number of customers: " << PTR1->getCustomerCount() << std::endl;
	std::cout << "Total number of serviced customers: " << PTR1->getDeparturesCount() << std::endl;


	delete PTR1;


}
