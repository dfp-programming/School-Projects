#pragma once
#include <string>
#include <stdexcept>
#include <iostream>
#include <iomanip>
using namespace std;

class Complex {
    friend ostream& operator<<(ostream& out, const Complex& theComplex); 
    friend istream& operator>>(istream& in, Complex& theComplex);
    friend Complex operator+(const Complex& lhs, const Complex& rhs);
    friend Complex operator-(const Complex& lhs, const Complex& rhs);
    friend Complex operator*(const Complex& lhs, const Complex& rhs);
    friend Complex operator/(const Complex& lhs, const Complex& rhs);
public:
    Complex(double re = 0.0, double im = 0.0);
    double getReal(void) const;            // return real part
    double getImaginary(void) const;        // return imaginary part
    void setReal(double re);            // sets the real part
    void setImaginary(double im);        // sets the imaginary part
    void convertStringToComplex(const string& complexString);
    
private:
    double real;
    double imag;
};


