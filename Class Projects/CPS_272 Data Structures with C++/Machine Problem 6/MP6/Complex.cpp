#include "Complex.hpp"


ostream& operator << (ostream& out, const Complex& theComplex)
{
	/*
	This function took me a while to craft, but it was worth the time because it made the 
	complex number look much nicer.  At first we convert the values to strings, remove trailing zeroes,
	then format those strings depending on what's needed. 

	the end goal is something like this:
	
		1.1+1.1i = 1.1+1.1i
		1+1i = 1+i
		0+1i = i
		1+0i = 1
		0+0i = 0

	There is not a straight way to do this, at least that I am aware.  

	
	*/

	double a = theComplex.getReal(), b = theComplex.getImaginary();
	string A{ "" }, B{ "" }, tempA{ "" }, tempB{ "" };

	//to string, and remove trailing zeroes and periods not needed
	tempA = to_string(a); 
	tempA.erase(tempA.find_last_not_of('0') + 1, string::npos);
	if (tempA[tempA.length() - 1] == '.')
		tempA.erase(tempA.length() - 1, string::npos);

	tempB = to_string(b);
	tempB.erase(tempB.find_last_not_of('0') + 1, std::string::npos);
	if (tempB[tempB.length() - 1] == '.')
		tempB.erase(tempB.length() - 1, string::npos);

	//dictating the rules

	//if a is 0, it should not be printed.
	if (a == 0)
		A = "";
	else
		A = tempA;


	//depending on the value of b, print it as +bi, i, or 0; 
	if (b > 0 && b != 1)
		B = "+" + tempB + "i";

	else if (b < 0)
		B = tempB + "i";

	else if (b == 1)
		B = "i";

	else if (b == 0 && a == 0)
		B = "0";
	

	//use this line to double check the formating
	//out << theComplex.getReal() << (theComplex.getImaginary() >= 0.0 ? "+" : "") <<  theComplex.getImaginary() << "i\n";

	out << A << B;

	return out;
}

istream& operator >> (istream& in, Complex& theComplex)
{
	string temp;

	getline(in, temp);

	theComplex.convertStringToComplex(temp);

	return in;
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
	// (a + bi) + (c + di) = (a + c) + (b + d)i

	double a{ 0.0 }, b{ 0.0 }, c{ 0.0 }, d{ 0.0 };

	a = lhs.getReal();
	b = lhs.getImaginary();
	c = rhs.getReal();
	d = rhs.getImaginary();
		
	Complex rComplex((a + c), (b + d));

	return rComplex;
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
	// (a + bi) - (c + di) = (a - c) + (b - d)i

	double a{ 0.0 }, b{ 0.0 }, c{ 0.0 }, d{ 0.0 };

	a = lhs.getReal();
	b = lhs.getImaginary();
	c = rhs.getReal();
	d = rhs.getImaginary();

	Complex rComplex((a - c), (b - d));

	return rComplex;
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
	// (a + bi)(c + di) = (ac - bd) + (b - d)i

	double a{ 0.0 }, b{ 0.0 }, c{ 0.0 }, d{ 0.0 };

	a = lhs.getReal();
	b = lhs.getImaginary();
	c = rhs.getReal();
	d = rhs.getImaginary();

	Complex rComplex(((a*c) - (b*d)) , (b - d));

	return rComplex;
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{

	//(a+bi)/(c+di) = ((ac+bd)/(c^2+d^2)) + ((bc-ad)/(c^2+d^2))i

	double a{ 0.0 }, b{ 0.0 }, c{ 0.0 }, d{ 0.0 }, denominator{ 0.0 };

	a = lhs.getReal();
	b = lhs.getImaginary();
	c = rhs.getReal();
	d= rhs.getImaginary();
	denominator = (c * c) + (d * d);

	if (denominator == 0)
		throw logic_error("It is not possible to divide by zero");

	Complex rComplex((((a * c) + (b * d)) / denominator), ((b * c) - (a * d)) / denominator);

	return rComplex;
}

Complex::Complex(double re, double im) : real(re), imag(im){}

double Complex::getReal(void) const
{
	return this->real;
}

double Complex::getImaginary(void) const
{
	return this->imag;
}

void Complex::setReal(double re)
{
	this->real = re;
}

void Complex::setImaginary(double im)
{
	this->imag = im;
}

void Complex::convertStringToComplex(const string& complexString) // a lot of small checks to ensure the string is right. 
{

	int index1, index2, index3;
	string str1, str2;

	index1 = complexString.find('i'); //find i, ensure there is only one
	index2 = complexString.rfind('i');
	index3 = complexString.find_first_not_of("0123456789.i+"); //find forbiden characters

	// check if there is more than one i, if it is not in the begining/end of the string, of for forbiden/quit characters
	if ((index1 != index2) || index1 != (complexString.length() - 1) || index1 == 0 || (index3 != -1)) {
		if (complexString[0] == 'q' || complexString[0] == 'Q')
			throw logic_error("Quit request");
		else
			throw logic_error("This is not a complex number");
	}
	
	index3 = 0;
	index1 = complexString.find('+'); //find +, ensure there is only one
	index2 = complexString.rfind('+');
	index3 = complexString.find('i');
	

	// check if + exist, if there is only one, it can't be on index 0, and it must be before i. 
	if ((index1 != index2) || (index1 == 0) || (index1 >= index3)) {
		
		throw logic_error("Complex number doesn't have the correct format");
	}

	//extract numbers
	str1 = complexString.substr(0, index1);
	
	if ((index3 - index1) == 1) //this means "number+i", in which case the second number = 1.
		str2 = "1";
	else
		str2 = complexString.substr(++index1, complexString.length() - index1);

	//cout << "index 1: " << index1 << "\tindex2: " << index2 << "\tindex3: " << index3 << endl;
	//cout << str1 << endl;
	//cout << str2 << endl;//set numbers
	
	setReal(stold(str1));
	setImaginary(stold(str2));

	
}
