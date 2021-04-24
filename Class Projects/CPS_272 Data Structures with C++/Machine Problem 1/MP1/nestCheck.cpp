#include "nestCheck.h"

void nestCheck::removeCharacters(std::string& inputString)
{
    std::string temp;
    int count(0);

    while (count < inputString.length())
    {
        if (inputString[count] == '(' || inputString[count] == ')' || inputString[count] == '[' || inputString[count] == ']' || inputString[count] == '{' || inputString[count] == '}')
        {
            temp += (inputString[count]);

        }
        count++;
    }

    inputString = temp;
}

void nestCheck::fillStacks(std::stack<int>& character, std::stack<int>& rCharacter, std::string copyString, char char1, char char2)
{
    int index1(0), index2(0);

    while (true)
    {
        //std::cout << copyString << std::endl;
        index1 = copyString.find_first_of(char2);
        index2 = copyString.rfind(char1, index1);

        if (index1 == -1 || index2 == -1)
            break;
        else
        {
            character.push(index2);
            rCharacter.push(index1);

            copyString[index1] = '_';
            copyString[index2] = '_';
            //std::cout << copyString << std::endl;
        }
    }
}

 void nestCheck::compareStacks(std::stack<int>& character, std::stack<int>& rCharacter)
{

    //check if the stacks are the same size.  different size stacks indicates an unbalanced string
    if (rCharacter.size() != character.size())
        this->result= false;

    // Each stack has a pair of characters at the top, stored as an index on the input string.
    // If the nesting is right, there are some simple conditions to check
    // Figuring this out took me more time than it should had, but it works well. 

    while (!character.empty() && !rCharacter.empty())
    {

        //std::cout << character.top() << " <=> " << rCharacter.top() << std::endl;

        //check if the left character is either bigger or the same as the right.  True = bad nesting;
        if (character.top() >= rCharacter.top())
        {
            this->result = false;
            break;
        }

        //Check if the difference of the string indexes is even or qual to 2.
        //for example: ({[]}) if we are checking {, these are indexes 1 and 4.  |1 - 4| = 3 so this is right.  All odd numbers are good in this case 
        //If the number is even, then you could have the following case ([{]}).

        else if ((rCharacter.top() - character.top()) % 2 == 0 || (rCharacter.top() - character.top()) == 2)
        {
            this->result = false;
            break;
        }

        //if it passed the checks, pop the tops and do it again

        else
        {
            character.pop();
            rCharacter.pop();
        }
    }
   
}

 void nestCheck::clearStacks(std::stack<int>& character, std::stack<int>& rCharacter)
 {
     //making sure the stacks are empty for next time!


     while (!character.empty())
     {
         character.pop();
     }

     while (!rCharacter.empty())
     {
         rCharacter.pop();
     }

 }

bool nestCheck::checkNesting(std::string& inputString)
{
    result = true;

    removeCharacters(inputString);
    fillStacks(character, rCharacter, inputString, '(', ')');
    compareStacks(character, rCharacter);
    clearStacks(character, rCharacter);

    removeCharacters(inputString);
    fillStacks(character, rCharacter, inputString, '[', ']');
    compareStacks(character, rCharacter);
    clearStacks(character, rCharacter);
    
    removeCharacters(inputString);
    fillStacks(character, rCharacter, inputString, '{', '}');
    compareStacks(character, rCharacter);
    clearStacks(character, rCharacter);

    return this->result;
}
