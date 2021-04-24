#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_RESOLUTION = 1000000;

class Fraction {

	double long numerator;
	int long denominator;

public:
	int long LCM;

	Fraction();	

	int simplify();
	int get_Data();
	void set_Numerator(double long);
	void set_Denominator(long int);
	double long print_Numerator();
	int long print_Denominator();
	string printFraction();
	int long findLCM(int long, int long);

	Fraction operator + (const Fraction&);
	Fraction operator - (const Fraction&);
	Fraction operator * (const Fraction&);
	Fraction operator / (const Fraction&);
	Fraction &operator ++ ();
	Fraction &operator -- ();
	Fraction &operator += (Fraction&);
	Fraction& operator -= (Fraction&);
	Fraction& operator *= (Fraction&);
	Fraction& operator /= (Fraction&);
	bool operator == (const Fraction&);
	bool operator != (const Fraction&);
	bool operator > (const Fraction&);
	bool operator < (const Fraction&);
	bool operator >= (const Fraction&);
	bool operator <= (const Fraction&);
	Fraction operator ^ (Fraction&);
};

class Choice {

public:
	Choice();
	void myChoice(Fraction*, Fraction*);
};



