#include "stringPattern.h"



bool stringPattern::checkString(std::string& inputString)
{
    int theMiddle(0);

    //check for hash
    if (inputString.find('#') == -1)
        return false;

    //determine where is the middle of the string, depending if it is even or odd in length. 
    else if (inputString.length() % 2 == 0)
        return false;

    else
        theMiddle = (inputString.length() + 1) / 2;

    //store the first half and second halves of the string into stacks
    for (int i = 0; i < theMiddle - 1; i++)
    {
        leftString.push(inputString[i]);
        rightString.push(inputString[(inputString.length() - 1) - i]);
    }

    //compare top of the stacks. If true, pop the tops and repeat. 
    for (int i = 0; i < theMiddle - 1; i++)
    {
        if (leftString.top() != rightString.top())
            return false;
        else
        {
            //std::cout << leftString.top() << " = " << rightString.top() << std::endl;
            leftString.pop();
            rightString.pop();
        }

    }

    return true;

}

