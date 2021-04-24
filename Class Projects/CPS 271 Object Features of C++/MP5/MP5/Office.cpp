#include "Office.h"

Office::Office(int whichFloor, int howManyRooms)
{	
	MyDate newDate;
	campusOffices.reserve(howManyRooms);//reserving how ever many offices we want. It saves memory, so I found it. 
	
	for (int i = 0; i < howManyRooms; i++)
	{	
		//Add a new room, and free it up
		campusOffices.push_back(newDate);
		campusOffices[i].resetTime();
	}
	floorLevel = whichFloor;
}

void Office::setOffice(int roomNumber)
{
	if (roomNumber < 0 || roomNumber > campusOffices.size())
	{
		std::cout << "THIS ROOM DOES NOT EXIST" << std::endl;
	}
	
	if (roomNumber >= 0 && roomNumber <= campusOffices.size())
	{
		if (campusOffices[roomNumber].busyOrFree() == true)
		{
			std::cout << "This room was not in the list for a reason. Evicting people from their room can be difficult\n";
			std::cout << "If you really want this room, take it it up to the dean. We don't want the drama\n" << std::endl;
		}
		
		if (campusOffices[roomNumber].busyOrFree() == false)
		{
			campusOffices[roomNumber].setTime();
		}
	}

}

void Office::printOffices(int roomNumber)
{
	if (roomNumber < 0 || roomNumber > campusOffices.size())
	{
		std::cout << "INVALID ROOM";
	}

	if (roomNumber >= 0 && roomNumber <= campusOffices.size())
	{
		std::cout << "Room " << floorLevel << std::setw(2) << std::setfill('0') << roomNumber << " Hours:";
		campusOffices[roomNumber].printTime();
		std::cout << std::setfill(' ');
	}

}

void Office::printOffices()
{
	std::cout << "\n\tAvailable Rooms" << std::endl;
	for (int i = 0; i < campusOffices.size(); i++)
	{
		if(campusOffices[i].busyOrFree()==false)
		{
			printOffices(i);
			std::cout << std::endl;
		}
	}

}

int Office::roomsInThisFloor()
{
	return  campusOffices.size();
}

bool Office::isThisRoomTaken(int &checkRoom)
{
	return campusOffices[checkRoom].busyOrFree();
}
