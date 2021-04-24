#pragma once
#include "Employee.h"
#include "Office.h"


class Faculty :
	public virtual Employee
{
	int room;
	bool ternure;


public:
	Faculty();

	void removeOffice();
	void setData(Office&);
	void printData(Office&);


};

