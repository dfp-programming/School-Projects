#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


string decrypt(string decrypt){

string returnLine;

	
return returnLine;	
}


string encrypt(string code){
	
string returnLine;
	

return returnLine;	
}	


int main() {
	
ifstream readFile("messages.txt");
ofstream writeFile("result.txt");

string line, action;


char secret[5][5];

vector<char> alphabet; 
int rows{0}, columns{0};

while(!readFile.eof()){

	getline (readFile,line);
	
	action=line[0];
	
	if (action=="E"){
		
		writeFile << "****************************************" << endl;
		writeFile << line << endl;
		writeFile << "encrypts to:" << endl;
		writeFile << encrypt(line) << endl;
				
	}
	
	else if (action=="D"){
		
		writeFile << "****************************************" << endl;
		writeFile << line << endl;
		writeFile << "decrypts to:" << endl;
		writeFile << decrypt(line) << endl;
		
		
	}
	
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
	return 0;
}


string decrypt(string decrypt){

string returnLine;

	
return returnLine;	
}



string encrypt(string code){
	
string returnLine;
	

return returnLine;	
}	




/*
void secretKey(ofstream &writeFile, string line, char secret[4][4]){


vector<char> alphabet; 


getline (readFile,temp_String1);

//secretKey(writeFile, placeHolder, codeWord);

cout << temp_String1 << endl;


//adding each letter of the alphabet to the vector
for (int i=0;i<25;i++){
		
		alphabet.push_back(65+i);
	}

//Adding the entire alphabet stored in the vector to the code word stored in the string
for (int i=0;i<25;i++){
		
		temp_String1+=alphabet[i];
	}

cout << temp_String1 << sizeof(codeWord) << endl;

//Removing duplicates
for(int i=0;i<=sizeof(temp_String1);i++){
	
	int count=i+1;
	
	while ( count < temp_String1.size() ){

		if (temp_String1[i] == temp_String1[count] ){
		
			temp_String1.erase(count, 1);
		
      	 	}
    
		++count;
     	
		}
}

cout << temp_String1 << sizeof(codeWord) << endl;

//storing the key in the array, and printing it to file. 

for (int i=0;i<sizeof(codeWord);i++){
		
		codeWord[rows][columns]=temp_String1[i];
				
		cout << codeWord[rows][columns] << " | "; 
		
		columns++;
					
		if(columns>=4){
			columns=0;
			cout << endl;
			++rows;
			}
			
		if(rows>=4){
			break;
			}
			
	}






const int t=8, w=8;

void secretKey(ofstream& writeFile, string line, char secret[t][w]){


vector<char> alphabet; 
int rows{0}, columns{0};
cout << line << endl;

//adding each letter of the alphabet to the vector
for (int i=0;i<25;i++){
		
		alphabet.push_back(65+i);
	}

//Adding the entire alphabet stored in the vector to the code word stored in the string
for (int i=0;i<25;i++){
		
		line+=alphabet[i];
	}

cout << line << sizeof(secret) << endl;

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

cout << line << sizeof(secret) << endl;

//storing the key in the array, and printing it to file. 

for (int i=0;i<sizeof(secret);i++){
		
		
		secret[rows][columns]=line[i];
				
		cout << secret[rows][columns] << " | "; 
		
		columns++;
					
		if(columns>=4){
			columns=0;
			cout << endl;
			++rows;
			}
			
		if(rows>=4){
			break;
			}
			
	}

}









	
*/
