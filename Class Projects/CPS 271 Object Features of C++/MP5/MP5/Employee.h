#pragma once
#include "Person.h"
class Employee :
	public virtual Person
{
	double long salary;
	MyDate DateOfHire;
	
public:
	Employee();
	void setData();
	void printData();

};

