#pragma once
#include "Person.h"

class Student :
	public virtual Person
{
	enum class tier : int {freshman =1, sophomore, junior ,senior};
	int rank;
	double GPA;

public:
	Student();

	void setData();
	void printData();

};

