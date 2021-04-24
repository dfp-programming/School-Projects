#include "book.h"

	Book::Book() {

		author = "No name";
		title = "Unknown title";
		ISBN = 0;

	}


	const void Book::printBook (ofstream& writeFile, int nameLenght, int titleLenght, int ISBN_Yes_Or_Not) {
		
		writeFile << left << setw(nameLenght) << author << setw(titleLenght) << title;
		
		if(ISBN_Yes_Or_Not==1)	writeFile << ISBN;
		
		}

	void Book::getData(ifstream& readFile) {

		getline(readFile, author);
		getline(readFile, title);
		getISBN(readFile);
		
		}

	const void Book::getISBN(ifstream& readFile) {

		readFile >> ISBN;
		readFile.ignore();
		
		}

	int unsigned long Book::tellMeTheISBN()
	{
		return ISBN;
	}

	

