#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;


template <typename T> class Fraction {
	double decimalF;
	T numerator;
	T denominator;
	

public:
	Fraction<T>* link;

	const int MAX_RESOLUTION = 10000000;;

	//some importatn functions. type check will be used by the constructor to to check if the object will be valid
	bool typeCheck(T);
	Fraction();
	bool checkOverflow(double);

	//setters and getters
	void set_Numerator(T&);
	void set_Denominator(T&);
	void cal_Decimal();
	T print_Numerator() const;
	T print_Denominator() const;
	double print_decimalF() const;

	//general methods
	//T get_Data();
	T simplify();
	T get_Data();
	T findLCM (const T&, const T&);
	
	//Operator overloads
	Fraction &operator = (const Fraction);
	Fraction &operator + (const Fraction&);
	Fraction &operator - (const Fraction&);
	Fraction &operator * (const Fraction&);
	Fraction &operator / (const Fraction&);

	template<typename >	friend fstream& operator >> (fstream& inputData, Fraction<T>* F);

};

template<typename T>
inline bool Fraction<T>::typeCheck(T numb)
{
	if (typeid(numb) == typeid(int) || typeid(numb) == typeid(char) || typeid(numb) == typeid(unsigned char) || typeid(numb) == typeid(int short) || typeid(numb) == typeid(int long))
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
inline Fraction<T>::Fraction()
{
	decimalF = double();
	numerator = 0;
	denominator = 1;
	link = nullptr;
	
	//checking if the data type is allowed
	if(typeCheck(numerator)==false)
	{
		cout << "DATA TYPE (" << typeid(T).name() << ") IS NOT ALLOWED - THIS TEMPLATE ONLY ALLOWS INTEGERS OR CHARS" << endl;
		exit(0);
	}

}

template<typename T>
inline bool Fraction<T>::checkOverflow(double numb)
{
	T check = numb;
	
	if (numb != check)
	{
		return true;
	}
	else return false;
}

template<typename T>
inline void Fraction<T>::set_Numerator(T &num)
{
	//If the decimals are too many, the calculations go bad.  I have set a limit of seven decimal places
	numerator = num;
	numerator = floor((numerator * MAX_RESOLUTION) / MAX_RESOLUTION);
}

template<typename T>
inline void Fraction<T>::set_Denominator(T &num)
{
	//If the decimals are too many, the calculations go bad.  I have set a limit of seven decimal places
	denominator = num;
	denominator = floor((denominator * MAX_RESOLUTION) / MAX_RESOLUTION);
}

template<typename T>
inline void Fraction<T>::cal_Decimal()
{
	if (print_Denominator() == 0) 
		cout << " Warning, division by 0 is not allowed" << endl;
	
	else 
	{
		double temp1 = print_Numerator(), temp2 = print_Denominator();
		decimalF = temp1 / temp2;
	}
}

template<typename T>
inline T Fraction<T>::print_Numerator() const
{
	return numerator;
}

template<typename T>
inline T Fraction<T>::print_Denominator() const
{
	return denominator;
}

template<typename T>
inline double Fraction<T>::print_decimalF() const
{
	return decimalF;
}

template<typename T>
inline T Fraction<T>::simplify()
{
	int long temp_Den(0), temp_Num(0);

	//If numerator==0, set denominator also to 0 
	if (numerator == 0)
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
	if (numerator < 0 && denominator < 0)
	{
		denominator *= -1;
		numerator *= -1;
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

template<typename T>
inline T Fraction<T>::get_Data()
{	

	string latentFraction = "0/1";
	int charInt(-2), theMiddle(-2), theWayOut(1);
	bool goodData(false);

	while (goodData == false)
	{
		goodData = true;

		std::cout << "Use format a/b, for b!=0\tPress q to quit" << std::endl;
		getline(cin, latentFraction);

		//Checking if the user wants to quit
		theWayOut = latentFraction.find_first_of("qQ");
		if (theWayOut != -1) exit(0);

		theMiddle = latentFraction.find('/');

		for (int i = 0; i < latentFraction.size(); i++)
		{
			charInt = latentFraction[i];

			if (charInt <= 44 || charInt >= 58)
			{
				std::cout << "ERROR 01: INVALID CHARACTER DETECTED\n" << std::endl;
				latentFraction.erase();
				goodData = false;
				break;
			}

			if (latentFraction[i] == '.')
			{
				std::cout << "ERROR 02: NO DECIMAL ALLOWED\n" << std::endl;
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

			if (latentFraction[i] == '/' && latentFraction[i + 1] == '/')
			{
				std::cout << "ERROR 04: FORMAT NOT UNDERSTOOD\n" << std::endl;
				latentFraction.erase();
				goodData = false;
				break;
			}

			//I would use this if the class would allow decimals, but this is all integers
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
		}


		if (goodData == false) continue;
		
		if (theMiddle == -1 && goodData == true)	//-1 means the user didn't input / so we assume it was a whole number, and the denominator is set to 1 
		{
			if (checkOverflow(stold(latentFraction)) == true)
			{
				cout << "INTEGER OVERFLOW DETECTED" << std::endl;
				cout << std::fixed << std::setprecision(0) << stold(latentFraction) << " STORED AS (" << typeid(numerator).name() << ") WILL RESULT IN LOST OF DATA "<< std::endl;
				cout << std::endl;
				goodData = false;

				numerator = 0;
				denominator = 1;
				latentFraction = "0/1";
				continue;
			}
			numerator = stold(latentFraction);
			denominator = 1;
		}

		if (theMiddle > 0 && goodData == true)
		{
			if (checkOverflow(stold(latentFraction)) == true)
			{
				cout << "INTEGER OVERFLOW DETECTED" << std::endl;
				cout << std::fixed << std::setprecision(0) << stold(latentFraction) << " STORED AS (" << typeid(denominator).name() << ") WILL RESULT IN LOST OF DATA" << std::endl;
				cout << std::endl;
				goodData = false;

				numerator = 0;
				denominator = 1;
				latentFraction = "0/1";
				continue;
			}

			numerator = stold(latentFraction);
			latentFraction.erase(0, theMiddle + 1);

			if (checkOverflow(stold(latentFraction)) == true)
			{
				cout << "INTEGER OVERFLOW DETECTED" << std::endl;
				cout << std::fixed << std::setprecision(0) << stold(latentFraction) << " STORED AS (" << typeid(denominator).name() << ") WILL RESULT IN LOST OF DATA" << std::endl;
				cout << std::endl;
				goodData = false;

				numerator = 0;
				denominator = 1;
				latentFraction = "0/1";
				continue;
			}

			if (stold(latentFraction) == 0)
			{
				std::cout << "ERROR 05: DIVISION BY ZERO IS NOT ALLOWED\n" << std::endl;
				latentFraction.erase();
				goodData = false;

				numerator = 0;
				denominator = 1;
				latentFraction = "0/1";
				continue;
			}
			
			denominator = stold(latentFraction);
		}

	}

	simplify();
	cout << "Your simplified fraction is " << fixed << setprecision(0) << +numerator << "/" << setprecision(0) << +denominator << std::endl;
	cout << endl;
	return 0;

}

template<typename T>
inline T Fraction<T>::findLCM (const T &a, const T &b)
{
	//To find the LCM, make "i" equal to any of the denomiators to start. Then keep increasing i until i%denominators == 0 
	
	double temp(0);
	
	T LCM(0);

	for (int long i = abs(a); i < INT_MAX; i++) {

		//this line of code is unusual, but if I set the data type to double, or float, this line will alarm out. 
		//the reason, is the % operation with a double can't be allowed, so it is flagged by the compiler even if this line will never be used on those conditions.
		//I opted for casting as integer long, since it is the largest integer this template function will allow. 
		if ((i % (int long)abs(a) == 0) && (i % (int long)abs(b) == 0)) {

			temp = i;
			break;
		}
	}
	
	if(checkOverflow(temp)==true)
	{
		cout << "THE LCM CALCULATION WILL RESULT IN INTEGER OVERFLOW " << endl;
		cout << std::fixed << std::setprecision(0) << temp << " STORED AS (" << typeid(LCM).name() << ") WILL RESULT IN LOST OF DATA " << std::endl;
		exit(0);
	}

	else
	{
		LCM = temp;
		return LCM;
	}

}

template<typename T>
inline Fraction<T>& Fraction<T>::operator=(const Fraction rhs)
{
	//the first if is to check for self assignment F1=F1
	if (this != &rhs)
	{
		numerator = rhs.numerator;
		denominator = rhs.denominator;
		//LCM = Fraction().LCM;
		return *this;
	}
	else
	{
		return *this;
	}

}

template<typename T>
inline Fraction<T> &Fraction<T>::operator+(const Fraction &f1)
{
	Fraction _Fraction;
	double LCM(0), temp(0);

	LCM = findLCM(denominator, f1.denominator);
		
	temp = (((LCM / denominator) * numerator) + (LCM / f1.denominator) * f1.numerator);

	if(checkOverflow(temp) == true)
	{
	cout << "THE CALCULATION WILL RESULT IN INTEGER OVERFLOW " << endl;
	cout << std::fixed << std::setprecision(0) << temp << " STORED AS (" << typeid(denominator).name() << ") WILL RESULT IN LOST OF DATA" << std::endl;
	exit(0);
	}

	_Fraction.numerator = temp;
	_Fraction.denominator = LCM;

	return _Fraction;
}

template<typename T>
inline Fraction<T>& Fraction<T>::operator-(const Fraction& f1)
{
	Fraction _Fraction;
	double LCM(0), temp(0);

	LCM = findLCM(denominator, f1.denominator);

	temp = (((LCM / denominator) * numerator) - (LCM / f1.denominator) * f1.numerator);

	if (checkOverflow(temp) == true)
	{
		cout << "THE CALCULATION WILL RESULT IN INTEGER OVERFLOW " << endl;
		cout << std::fixed << std::setprecision(0) << temp << " STORED AS (" << typeid(denominator).name() << ") WILL RESULT IN LOST OF DATA" << std::endl;
		exit(0);
	}

	_Fraction.numerator = temp;
	_Fraction.denominator = LCM;

	return _Fraction;
}

template<typename T>
inline Fraction<T>& Fraction<T>::operator*(const Fraction& f1)
{
	Fraction _Fraction;
	double temp(0);

	temp = numerator * f1.numerator;

	if (checkOverflow(temp) == true)
	{
		cout << "THE CALCULATION WILL RESULT IN INTEGER OVERFLOW " << endl;
		cout << std::fixed << std::setprecision(0) << temp << " STORED AS (" << typeid(numerator).name() << ") WILL RESULT IN LOST OF DATA" << std::endl;
		exit(0);
	}
	_Fraction.numerator = temp;

	temp = denominator * f1.denominator;

	if (temp == 0)
	{
		cout << "THE CALCULATION WILL RESULT IN DENOMINATOR ZERO" << endl;
		exit(0);
	}

	if (checkOverflow(temp) == true)
	{
		cout << "THE CALCULATION WILL RESULT IN INTEGER OVERFLOW " << endl;
		cout << std::fixed << std::setprecision(0) << temp << " STORED AS (" << typeid(numerator).name() << ") WILL RESULT IN LOST OF DATA" << std::endl;
		exit(0);
	}
	_Fraction.denominator = temp;

	return _Fraction;
}

template<typename T>
inline Fraction<T>& Fraction<T>::operator/(const Fraction& f1)
{
	Fraction _Fraction;
	double temp(0);

	temp = numerator * f1.denominator;

	if (checkOverflow(temp) == true)
	{
		cout << "THE CALCULATION WILL RESULT IN INTEGER OVERFLOW " << endl;
		cout << std::fixed << std::setprecision(0) << temp << " STORED AS (" << typeid(numerator).name() << ") WILL RESULT IN LOST OF DATA" << std::endl;
		exit(0);
	}
	_Fraction.numerator = temp;
	
	temp = denominator * f1.numerator;
	
	if (temp == 0)
	{
		cout << "THE CALCULATION WILL RESULT IN DENOMINATOR ZERO" << endl;
		exit(0);
	}

	if (checkOverflow(temp) == true)
	{
		cout << "THE CALCULATION WILL RESULT IN INTEGER OVERFLOW " << endl;
		cout << std::fixed << std::setprecision(0) << temp << " STORED AS (" << typeid(numerator).name() << ") WILL RESULT IN LOST OF DATA" << std::endl;
		exit(0);
	}
	_Fraction.denominator = temp;
	
	return _Fraction;
}

template<typename T> inline fstream& operator >> (fstream& inputData, Fraction<T>* F)
{
	T temp1, temp2;

	inputData >> temp1 >> temp2;

	if (F->typeCheck(temp1) == false) cout << "data type not allowed" << endl;
	else if (temp2 == 0) cout << "Error - Division by zero is not allowed - Data not read";
	else
	{
		F->set_Numerator(temp1);
		F->set_Denominator(temp2);
		F->simplify();
		F->cal_Decimal();
	}
	return inputData;
}


