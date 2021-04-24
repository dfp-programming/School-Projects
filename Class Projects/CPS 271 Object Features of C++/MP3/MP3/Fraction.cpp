#include "fraction.h"

Fraction::Fraction() 
{
	numerator = 0;
	denominator = 1;
	LCM=1;
}

int Fraction::simplify()
{
	int resolution = MAX_RESOLUTION;
	int long rounded_Num_(0), temp_Den(0), temp_Num(0);

//Using ceil() or floor() is not good because if not a decimal, then the value goes up/down by 1. static_cast works well to take out decimals. 
	rounded_Num_ = static_cast<int long> (numerator);

//If numerator==0, the fraction must be leave fraction alone.  
	if (numerator==0)
	{
		return 0;
	}

//If numerator==denominator, the fraction must be 1/1
	if (denominator == numerator)
	{
		numerator = 1;
		denominator = 1;
		return 0;
	}

//If both members are negative, the fraction becomes positive.
	if(numerator<0 && denominator<0)
	{
		denominator *= -1;
		numerator *= -1;
	}

// if rounded_Num is less than numerator, then numerator must be a decimal.  If so, conver the fraction to integers.
	if (abs(rounded_Num_) < abs(numerator)) 
	{
		//multiply both numerator and denominator by 10, then check if numerator is still decimal. If not longer decimal, then break
		for(int i = 1; i <= resolution ; )
		{
			numerator *= 10;
			denominator *= 10;
			
			//doing this takes away unwanted decimals, but by dividing the resolution by 10 everytime,
			//We can dynamically control the max amount of decimals, and take away less decimals everytime.
			//This way we can miminize the amount of unwanted decimals even further
			numerator = floor(numerator * resolution) / resolution;
			denominator = floor(denominator * resolution) / resolution;

			resolution /= 10;

			if (ceil(numerator) - floor(numerator) != 1) {
				break;
			}
		}
	} 

//simplying the fraction
	temp_Den = abs(denominator);
	temp_Num = abs(numerator);

	for (int i = 2; i <= denominator; i++)
	{
		if ((temp_Num % i == 0) && (temp_Den % i == 0))
		{
			temp_Num /= i;
			temp_Den /= i;
		}
	}

	if (numerator < 0) temp_Num *= -1;
	if (denominator < 0) temp_Den *= -1;
	numerator = temp_Num;
	denominator = temp_Den;

}

int Fraction::get_Data()
{
	string latentFraction = "0/1";
	int charInt(-2), theMiddle(-2), theWayOut(1);
	bool goodData(false);
	   	
	while (goodData == false)
	{
		goodData = true;
		
		std::cout << "Enter a fraction in format a/b or a.c/b, for b!=0" << std::endl;
		getline(cin, latentFraction);

		//Checking if the user wants to quit
		theWayOut = latentFraction.find_first_of("qQ");
		if (theWayOut != -1) return 0;
		
		theMiddle = latentFraction.find('/');
							   
		for (int i = 0; i < latentFraction.size(); i++)
		{
			charInt = latentFraction[i];

			if (charInt <= 44 || charInt >= 58)
			{
				std::cout << "ERROR 02: INVALID CHARACTER DETECTED\n" << std::endl;
				latentFraction.erase();
				goodData = false;
				break;
			}

			if (latentFraction.front() == '/')
			{
				std::cout << "ERROR 03: NO NUMERATOR\n" << std::endl;
				latentFraction.erase();
				goodData = false;
				break;
			}

			if (latentFraction[i]=='/'&& latentFraction[i+1] == '/')
			{
				std::cout << "ERROR 04: FORMAT NOT UNDERSTOOD\n" << std::endl;
				latentFraction.erase();
				goodData = false;
				break;
			}

			if (latentFraction[i] == '.' && latentFraction[i + 1] == '/')
			{
				std::cout << "ERROR 04: FORMAT NOT UNDERSTOOD\n" << std::endl;
				latentFraction.erase();
				goodData = false;
				break;
			}

			if (latentFraction[i] == '-' && latentFraction[i + 1] == '/')
			{
				std::cout << "ERROR 04: FORMAT NOT UNDERSTOOD\n" << std::endl;
				latentFraction.erase();
				goodData = false;
				break;
			}

			if (latentFraction.back() == '/')
			{
				std::cout << "ERROR 05: NO DENOMINATOR\n" << std::endl;
				latentFraction.erase();
				goodData = false;
				break;
			}

			if (latentFraction.back() == '0')
			{
				std::cout << "ERROR 05: DIVISION BY ZERO IS NOT ALLOWED\n" << std::endl;
				latentFraction.erase();
				goodData = false;
				break;
			}
		}

		if (goodData == false) continue;
		
		if (theMiddle == -1 && goodData == true)	//-1 means the user didn't input / so we assume it was a whole number, and the denominator is set to 1 
		{
			numerator = stold(latentFraction);
			denominator = 1;
		}

		if (theMiddle > 0 && goodData == true)
		{
			numerator = stold(latentFraction);
			latentFraction.erase(0, theMiddle + 1);
			denominator = stold(latentFraction);
		}
	}

	simplify();
	std::cout << "Your fraction is " << fixed << setprecision(0) << numerator << "/" << setprecision(0) << denominator << std::endl;
	return 1;

}

void Fraction::set_Numerator(double long num)
{
	//If the decimals are too many, the calculations go bad.  I have set a limit of seven decimal places
	numerator = num;
	numerator = floor((numerator * 10000000) / 10000000);
}

void Fraction::set_Denominator(long int dem)
{
	denominator = dem;
}

double long Fraction::print_Numerator() {

	return numerator;

}

int long Fraction::print_Denominator() {

	return denominator;

}

string Fraction::printFraction()
{
	if (print_Denominator() == 0) return "ERROR 05: DIVISION BY ZERO IS NOT ALLOWED\n";

	else {
		string f = to_string((int long)print_Numerator()) + '/' + to_string(print_Denominator());
		return f;
	}
}

int long Fraction::findLCM(int long a, int long b)
{
	//To find the LCM, make "i" equal to any of the denomiators to start. Then keep increasing i until i%denominators == 0 
	//The LCM gets stored in LCM
	for (int long i = abs(a); i < INT_MAX; i++) {

		if ((i % abs(a) == 0) && (i % abs(b) == 0)) {

			LCM = i;
			break;
		}
	}
	return LCM;
}

Fraction Fraction::operator + (const Fraction &f1)
{
	Fraction rFraction;

	rFraction.findLCM(denominator, f1.denominator);
	
	rFraction.set_Numerator(((rFraction.LCM / denominator) * numerator) + ((rFraction.LCM / f1.denominator) * f1.numerator));
		
	rFraction.denominator=rFraction.LCM;

	return rFraction;
}

Fraction Fraction::operator - (const Fraction& f1)
{
	Fraction rFraction;

	rFraction.findLCM(denominator, f1.denominator);

	rFraction.set_Numerator(((rFraction.LCM / denominator) * numerator) - ((rFraction.LCM / f1.denominator) * f1.numerator));

	rFraction.denominator = rFraction.LCM;

	return rFraction;
}

Fraction Fraction::operator * (const Fraction& f1)
{
	Fraction rFraction;

	rFraction.numerator = numerator * f1.numerator;
	rFraction.denominator = denominator * f1.denominator;

	return rFraction;
}

Fraction Fraction::operator / (const Fraction& f1)
{
	Fraction rFraction;
	rFraction.numerator = numerator * f1.denominator;
	rFraction.denominator = denominator * f1.numerator;
	return rFraction;
}

Fraction &Fraction::operator ++ ()
{
	this->numerator=(this->numerator+ abs(this->denominator));
	return *this;
}

Fraction &Fraction::operator -- ()
{
	this->numerator = (this->numerator - abs(this->denominator));
	return *this;
}

Fraction &Fraction::operator += (Fraction& f1)
{
	*this = *this + f1;
	return *this;
}

Fraction &Fraction::operator -= (Fraction& f1)
{
	*this = *this - f1;
	return *this;
}

Fraction &Fraction::operator *= (Fraction& f1)
{
	*this = *this * f1;
	return *this;
}

Fraction &Fraction::operator /= (Fraction& f1)
{
	*this = *this / f1;
	return *this;
}

bool Fraction::operator== (const Fraction& f1)
{
	if (this->numerator == f1.numerator && this->denominator == f1.denominator) 
	{
		return true;
	}
	else return false;
}

bool Fraction::operator!= (const Fraction& f1)
{
	if (this->numerator != f1.numerator || this->denominator != f1.denominator)
	{
		return true;
	}
	else return false;
}

bool Fraction::operator > (const Fraction& f1)
{
	double long a(numerator / denominator), b(f1.numerator/f1.denominator);
	
	if (a>b)
	{
		return true;
	}
	else return false;
}

bool Fraction::operator < (const Fraction& f1)
{
	double long a(numerator / denominator), b(f1.numerator / f1.denominator);

	if (a < b)
	{
		return true;
	}
	else return false;
}

bool Fraction::operator >= (const Fraction& f1)
{
	if (*this>f1 || *this == f1)
	{
		return true;
	}
	else return false;
}

bool Fraction::operator <= (const Fraction& f1)
{
	if (*this < f1 || *this == f1)
	{
		return true;
	}
	else return false;
}

Fraction Fraction::operator ^ (Fraction &f1)
{
	Fraction* fPtr = new Fraction;
	
	long int a = this->numerator;
	long int b = f1.numerator;
	fPtr->numerator = a ^ b;
	
	a = this->denominator;
	b = f1.denominator;
	fPtr->denominator = a ^ b;

	return *fPtr;
		
}

Choice::Choice()
{
	string LatentOperator = " ";
}

void Choice::myChoice(Fraction* f1, Fraction* f2)
{
	int width1(11);
	Fraction f3;

	std::cout << "\nThese are the results of different operations\n" << std::endl;
		
	f3 = *f1 + *f2;
	f3.simplify();
	std::cout << setw(width1) << right << "f1 + f2 = " << f3.printFraction() << std::endl;

	f3 = *f1 - *f2;
	f3.simplify();
	std::cout << setw(width1) << right <<  "f1 - f2 = " << f3.printFraction() << std::endl;

	f3 = *f1 * *f2;
	f3.simplify();
	std::cout << setw(width1) << right << "f1 * f2 = " << f3.printFraction() << std::endl;

	f3 = *f1 / *f2;
	f3.simplify();
	std::cout << setw(width1) << right << "f1 / f2 = " << f3.printFraction() << std::endl;
	
	++ *f1;
	f1->simplify();
	std::cout << setw(width1) << right << "++f1 = " << f1->printFraction() << std::endl;

	++ *f2;
	f2->simplify();
	std::cout << setw(width1) << right << "++f2 = " << f2->printFraction() << std::endl;

	-- *f1;
	f1->simplify();
	std::cout << setw(width1) << right << "--f1 = " << f1->printFraction() << std::endl;

	-- *f2;
	f2->simplify();
	std::cout << setw(width1) << right << "--f2 = " << f2->printFraction() << std::endl;

	*f1 += *f2;
	f1->simplify();
	std::cout << setw(width1+1) << right << "f1 += f2 => " << "  f1 = " << f1->printFraction() << std::endl;
	
	*f1 -= *f2;
	f1->simplify();
	std::cout << setw(width1+1) << right << "f1 -= f2 => " << "  f1 = " << f1->printFraction() << std::endl;

	*f1 *= *f2;
	f1->simplify();
	std::cout << setw(width1+1) << right << "f1 *= f2 +> " << "  f1 = " << f1->printFraction() << std::endl;

	*f1 /= *f2;
	f1->simplify();
	f1->simplify();
	std::cout << setw(width1+1) << right << "f1 /= f2 => " << "  f1 = " << f1->printFraction() << std::endl;

	if ((*f1 == *f2 ) == true) 
	{
		std::cout << setw(width1) << right << "f1 == f2 = " << "true" << std::endl;
	}

	if ((*f1 != *f2) == true)
	{
		std::cout << setw(width1) << right << "f1 != f2 = " << "true" << std::endl;
	}

	if ((*f1 >= *f2) == true)
	{
		std::cout << setw(width1) << right << "f1 >= f2 = " << "true" << std::endl;
	}

	if ((*f1 <= *f2) == true)
	{
		std::cout << setw(width1) << right << "f1 <= f2 = " << "true" << std::endl;
	}

	f3=*f1 ^ *f2;
	f3.simplify();
	std::cout << setw(width1) << right << "f1 ^ f2 = " << f3.printFraction() << std::endl;

}
