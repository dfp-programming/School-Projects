/*Hello!!

This program is useful for someone managing a group of rental units and would like to know the amount of rent to charge that will result in the most profit.
The user will be prompted to input the number of units managed, rent amout when all units remain occupied (lowest rent), 
and the increase in rent that will make one tenant leave,as well as the maintenance cost per unit.
The program will tell you how manu units to rent for maximum profit. 

I hope you like my program.I spent a lot of time trying different types of loops to obtain the right result.
In the end i chose to use all the FOR loop even thought i could get it to work with the WHILE, and DO WHILE loop as well.
 
Diego F. Perez - CPS171, section D01 - MACHINE PROBLEM 3. */


#include <iostream>
#include <fstream>
using namespace std;

int main() {
	
	//Declaring variables
	int totalUnits{0}; 
	double rent{0.0}, rentIncreaseFactor{0.0}, maintFee {0.0}, profit{0.0}, profitTemp{0.0};
	
	//creating an objet to write to file. 
	ofstream writeToFile("max_profit_units.txt");
	
	//Getting user input
	cout << "Enter the total number of rental units" << endl;
	cout << "\t";
	cin >> totalUnits;
	
	cout << "\nRent amount to occupy all units" << endl;
	cout << "\t" << '$';
	cin >> rent; 
	
	cout << "\nIncrease in rent to vacate one unit" << endl;
	cout << "\t" << '$';
	cin >> rentIncreaseFactor;
	
	cout << "\nMaintenance cost per rental unit" << endl;
	cout << "\t" << '$';
	cin >> maintFee;
	
	//calculate profit during maximum occupancy.
	profit = (totalUnits*rent)-(totalUnits*maintFee);
		
	//calculating the maximum profit and maximum rent amount through a FOR loop. This also gives me the amount of units to be rented
	for(int count = totalUnits-1; count>0; count--){
				
		profitTemp=profit;
		rent+=rentIncreaseFactor;
		profit=rent*count;
		
		if(profitTemp>=profit){
		profit=profitTemp;
		totalUnits=count;
		break;
		}
	}
	
	//writing rent for max profit to file, and closing it. 
		
	writeToFile  << "Number of units rented for maximum profit: " << totalUnits << endl;
	writeToFile.close();
			
	return 0;
}
