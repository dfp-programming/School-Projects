/* Machine Problem 1.cpp : This file contains the 'main' function. Program execution begins and ends there.

Hello! this program has a very simple use.  It prompts the user to enter a value in centimeters. 
The value then gets converted to meters, shown to the user, and used to calculate: the area of a circle,
the area of a square, the differecen between the square and circle area, and the volume of a cube when the value is rounded down or up.
Although not mentioned as a requirement, I added error checking in case the user wants to enter a negative number. I hope you enjoy this program.  

Created by Diego F. Perez for CPS171, on 14th of September, 2019 - MACHINE PROBLEM 1*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

//I made a function to calculate a cube's volume given the length its side.  This function gets used later.  
float cubeVolume(float cubeSide)
{
	float cubeVolume = cubeSide * cubeSide * cubeSide; //cube's volume = side^3
	return cubeVolume;
}

//Now to the actual program.
int main()
{
	float geoLength_cm{ 0 };										//variable to store the user's input. Initialized to 0
	float squareArea{ 0 }, circleArea{ 0 };	//variables needed to store area calculations. All initialized to 0.

	//The following lines introduce the program, and prompt the user to enter a number to be stored.
	cout << "Volume and Area Calculator by Diego F. Perez\n";
	cout << endl;
	cout << "Enter the floating-point value for the length in centimeters of the square, cube, or circle diameter.\n";
	cout << endl << "\t", cin >> geoLength_cm;

	if (geoLength_cm < 0.0)
		{
			geoLength_cm = (geoLength_cm * -1);
			cout << endl << "You meant a positive number, right?. I have multiplied by -1" << endl;
		}
	
	//Declaring variable to store and convert the user's input to meters.
	float geoLength_m{ geoLength_cm / 100 };
	
	//Showing the user's input and its converted value into meters.
	cout << "\nYou've entered " << geoLength_cm << "cm, which is equivalent to " << geoLength_m << "m\n" << endl;

	squareArea = geoLength_m * geoLength_m;// calculates the area of the square lenght*lenght
	circleArea = 3.14159 * ((geoLength_m/2) * (geoLength_m/2));// calculates area of the circle pi*radius2. radius=diameter/2
	
	//output the results.  I used the abs() function to ensure it could never be negative.
	cout << "the area of a square is: " << setw(60) << squareArea << " square meters\n";
	cout << "the area of a circle is: " << setw(60) << circleArea << " square meters\n";
	cout << "The area difference between circle and square is: " << setw(35) << abs(circleArea- squareArea) << " square meters\n";

	/*for the cube volume, first wee need to round down and up the geoLenght_m variable. This can be done with ceil() and floor().
	I used those functions inside the function I created at the beginning of the program, which calculates the volume of the cube*/
	cout << "the volume of a cube when " << setw(12) <<geoLength_m << "m is rounded down: " << setw(28) << cubeVolume(floor(geoLength_m)) << "  cubic meters\n";
	cout << "the volume of a cube when " << setw(12) << geoLength_m << "m is rounded up: " << setw(30) << cubeVolume(ceil(geoLength_m)) << "  cubic meters\n";
	return 0;
}

