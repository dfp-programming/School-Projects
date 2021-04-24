/*Hello!!

This program is useful for someone managing a group of rental units. The user would like to know the amount of rent to charge that will result in the most profit.
The user will be prompted to input the number of units managed, rent amout when all units remain occupied (lowest rent), 
and the increase in rent that will make one tenant leave,as well as the maintenance cost per unit.
The program will tell you how much rent to charge, how many units will be occupied for max. profit, the raw and net profit, as well as the total expenses. 

I hope you like my program.I spent a lot of time trying different types of loops to obtain the right result.
In the end i chose to use all the FOR loop even thought i could get it to work with the WHILE, and DO WHILE loop as well.
 

Diego F. Perez - CPS171, section D01 - MACHINE PROBLEM 3. */


#include <iostream>
#include <fstream>
using namespace std;

int main() {
	
	//Declaring variables
	int totalUnits{0}; 
	double rentTotalOccupancy{0.0}, rentIncreaseFactor{0.0}, maintFee {0.0}, profit{0.0}, profitTemp{0.0};
	
	//creating an objet to write to file. 
	
	ofstream writeToFile("max_profit_rent.txt");
	
	//Getting user input
	
	cout << "Enter the total number of rental units" << endl;
	cout << "\t";
	cin >> totalUnits;
	
	cout << "\nRent amount to occupy all units" << endl;
	cout << "\t" << '$';
	cin >> rentTotalOccupancy; 
	
	cout << "\nIncrease in rent to vacate one unit" << endl;
	cout << "\t" << '$';
	cin >> rentIncreaseFactor;
	
	cout << "\nMaintenance coost per rental unit" << endl;
	cout << "\t" << '$';
	cin >> maintFee;
	
	//calculate and output profit during maximum occupancy.
	profit = (totalUnits*rentTotalOccupancy)-(totalUnits*maintFee);
	cout << "\nNet profit during maximum occupancy:" << endl;
	cout << "\t$" << profit << "\n" << endl;
	
	//calculating the maximum profit. 
	
	totalUnits--;
	for(totalUnits;totalUnits>0;totalUnits--){
		
	//	cout<<"******" << totalUnits <<endl;
		
		profitTemp=profit;
	//	cout << profitTemp << endl;
		
		rentTotalOccupancy+=rentIncreaseFactor;
	//	cout << rentTotalOccupancy << endl;
		
		profit=rentTotalOccupancy*totalUnits;
	//	cout << profit << endl;
		
		if(profitTemp>=profit){
		profit=profitTemp;
		break;
		}
	}
	
		
	//stating different calculation results
	
	writeToFile  << "Rent amount for maximum profit: $" << rentTotalOccupancy << endl;
	writeToFile.close();
	
	cout << "Rent amount for maximum profit:" << endl;
	cout << "\t$" <<rentTotalOccupancy << endl;
	
	cout << "\nOccupancy for maximum profit: "<< endl;
	cout << "\t" <<totalUnits << endl;
	
	cout << "\nTotal expenses:" << endl;
	cout << "\t$" <<maintFee*totalUnits << endl;
	
	cout << "\nRaw profit:" << endl;
	cout << "\t$" << profit<< endl;
	
	cout << "\nNet profit:" << endl;
	profit -=  (maintFee*totalUnits);
	cout << "\t$" << profit<< endl;
		
	return 0;
}
