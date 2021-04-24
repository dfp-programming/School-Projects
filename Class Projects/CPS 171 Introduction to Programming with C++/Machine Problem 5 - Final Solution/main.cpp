/*
Hello! this program will read a file that contains a set of strings that have to be coded and decoded according to a keyword also provided in the file. 
The program will then decode or encode accordingly, using the cipher based on the keyword.

I must say, this program was extremely difficult for me.  The hard part was not understanding the array concept, but knowing how touchy it may be. I was surprised everything that 
could affect it.  This is why it took me so long.

I hope you enjoy my program.

Diego F. Perez - CPS171, section D01 - MACHINE PROBLEM 5.

*/



#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;



int main() {
	
ifstream readFile("messages.txt");
ofstream writeFile("result.txt");

string line, line2;
int rows{0}, columns{0};
char secret[5][5];
vector<char> alphabet; 

while(!readFile.eof()){
	line.erase();
	line2.erase();
	getline (readFile,line);
	
	
//******************************************************************* coding ****************************************************************		
	if (line[0]=='E'){
		
		line.erase(0,2); //getting rid of the E or D. 
				
				for(int i=0;i<=line.size();i++){
					
					char upDownChar, myChar=line[i];
					int count=0;
					int r{0}, c{0};
								
					//if the character is below @ in the ASCII table, it will be conserved ans passed onto the string. 			
					if (myChar<=64){
						line2+=line[i];
						}		
					
					//Comparing to the cipher and encrypting
					while (count<=sizeof(secret)){
									
						upDownChar=line[i];
						upDownChar=toupper(upDownChar);
						
						if (upDownChar==secret[c][r] ){
							
							upDownChar=secret[r][c];
							line2+=upDownChar;
							}
									
				   		++c;
						++count;
									
						if(c>=5){
							c=0;
							++r;
							}
							
						if(r>=5){
							r=0;
							c=0;
							count=0;
							break;
							}
						}
						
				
				}
		
		//printing the result
		writeFile << "****************************************" << endl;
		writeFile << line << endl;
		writeFile << "encrypts to:" << endl;
		writeFile << line2 << endl;
		continue;
	}
	
//******************************************************************* decoding****************************************************************		
	
	if (line[0]=='D'){

				line.erase(0,2); //getting rid of the E or D. 
				
				for(int i=0;i<=line.size();i++){
					
					char upDownChar, myChar=line[i];
					int count=0;
					int r{0}, c{0};
					
					//if the character is below @ in the ASCII table, it will be conserved ans passed onto the string. 				
					if (myChar<=64){
						line2+=line[i];
						}		
					//Comparing to the cipher and decrypting
					while (count<=sizeof(secret)){
						
						if (secret[r][c] == line[i]){
						
							upDownChar=secret[c][r];
							upDownChar=tolower(upDownChar);
							line2+=upDownChar;
							}
									
				   		++c;
						++count;
									
						if(c>=5){
							c=0;
							++r;
							}
							
						if(r>=5){
							r=0;
							c=0;
							count=0;
							break;
							}
						}
						
				
				}
		
		//printing the result
		writeFile << "****************************************" << endl;
		writeFile << line << endl;
		writeFile << "decrypts to:" << endl;
		writeFile << line2 << endl;
		continue;
		
	}
//******************************************************************* Generating the cipher****************************************************************	
	else {
					
						//adding each letter of the alphabet to the vector
				for (int i=0;i<25;i++){
					
						alphabet.push_back(65+i);
					}
				
				//Adding the entire alphabet stored in the vector to the code word stored in the string
				for (int i=0;i<25;i++){
						
						line+=alphabet[i];
					}
											
				//Removing duplicates
				for(int i=0;i<=sizeof(line);i++){
					
					int count=i+1;
					
					while ( count < line.size() ){
				
						if (line[i] == line[count]){
						
							line.erase(count, 1);
						
				      	 	}
				    
						++count;
				     	
						}
				}
												
				writeFile << "    ";
												
				for (int i=0;i<=4;i++){
					
					writeFile << rows +i << "   ";
												
					}									
							
				//storing the key in the array, and printing it to file. 
								
				for (int i=0;i<sizeof(secret);i++){
						
						if(columns==0){
							writeFile << "\n" << rows << " | "; 
						}
						
						secret[rows][columns]=line[i];
								
						writeFile << secret[rows][columns] << " | "; 
						
						columns++;
									
						if(columns>=5){
							
							columns=0;
							writeFile << endl;
							writeFile << " ---------------------" << endl;
							++rows;
							}
							
						if(rows>=5){
							break;
							}
							
						}
				
					
					}
										
				}
readFile.close();
writeFile.close();
				
				
	return 0;
}


