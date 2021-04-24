#pragma once

#include <iostream>
#include <string>
#include <stack>
#include "baseConverter.h";
#include "nestCheck.h"

class stringPattern
{
    std::stack<char> leftString, rightString;

public:
    bool checkString(std::string& inputString);


};

