#pragma once
#include <vector>
#include "MyDate.h"

class Office
{
	std::vector <MyDate> campusOffices;
	int floorLevel;

public:

	Office(int, int);
	void setOffice(int);
	void printOffices(int);
	void printOffices();
	int roomsInThisFloor();
	bool isThisRoomTaken(int&);

};

