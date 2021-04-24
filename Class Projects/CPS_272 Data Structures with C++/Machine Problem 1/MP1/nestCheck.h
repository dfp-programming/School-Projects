#pragma once
#include "stringPattern.h"

class nestCheck
{
	//create a pair of stacks, one for each pair of characters to check i.e (), [], {}.
	std::stack<int> character;
	std::stack<int> rCharacter;
	bool result;

	public:

		nestCheck()
		{
			result = true;
		}

		void removeCharacters(std::string& inputString);
		void fillStacks(std::stack<int>& character, std::stack<int>& rCharacter, std::string copyString, char char1, char char2);
		void compareStacks(std::stack<int>& character, std::stack<int>& rCharacter);
		void clearStacks(std::stack<int>& character, std::stack<int>& rCharacter);
		bool checkNesting(std::string& inputString);

};

