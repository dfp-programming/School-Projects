#include <iostream>
#include <vector>
#include "Fraction.h"
#include <fstream>
using namespace std;


int main()
{
	//objects to read file1 and file2
	fstream readFile1("FractsToVector.txt"), readFile2("FractsToList.txt");
	
	//vectors for file1, and the combination of file1 and the list. 
	vector<Fraction<int>*> vectorOfFractions, mergedVector;
	
	//pointers for the list
	Fraction<int> *node = nullptr, *head = nullptr, *tempNode = nullptr, *traverse = nullptr;
	
	int listSize(0), count(0);
	
	cout << "\nVector of fractions as it is being read from the file\n" << endl;
	//reading into the vector of fractions. 
	while (!readFile1.eof())
	{
		Fraction<int>* tempFraction = new Fraction<int> ;
		readFile1 >> tempFraction;
		vectorOfFractions.push_back(tempFraction);
		
		cout << setw(3) << right << vectorOfFractions[count]->print_Numerator() << "/" << setw(2) << left << vectorOfFractions[count]->print_Denominator();
		cout << fixed;
		cout << setprecision(5) << setw(10) << right << vectorOfFractions[count]->print_decimalF() << "\t" << vectorOfFractions.size() << endl;
		++count;
		
	}
	

	//sorting the vector of fractions
	for (int j = 0; j < vectorOfFractions.size(); j++)
	{
		for (int i = 1; i < vectorOfFractions.size(); i++)
		{
			if (vectorOfFractions[i-1]->print_decimalF() > vectorOfFractions[i]->print_decimalF())
			{
				//I could use the swap function
				//swap(vectorOfFractions[i],vectorOfFractions[i-1]);

				//or I could use my own algorithm.  either one works. 
				Fraction<int>* tempFraction = vectorOfFractions[i-1];
				vectorOfFractions[i - 1] = vectorOfFractions[i];
				vectorOfFractions[i] = tempFraction;
			}
		}
	}


	//output vector of fractions after it has been sorted. 
	cout << "\nVector of fractions after sorting\n" << endl;
	for (int i = 0; i < vectorOfFractions.size(); i++)
	{

		cout << setw(3) << right << vectorOfFractions[i]->print_Numerator() << "/" << setw(2) << left << vectorOfFractions[i]->print_Denominator();
		cout << fixed;
		cout << setprecision(5) << setw(10) << right << vectorOfFractions[i]->print_decimalF() << "\t" << i << endl;

	}

	//creating and reading into the List
	cout << "\nList of fractions as it is being read from the file\n" << endl;
	
	count = 0;
	while (!readFile2.eof())
	{
		if (count == 0)
		{
		node = new Fraction<int>;
		head = new Fraction<int>;
		head->link = node;
		tempNode = node;
		}
		
		readFile2 >> node;

		node->link = new Fraction<int>;
		node = node->link;
		tempNode = node;
		tempNode->link = node;

		if (readFile2.eof() == true) tempNode->link = nullptr;
	
		++count;

		cout << setw(3) << right << tempNode->print_Numerator() << "/" << setw(2) << left << tempNode->print_Denominator();
		cout << fixed;
		cout << setprecision(5) << setw(10) << right << tempNode->print_decimalF() << "\t" << count << endl;
		cout << " head = " << head << "\thead links to = " << head->link << "\tthis node = " << tempNode <<  "\tlinks to = " << tempNode->link <<  endl;
	}
	listSize = count;
	count = 0;


	cout << "\nTraversing the list and adding it to a new vector\n" << endl;
	traverse = head->link;
	while (traverse != NULL)
	{
		mergedVector.push_back(traverse);
		if(count <  vectorOfFractions.size())	mergedVector.push_back(vectorOfFractions[count]);
		
		cout << setw(3) << right << traverse->print_Numerator() << "/" << setw(2) << left << traverse->print_Denominator();
		cout << fixed;
		cout << setprecision(5) << setw(10) << right << traverse->print_decimalF() << "\t" << count << endl;
		cout << " head = " << head << "\tthis node = " << traverse << "\tlinks to = " << traverse->link << endl;
			   		 	  
		traverse = traverse->link;
		++count;
	}


	//sorting the new merged vector. 
	for (int j = 0; j < mergedVector.size(); j++)
	{
		for (int i = 1; i < mergedVector.size(); i++)
		{
			if (mergedVector[i - 1]->print_decimalF() > mergedVector[i]->print_decimalF())
			{
				//I could use the swap function
				//swap(vectorOfFractions[i],vectorOfFractions[i-1]);
	
				//or I could use my own algorithm.  either one works. 
				Fraction<int>* tempFraction = mergedVector[i - 1];
				mergedVector[i - 1] = mergedVector[i];
				mergedVector[i] = tempFraction;
			}
		}
	}


	cout << "\nMerged vector already sorted\n" << endl;
	for (int j = 0; j < mergedVector.size(); j++)
	{
		cout << setw(3) << right << mergedVector[j]->print_Numerator() << "/" << setw(2) << left << mergedVector[j]->print_Denominator();
		cout << fixed;
		cout << setprecision(5) << setw(10) << right << mergedVector[j]->print_decimalF() << "\t" << j << endl;
	
	}

	//Removing duplicates
	for (int j = 1; j < mergedVector.size(); j++)
	{

		if (mergedVector[j - 1]->print_decimalF() == mergedVector[j]->print_decimalF())
		{
			vector<Fraction<int>*>::iterator d;
			d = mergedVector.begin()+(j-1);
			mergedVector.erase(d);
			
			//delete mergedVector[j - 1];
			
		}

	}
	mergedVector.shrink_to_fit();


	cout << "\nMerged vector with all duplicates removed\n" << endl;
	for (int j = 0; j < mergedVector.size(); j++)
	{
		cout << setw(3) << right << mergedVector[j]->print_Numerator() << "/" << setw(2) << left << mergedVector[j]->print_Denominator();
		cout << fixed;
		cout << setprecision(5) << setw(10) << right << mergedVector[j]->print_decimalF() << "\t" << j << endl;

	}

}

