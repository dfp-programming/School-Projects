#include "book.h"

const enum FORMAT {AUTHOR=15, TITLE=25};

int main() {

	string file_2b_Read = "mp8book.txt";
	string outputFile = "mp8booktest.txt";

	ofstream writeFile;
	ifstream readFile;
	
	//opening the file
	readFile.open(file_2b_Read);

	//creating the output file and adding a title
	writeFile.open(outputFile);
	writeFile << "Testing the book class by Diego F. Perez\n" << endl;
			
	Book book1, book2;

	writeFile << "The information for book 1 is:" << endl;
	book1.printBook(writeFile, AUTHOR, TITLE);

	writeFile << "The information for book 2 is:" << endl;
	book2.getData(readFile);
	book2.getISBN(readFile);
	book2.printBook(writeFile, AUTHOR, TITLE);


}