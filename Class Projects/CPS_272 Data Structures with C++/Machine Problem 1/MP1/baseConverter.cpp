#include "baseConverter.h"

int baseConverter::getInteger(int lowRange, int highRange)
{

    int myInt(0);
    try
    {
        std::cin >> myInt;
        if (std::cin.fail())
            throw ("Not an integer.\n");

        if (myInt < lowRange || myInt > highRange)
            throw ("Input out of range.\n");


    }
    catch (const char* message)
    {
        std::cin.ignore(INT_MAX, '\n');
        std::cin.clear();

        std::cout << message << std::endl;
        return 0;
    }


    return myInt;
}

void baseConverter::multibaseOutput()
{

    std::cout << "\nEnter a non-negative decimal number, or enter 0 to quit: ";
    number = getInteger(0, INT_MAX);

    if (number == 0)
        return;

    std::cout << "Enter base (2 <= B <= 16), or enter 0 to quit: ";
    base = getInteger(0, INT_MAX);

    if (base == 0)
        return;

    tempNumber = number;

    
    //if all looks pretty, then do some actual code.  
     //divide number by base, and store the reminder.  Decrease number by reminder so division is exact, then do division.  Storing the reminders will yield the new number. 
    while (tempNumber > 0)
    {
        reminder.push(tempNumber % base);
        tempNumber -= reminder.top();
        tempNumber /= base;
    }

    while (!reminder.empty())
    {
        conversion += (char)baseArray[reminder.top()];
        reminder.pop();
    }

    std::cout << number << " base " << base << " is " << conversion << std::endl;;

    conversion.erase();
}

