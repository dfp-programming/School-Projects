#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;


int convert_roman_to_decimal(char digit){

//FUNCTION convert_from_Roman_to_Decimal
//int convert_from_Roman_to_Decimal(char);
//This function is to receive a char (e.g. an 'M' or a 'C' etc.) and return its corresponding integer value as an integer.
// Use a value-returning function. It can be called from the get_Data function.	
	
int integer;

/*Switch statement to convert a character to an number. 
I     1
V     5
X     10
L     50
C     100
D     500
M     1000 	
*/
	
	switch(digit){
		
		case 'I':
			
			integer=1; break;
			
		case 'V':
			
			integer=5; break;
		
		case 'X':
			
			integer=10; break;
			
		case 'L':
			
			integer=50; break;
			
		case 'C':
			
			integer=100; break;
			
		case 'D':
			
			integer=500; break;
			
		case 'M':
			
			integer=1000; break;
			
		}
	return integer;
}

int get_Data(string roman){

//FUNCTION get_Data
//This function receives the input file, reads one series of chars representing a Roman numeral, and sends back the value of the numeral read in. 
//This function can call the function convert_from_Roman_to_Decimal to do the conversion while it is reading each letter.

char digit='0';
int conversion{0};

	for(int count=0; count<roman.length();count++){
	    
		digit=roman[count];
		conversion+=convert_roman_to_decimal(digit);
		
		if (count>=roman.length()){
			count=0;
			break;
			}
	}
	
return conversion;
	
}
string convert_from_Decimal_to_Roman(int romanDecimal_3){

//FUNCTION convert_from_ Decimal_ to _ Roman
//string convert_from_Decimal_to_Roman(int);
//This function is to receive a integer (e.g. 13) and return its corresponding roman value as a string (e.g. XIII). Use a value-returning function.

string decimal2roman;
		
	if(romanDecimal_3>=1000){
		
		do{
		romanDecimal_3-=1000;
		decimal2roman.append("M");
			}
		while(romanDecimal_3>=1000);
		
		}
	
	if (romanDecimal_3>=500){
		
		do{
		romanDecimal_3-=500;
		decimal2roman.append("D");
			}
		while(romanDecimal_3>=500);
				
		}
	
	if (romanDecimal_3>=100){
		
		do{
		romanDecimal_3-=100;
		decimal2roman.append("C");
			}
		while(romanDecimal_3>=100);
				
		}

	if (romanDecimal_3>=50){
		
		do{
		romanDecimal_3-=50;
		decimal2roman.append("L");
			}
		while(romanDecimal_3>=50);
				
		}

	if (romanDecimal_3>=10){
		
		do{
		romanDecimal_3-=10;
		decimal2roman.append("X");
			}
		while(romanDecimal_3>=10);
				
		}
		
	if (romanDecimal_3>=5){
		
		do{
		romanDecimal_3-=5;
		decimal2roman.append("V");
			}
		while(romanDecimal_3>=5);
				
		}
		
	if (romanDecimal_3>=1){
		
		do{
		romanDecimal_3-=1;
		decimal2roman.append("I");
			}
		while(romanDecimal_3>=1);
				
		}		
		
	return decimal2roman;

}


void calc_Romans(int romanDecimal_1, int romanDecimal_2, char math, int& romanDecimal_3){

//FUNCTION calc_Romans
//void calc_Romans(int, int, char, int&);
//This function is given the two integers and a char (the operator) and returns the result of doing the required operation on the two integers,
// (using the reference 4th parameter.)

	switch(math){
		
		case '+':
			
			romanDecimal_3=romanDecimal_1+romanDecimal_2;	break;
			
		case '-':
			
			romanDecimal_3=romanDecimal_1-romanDecimal_2;	break;
			
		case '*':
			
			romanDecimal_3=romanDecimal_1*romanDecimal_2;	break;
		
		case '/':
			
			romanDecimal_3=romanDecimal_1/romanDecimal_2;	break;
	}



}

void print_Result(ofstream &writeFile, string romanString_1, string romanString_2, char mathOperator, int romanCalculation){

//FUNCTION print_Result
//void print_Result(int);
//This void function receives the integer result of the calculation, and prints it out. It does not have to return anything to the calling program.

writeFile << "The first number is " << romanString_1 << " ( " << get_Data(romanString_1) << " )." << endl;
writeFile << "The second number is " << romanString_2 << " ( " << get_Data(romanString_2) << " )." << endl;
writeFile << "The operator is " << mathOperator << endl;
writeFile << "The result is " << romanCalculation << " ( " << convert_from_Decimal_to_Roman(romanCalculation) << " )." << endl;
writeFile << "************************************************" << endl;


}


//INPUT/OUTPUT: The input file will have number of lines. Each line will have two Roman numbers followed by an operator, separated by blanks. Include a copy of the file with your program and output.  The style of the data file looks as follows:


int main() {

string roman1, roman2, roman3;	
int romanDec1{0}, romanDec2{0}, romanDec3{0}; 
char operand;

ifstream readFile("mp4romanletrdata.txt");
ofstream writeFile("roman_result.txt");


while(readFile >> roman1 >> roman2 >> operand){
	
	romanDec1=get_Data(roman1);
	romanDec2=get_Data(roman2);
	calc_Romans(romanDec1,romanDec2,operand,romanDec3);
	
	print_Result(writeFile, roman1, roman2, operand, romanDec3);
	
//	cout << roman1 << "\t"<< romanDec1 << "\tand\t" << roman2 << "\t" << romanDec2 << "\tand\t" << operand <<  "\tresult\t" << romanDec3 << "\tresult\t" << convert_from_Decimal_to_Roman(romanDec3) << endl;

	}
	
	return 0;
}
