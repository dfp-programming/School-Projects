#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class get_Numbers_Safely {

	string alarm1, alarm2, alarm3, alarm4;
	double long number;
	int temp_Number;

public:

	get_Numbers_Safely();

	double long get_Number(int low_Range, int high_range, char check_Range, char check_Zero, char allow_Decimal);


};

class Fraction {

	double long numerator;
	int long denominator;

public:	
	
	Fraction();
		
	void get_Data(get_Numbers_Safely my_Int);
	
	double long print_Numerator();

	int long print_Denominator();

};

class Fraction_Math {
		
	//I made the denominator a double long so I could work with bigger numbers, but it will still be threated as integer
	double long numerator_, rounded_Num_, denominator_;
	int long  whole_number_, temp_Num, temp_Den;

public:

	Fraction_Math();

	void add(Fraction fraction1, Fraction fraction2);

	void substract(Fraction fraction1, Fraction fraction2);

	void multiply(Fraction fraction1, Fraction fraction2);

	void divide(Fraction &fraction1, Fraction &fraction2);

	int long simplify();
};


