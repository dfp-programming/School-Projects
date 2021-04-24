#include "Faculty.h"

Faculty::Faculty()
	:room (-1), ternure(false){}


void Faculty::removeOffice()
{
	room = -1;
}

void Faculty::setData(Office& floorOffices)
{
	Employee::setData();

	bool breakFree = false;

	while (breakFree == false)
	{
		std::cout << "Assign an office - Enter -1 to skip this step" << std::endl;
		floorOffices.printOffices();

		room = getNumbers::getInt(-1, floorOffices.roomsInThisFloor());

		if (room >= 0)
		{
			switch (floorOffices.isThisRoomTaken(room))
			{
			case 0:
				floorOffices.setOffice(room);
				breakFree = true;
				break;
			case 1:
				floorOffices.setOffice(room);
				room = -1;
				continue;
				break;
			default:
				break;
			}
		}

		if (room == -1)
		{
			std::cout << "OFFICE ASSIGMENT CANCELLED" << std::endl;

		}
	}

	std::cout << "Ternure? 0-No 1-Yes  ";
	ternure = getNumbers::getInt(0, 1);

}

void Faculty::printData(Office& floorOffice)
{
	std::cout << "FACULTY" << std::endl;
	Employee::printData();

	std::cout << std::setw(indentation) << std::left << "Office: ";
	floorOffice.printOffices(room);
	std::cout << std::setw(indentation) << std::left << "\nTerure: " << std::setw(indentation) << std::left << (ternure ? " true" : " false" ) << std::endl;
	std::cout << "*****************************************************" << std::endl;

}
