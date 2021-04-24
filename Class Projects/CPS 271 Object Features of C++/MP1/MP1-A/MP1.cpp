//Hello! 
//
//It gives the user 3 choices, and it explains what each choices does.
//I was unsure what to do with the 3 option, so I decided to give tell the user what happened by printing to the console. 

//I hope you like my program.
//
//Machine Problem 1 - first half of the assignment
//Diego F. Perez - CPS 271-D01
//January 19, 2020.


#include <iostream>
#include <iomanip>
using namespace std;

string alarm1{ "ERROR 01 - NOT A VALID CHOICE\n" }, alarm2 { "ERROR 02 - INVALID DATA\n" },  alarm3{ "ERROR 03 - NEGATIVE NUMBERS NOT ALLOWED\n" };


//power function to elevate a number to the power of another.
double long power(double base, int exponent) {
		
	double long result = base;
	
	//Any number to the power of 0 equals 0.
	if (exponent == 0) result = 0;
					
	else {

		for (int i = 1; i < exponent; i++) {

			result *= base;
		}
	}

	return result;

}

//This functions converts hours and mins to seconds. 
double long hms_to_secs(double long hours, double long mins, double long secs) {
		
	//Time should never be negative, so I am using abs to make sure it stays that way, and to not mess with the sum. 
	hours = abs(hours * 3600);
	mins = abs(mins * 60);
	return (hours + mins + abs(secs));

}

//this function swaps two values by reference.
void swap(double long& valueA, double long& valueB) {

	double long swap_{ 0.0 };

	swap_ = valueB;
	valueB = valueA;
	valueA = swap_;
	
}

//function to get an integer input without error. 
int getInteger(int doSomethingElse) {

	// doSomethingElse == 0, then prints main menu and only takes numbers 1-4
	// doSomethingElse != 0, it will allow any integer

	int  number;

	// main menu
	if (doSomethingElse == 0) {
		cout << setw(50) << right << "Please chose one of the following options\n" << endl;
		cout << setw(30) << left << "1 for the POWER function.";
		cout << setw(30) << left << "2 to convert HH:MM:SS to seconds." << endl;
		cout << setw(30) << left << "3 to swap two values.";
		cout << setw(30) << left << "4 to abort.\n" << endl;
	}

	//error checking
	while (1) {

		try {

			cout << "\t";
			cin >> number;

			if (cin.fail())
				throw 2;   //invalid data

			if (doSomethingElse == 0) {
				if (number <= 0 || number > 4)
					throw 1;	//not a valid choice

				if (number > 0 || number < 4) {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					return number;
				}
			}

			if (doSomethingElse != 0) {
				if (number < 0)
					throw 3;	//negative numbers not allowed

				if (number > 0) {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					return number;
				}
			}
		}
		catch (const int error) {

			if (error == 1) {
				cout << alarm1;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				continue;
			}

			if (error == 2) {
				cout << alarm2;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				continue;
			}

			if (error == 3) {
				cout << alarm3;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				continue;
			}
		}
	}

}
		

//function to get an decimal input without error. 
double long getDecimal() {

	double long  number{ 0 };
	while (1) {

		try {

			cout << "\t";
			cin >> number;

			if (cin.fail())
				throw 2;   //invalid data

			else {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				return number;
			}
		}
		catch (const int error) {

			if (error == 2) {
				cout << alarm2;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				continue;
			}
		}
	}
}

int main() {

		//variables used for deciding what to do
		float whatToDo{ 0 };

		//POWER function variables
		double base{ 0.0 };
		int exponent{ 2 };

		//hms_to_secs Variables
		double long hours{ 0.0 }, mins{ 0.0 }, secs{ 0.0 };

		//swap variables
		double long valueA{ 0.0 }, valueB{ 0.0 };

		cout << "Machine Problem 1 - Diego F. Perez\n" << endl;

		do {

			whatToDo = getInteger(0);

			if (whatToDo == 1) {
				cout << "\n\t\tPOWER function!" << endl;
				
				cout << "\nEnter a number for the base:\t";
				base=getDecimal();
							
				cout << "Enter the exponent:\t\t";
				exponent = getInteger(1);
				
				cout << base << " to the power of " << abs(exponent) << " is:  \t\t" << power(base, exponent) << "\n" << endl;
				continue;
			}

			if (whatToDo == 2) {

				while (hours >= 0) {

					hours = 0.0;
					mins = 0.0;
					secs = 0.0;

					cout << "\n\tHH:MM:SS to seconds. Input a negative value to abort.\n" << endl;

					//Time should never be negative, so if the user enters a negative value it will abort the loop.

					cout << "Enter the hours \t";
					hours= getDecimal();
					if (hours < 0) {
						cout << "You have entered a negative value.\n" << endl;
						hours = 0;
						break;
					}

					cout << "Enter the minutes \t"; 
					mins = getDecimal();
					if (mins < 0) {
						cout << "You have entered a negative value.\n" << endl;
						break;
					}

					cout << "Enter the seconds \t"; 
					secs = getDecimal();

					if (secs < 0) {
						cout << "You have entered a negative value.\n" << endl;
						break;
					}

					cout << "\n" << hours << ':' << mins << ':' << secs << " is equivalent to " << hms_to_secs(hours, mins, secs) << " seconds." << endl;


				}

				continue;
			}
			if (whatToDo == 3) {

				cout << "\t\tSwap two values!\n" << endl;
					
				cout << "Enter the first value \"A\" " << endl;
				//cout << "\t";
				valueA = getDecimal();
				
				cout << "Enter the second value \"B\" " << endl;
				//cout << "\t"; 
				valueB = getDecimal();

				swap(valueA, valueB);

				cout << "Now A is " << valueA << " and B is " << valueB << " . Thank you!\n" << endl;

				continue;
			}
						
		} while (whatToDo != 4);
		
	return 0;

}