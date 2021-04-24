/*Hello! this program has a very simple use.  It prompts the user to enter a value in centimeters.
The value then gets converted to meters, shown to the user, and used to calculate: the area of a circle,
the area of a square, the differecen between the square and circle area, and the volume of a cube when the value is rounded down or up.
Although not mentioned as a requirement, I added error checking in case the user wants to enter a negative number. I hope you enjoy this program.

Created by Diego F. Perez for CPS171, on 14th of September, 2019 - MACHINE PROBLEM 1*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	float geoLength_cm{ 0 };													//variable to store the user's input.
	float squareArea{ 0 }, circleArea{ 0 }, cubeVol_up{ 0 }, cubeVol_down{ 0 };	//Variables used for calculations. 

	//Program introduction and prompting the user to enter a number.
	cout << "Volume and Area Calculator by Diego F. Perez\n";
	cout << endl;
	cout << "Enter the floating-point value for the length in centimeters of the square, cube, or circle diameter.\n";
	cout << endl << "\t", cin >> geoLength_cm;

	//Declaring variable to store and convert the user's input to meters. Using abs() to correct negative values. 
	float geoLength_m{ abs(geoLength_cm / 100) };

	//Echo user's input and converted value into meters.
	cout << "\nYou've entered " << abs(geoLength_cm) << "cm, which is equivalent to " << geoLength_m << "m\n" << endl;

	squareArea = geoLength_m * geoLength_m;							// calculates the area of the square lenght*lenght
	circleArea = 3.14159 * ((geoLength_m / 2) * (geoLength_m / 2));	// calculates area of the circle pi*radius^2. radius=diameter/2

	//Output the results. I used the abs() function to ensure it could never be negative.
	cout << "the area of a square is: " << setw(60) << squareArea << " square meters\n";
	cout << "the area of a circle is: " << setw(60) << circleArea << " square meters\n";
	cout << "The area difference between circle and square is: " << setw(35) << abs(circleArea - squareArea) << " square meters\n";

	//Rounding down and up geoLenght_m using floor() and ceil(). Then storing the value in variables for cube volume calculation.
	cubeVol_up = ceil(geoLength_m);
	cubeVol_down = floor(geoLength_m);

	//Calculation and output of the two different cube volumes. Using setw() to ensure long number inputs don't affect placement. 
	cout << "the volume of a cube when " << setw(12) << geoLength_m << "m is rounded down: " << setw(28) << (cubeVol_down*cubeVol_down*cubeVol_down) << "  cubic meters\n";
	cout << "the volume of a cube when " << setw(12) << geoLength_m << "m is rounded up: " << setw(30) << (cubeVol_up*cubeVol_up*cubeVol_up) << "  cubic meters\n";

	return 0; 
}

