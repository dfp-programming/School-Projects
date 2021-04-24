#include "book.h"

const enum FORMAT {INDEX = 10, AUTHOR=15, TITLE=40, NUMBER_OF_BOOKS=10, YES=1, NO=0};

int main() {

	//I chose to put all the file names into strings, so it is easier to change if needed. It came in handy. 

	string file_2b_Read_01 = "mp8bookarray.txt";			//file to be read and stores in the book array 
	string file_2b_Read_02 = "mp8bookISBN.txt";				//ISBN customer list
	string outputFile = "mp8booklist-finalresult.txt";		//file listing all the books present, and if they cross into the ISBN list. 
	int unsigned long ISBN_Customer{ 0 };					//to be used when cross referencing. 

	ofstream writeFile;
	ifstream readFile(file_2b_Read_01);
	
	//creating the output file and adding a title
	writeFile.open(outputFile);
	writeFile << "Testing the book class by Diego F. Perez\n" << endl;
			
	//creating an array of the book class, for 10 books. 
	Book book_[NUMBER_OF_BOOKS];

	//some book, for later. No data will be stored.  
	Book YourBookMustNotBeInterestingSoWeDontHaveIt;


	//reading all of the books into the class array
	for (int i = 0; i < NUMBER_OF_BOOKS; i++) {
		book_[i].getData(readFile);
	}
			
	//printing all the books simply to list them up.
	writeFile << setw(INDEX) << left << "INDEX"<< setw(AUTHOR) << "AUTHOR" << setw(TITLE) << "TITLE" << "ISBN" << endl;
	
	for (int i = 0; i < NUMBER_OF_BOOKS; i++) {
		writeFile << setw(INDEX) << left << i + 1;
		book_[i].printBook(writeFile, AUTHOR, TITLE, YES);
		writeFile << endl;
	}

	writeFile << "-------------------------  END OF BOOK LIST ------------------------- \n" << endl;

	//switching file streams
	readFile.close();
	readFile.open(file_2b_Read_02);

	//reading the ISBN file, cross referencing with book array, and printing a message with the result.  
	int count{ 0 };
	while (!readFile.eof()) {

		readFile >> ISBN_Customer;
		writeFile << left  << setw(INDEX/2) << "ISBN" << ISBN_Customer;

		for (count = 0; count < NUMBER_OF_BOOKS; count++) {
			
			if (ISBN_Customer == book_[count].tellMeTheISBN()) {

				writeFile << " IS IN STOCK" << endl;
				writeFile << setw(INDEX) << " ";
				book_[count].printBook(writeFile, AUTHOR, TITLE, NO);
				writeFile << endl << endl;
						break;
			}
			
			if (count == NUMBER_OF_BOOKS-1) {

				writeFile << " IS NOT IN OUR LIBRARY" << endl;
				writeFile << setw(INDEX) << " ";
				YourBookMustNotBeInterestingSoWeDontHaveIt.printBook(writeFile, AUTHOR, TITLE, YES);
				writeFile << endl << endl;
			}
			
		}
			   
	}
	
}