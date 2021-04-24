#include "book.h"


	string author, title;
	int long ISBN;

	
	Book::Book() {

		author = "No name";
		title = "Unknown title";
		ISBN = 0;

	}


	const void Book::printBook (ofstream& writeFile, int nameLenght, int titleLenght) {
		
		writeFile << left << setw(nameLenght) << author << setw(titleLenght) << title << setw (0) << ISBN << endl;
		
		}

	void Book::getData(ifstream& readFile) {

		getline(readFile, author);
		getline(readFile, title);

		}

	const int long Book::getISBN(ifstream& readFile) {

		readFile >> ISBN;

		return ISBN;
		}


