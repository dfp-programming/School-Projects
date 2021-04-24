#include <iostream>
#include <stack>
#include <fstream>
#include <algorithm>
#include "stringPattern.h"

int main()
{
    //some variables
    int choice(0);
    std::string inputString, fileName;
    std::fstream file;

    //class objects
    stringPattern pattern;
    baseConverter baseChange;
    nestCheck nestEncabulator;  //I didn't have a turbo one

  

    while (true)
    {
        std::cout << "\nWhat would you like to do?" << std::endl;
        std::cout << "1. Check if a string matches pattern XYZ#ZYX" << std::endl;
        std::cout << "2. Convert a base 10 number to a different base, where (2 <= base <= 16)" << std::endl;
        std::cout << "3. Check if a file has the correct nesting: {[()]}" << std::endl;
        std::cout << "4. Quit" << std::endl;


        choice = baseConverter::getInteger(1, 4);
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');

        std::cout << "You have chosen: " << choice << std::endl;

        switch (choice)
        {
        case (1):

            while (inputString[0] != ' ')
            {
                std::cout << "Please insert a string to be analyzed or enter a space to quit\n";
                getline(std::cin, inputString);

                if (inputString[0] == ' ')
                    break;

                else if (pattern.checkString(inputString) == false)
                    std::cout << inputString << " does not match the pattern\n" << std::endl;

                else
                    std::cout << inputString << " matches the pattern\n" << std::endl;

            }

            inputString.erase();
            choice = 0;
            break;

        case (2):

            baseChange.multibaseOutput();
            inputString.erase();
            choice = 0;
            break;

        case (3):

            std::cout << "Please enter the name of the file: ";
            std::getline(std::cin, fileName);
            file.open(fileName);

            if (file.fail())
            {
                std::cout << "There was a problem opening the file\n";
                break;
            }

            while (true)
            {
                std::getline(file, inputString);

                //check if the charfacters are parentesis, brackets, and curly brackets are nested correctly.
                if (nestEncabulator.checkNesting(inputString) == false)
                {
                    std::cout << "the symbols in file \"" << fileName << "\" are not balanced." << std::endl;
                    break;
                }

                else if (file.eof())
                {
                    std::cout << "the symbols in file \"" << fileName << "\" are balanced." << std::endl;
                    break;
                }

            }

            file.close();
            inputString.erase();
            choice = 0;
            break;

        case (4):

            std::cout << inputString << "\nThank you for playing!\n" << std::endl;
            exit(0);
            break;

        default:
            std::cout << "Please try again\n" << std::endl;
            choice = 0;
            break;

        }
    }
}
