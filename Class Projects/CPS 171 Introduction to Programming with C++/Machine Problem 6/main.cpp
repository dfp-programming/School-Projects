/*
Hello! this program will read a file that contains a set of strings with the names eight persons starting with last name, forst name, and middle initial.
the string also contains marital status and sex information. The program will read the file, echo the information into another file, determine the proper 
title for each person and then print the name as tittle, first name, middle name, last name.

I had fund making this program. I hope you like it!.

Diego F. Perez - CPS171, section D01 - MACHINE PROBLEM 6.

*/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;


//creating a few enums that I want to use throughout the program
enum marriedOrHappy:unsigned char{SINGLE='S', MARRIED='M', DIVORCED='D'};
enum genderEnum:unsigned char{MALE='M', FEMALE='F', OTHER='O'};
enum charecter:unsigned char{COMA=',',SPACE=' ',DOT='.'};


//this function reads the first two characters, and determines the person's title. It then preps the line for the next function by removing 
//characters I dont want to pass along. 
void prefix(string& currentLine, string& prefixTitle){
	
		char status;
		char gender;
		
		if(currentLine[1]==MALE){
			status= MARRIED;
		}
		
		if(currentLine[1]==SINGLE){
			status= SINGLE;
		}
		
		if(currentLine[1]==DIVORCED){
			status= DIVORCED;
		}
				
		if(currentLine[0]==MALE){
			gender= MALE;
		}
	
		if(currentLine[0]==FEMALE){
			gender= FEMALE;
		}
		
		if(gender==MALE){
			prefixTitle= "Mr. ";
		}
		if(gender==FEMALE&&status==MARRIED){
			prefixTitle= "Mrs. ";
		}
		if(gender==FEMALE&&(status==SINGLE||status==DIVORCED)){
			prefixTitle= "Ms. ";
		}
		gender='\0';
		status='\0';
		currentLine.erase(0,2);
}


//this function reads the lastname and removes the characters we dont want to make it easier in the next function.
void lastName(string& currentLine, string& familyName){
	
	familyName=currentLine.substr(0,currentLine.find(COMA));
	
	currentLine.erase(0,familyName.size()+1);
	
	if (familyName[0]==SPACE)	
			familyName.erase(0,familyName.find_first_not_of(SPACE));
	
	familyName.append(" ");
	
}

//this function reads the first name and removes the characters we dont want to make it easier in the next function.
void givenName(string& currentLine, string& firstName){
	
	firstName=currentLine.substr(0,currentLine.rfind(SPACE));
	currentLine.erase(0,firstName.length());
	
	if (firstName[0]==SPACE)
			firstName.erase(0,firstName.find_first_not_of(SPACE));
	
	firstName=firstName.substr(0,firstName.find_first_of(SPACE));
	firstName.append(" ");
}

//this function reads the middle initial and puts a dot in it. 
void theNameBetweenFirstNameAndLastName(string& currentLine, string& middleInitial){

	middleInitial=currentLine.substr(0,currentLine.rfind(DOT));
	
	if (middleInitial[0]==SPACE)
			middleInitial.erase(0,middleInitial.find_first_not_of(SPACE));
	
	middleInitial=middleInitial.substr(0,middleInitial.find(DOT));
	
	if(middleInitial.size()>=1){
			middleInitial.append(". ");
			}
	else middleInitial.erase();
}


int main(){
	
	
	//defining variables and adding the title for the columns in the file.
	ifstream readFile("mp6Names.txt");
	ofstream writeFile("result.txt");
	string line1, originalName, title, familyName, firstName, middleName;
	string line2="Original name";
	
	line2.resize(35);
	writeFile << line2 << "Standardized name\n" << endl;
	
	
	while(!readFile.eof()){

		getline(readFile,line1);
	
		//echo the data and formatting it for lenght. 
		line2=line1;
	    line2.resize(35);
		writeFile << line2;
		
		
		//calling out all the functions, since it is all passed by reference it makes it easier for me. 
		prefix(line1,title);
		lastName(line1, familyName);
		givenName(line1, firstName);
		theNameBetweenFirstNameAndLastName(line1, middleName);
		
	
		//printing the output
		writeFile << title << firstName << middleName << familyName << endl;
		
	}

//closing the streams
readFile.close();
writeFile.close();	

	return 0;
}
