#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

class Book {

public:
	
	Book();
	
	const void printBook(ofstream& writeFile, int nameLenght, int titleLenght);

	void getData(ifstream& readFile);

	const int long getISBN(ifstream& readFile);


	};
	
