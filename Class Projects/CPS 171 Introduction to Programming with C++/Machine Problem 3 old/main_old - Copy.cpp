#include <iostream>
#include <fstream>
using namespace std;


int main() {

//Declaring variables now
int totalUnits{50};
double rentTotalOccupancy{600.0}, rentMaxProfit{0},rentIncreaseFactor{40.0}, maintFee {27.0}, maxProfit{0}, maxProfitTemp{0};

//Getting user input

cout << "Enter the total number of rental units" << endl;
cout << totalUnits << endl; //this will be changed to cin to get user input

cout << "Enter the rent amount to occupy all units" << endl;
cout << rentTotalOccupancy<< endl; //this will be changed to cin to get user input

cout << "Enter the increase in rent to vacate one unit" << endl;
cout << rentIncreaseFactor<< endl; //this will be changed to cin to get user input

cout << "Enter the amount required to mantain one rental unit" << endl;
cout << maintFee << "\n" <<endl; //this will be changed to cin to get user input

//I want to calculate the profit when all units are rented out
cout << "When all units are rented, the profit is: "<< (totalUnits*rentTotalOccupancy)-(totalUnits*maintFee) << "\n" << endl;

rentMaxProfit = rentTotalOccupancy; //Let's assume the most lucrative rent is the same as max occupancy rent.  Not right, but just to start.
maxProfit = (totalUnits*rentTotalOccupancy)-(totalUnits*maintFee);   //let's assume maximum occupancy equals max profit. Not right but this is a good start.


while(maxProfit>=maxProfitTemp){

//The following cout statements are simply to track the progress of the loop before calculations
cout <<"************************************************************************** "<< endl;
cout <<"max profit temp is: "<< maxProfitTemp<<endl;
cout <<"max profit is: " << maxProfit << endl;
cout <<"rent for maximum profit is: " << rentMaxProfit << endl;
cout << "units occupied for maximum profit: "<< totalUnits << "\n"<< endl;

--totalUnits; // decrease the unit count by one
maxProfitTemp = maxProfit; // I need to save the maximum profit value into a temp variable for comparison purposes
rentMaxProfit = rentMaxProfit + rentIncreaseFactor; //Adding the rent factor to the rent
maxProfit = (totalUnits*rentMaxProfit);//-(totalUnits*maintFee);


//The following cout statements are simply to track the progress of the loop after calculations
cout <<"max profit temp is: "<< maxProfitTemp<<endl;
cout <<"max profit is: " << maxProfit<<endl;
cout <<"rent for maximum profit is: " << rentMaxProfit<<endl;
cout << "units occupied for maximum profit: " << totalUnits << "\n"<<endl;

}

cout <<"**************************** Final result **************************************\n "<<endl;
cout << "rent amount for maximum profit " << rentMaxProfit << endl;
cout << "rent was increased by " << rentMaxProfit-rentTotalOccupancy << endl;
cout << "amount of units occupied for maximum profit " << totalUnits << endl;
cout << "maximum profit " << maxProfit << endl;

return 0;
}
