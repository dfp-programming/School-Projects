#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

class Book {

	string author, title;
	int unsigned long ISBN;

public:	

	Book();
	
	const void printBook(ofstream& writeFile, int nameLenght, int titleLenght, int ISBN_Yes_Or_Not);

	void getData(ifstream& readFile);

	const void getISBN(ifstream& readFile);

	int unsigned long tellMeTheISBN();


	};
	
