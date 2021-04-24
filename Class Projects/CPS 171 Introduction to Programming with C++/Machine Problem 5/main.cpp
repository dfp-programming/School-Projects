#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*
void secretKey(ofstream &writeFile, string line, char secret[4][4]){
	
	vector<char> encryption;
	int vSize{0}, count{0}, r{0}, c{0};

	for (int i=0;i<=25;i++){
		
		encryption.push_back(65+i);
		}
		
	vSize=encryption.size();

	for (int i=0;i<=vSize;i++){
		
		do{
			if(line[i]==encryption[count]){
				
				secret[r][c]=line[count];
				encryption.erase(encryption.begin()+count,encryption.begin()+count);
				}
				
				c++;
				
		if(c>=4){
			c=0;
			++r;
			}
		
		if(r>=4){
		break;
			}
				
				++count;
			//	break;									
			}
		while(count<=line.size());
		
		writeFile << r << c << endl;
		writeFile << "line[i] " << line[i] << endl;	
		writeFile << "encryption " << encryption[i] << endl;
		writeFile << "secret " << secret[r][c] << endl;	
		
			
		
	}





	for (int i=0;i<=25;i++){
		
	writeFile << encryption[i] <<endl;
	}
	

/*	
	 //vector <char> encryption=(25,'A');//,'B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y'};///{"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y"};/
	
//	int lenght = sizeof(encryption)/sizeof(encryption[0]);
	int r{0}, c{0}, count{0};
//	bool compare;
//	int rows = sizeof(secret)/sizeof(secret[0]);
//	int columns = sizeof(secret[0])/sizeof(secret[0][0]);
	
	for(int i=0;i<=lenght;i++){
						
		
				do{
					
					if (encryption[i]!=' '){
					
						secret[r][c]=line[i];					
						encryption[i]=' ';
					
							}
					
						
					++count;
					}
				
				while(count<=lenght);
	
		writeFile << r << c << encryption[i]<<endl;
		writeFile << secret[r][c] << endl;			
		
		c++;
				
		if(c>=4){
			c=0;
			++r;
			}
		
		if(r>=4){
		break;
			}	
					
	}
	
	
}
	*/
char decode(char decrypt){
	
	
}


char encrypt(char code){
	
	
}	

int main() {
	
ifstream readFile("messages.txt");
ofstream writeFile("result.txt");

int vSize{0}, mainCount{0}, count{0}, row{0}, column{0};
string placeHolder;
char codeWord[4][4];
vector<char> encryption; 
string letter1, letter2;
bool usedThisLetterB4{false};

getline (readFile,placeHolder);

//secretKey(writeFile, placeHolder, codeWord);

for (int i=0;i<25;i++){
		
		encryption.push_back(65+i);
	}
		
vSize=encryption.size();

while(mainCount<vSize){

		while(count<=encryption.size()){
				
				letter1=placeHolder[mainCount];
				letter2=encryption[count];
				
				if(letter1==letter2){
					usedThisLetterB4=true;
				//	letter1=placeHolder[mainCount];
							
				}
				writeFile << "main count = " << mainCount << endl;
				writeFile << "count = " << count << endl;
				writeFile << "letter1 = " << letter1 << endl;
				writeFile << "letter2 = " << letter2 << endl;
				writeFile << "usedThisLetterB4 = " << usedThisLetterB4 << endl;
				count++;
				
			}

	count=0;
	usedThisLetterB4=false;
	
	
	if(usedThisLetterB4==false){
	
		codeWord[row][column]=placeHolder[mainCount];				
	//	encryption.erase(encryption.begin()+mainCount);
	}
			
	writeFile << row << column << endl;
	writeFile << "*************************************** codeWord = " << codeWord[row][column] << endl;

	++column;
				
	if(column>=4){
		column=0;
		++row;
		}
		
	if(row>=4){
		break;
		}
				
	++mainCount;

}

	//	writeFile << "vSize = " << vSize << endl;
	//	writeFile << "count = " << count << endl;
	//	writeFile << "placeHolder[i] = " << placeHolder[i] << endl;
	//	writeFile << "letter = " << letter << endl;
	//	writeFile << "letter2 = " << letter2 << endl;
	//	writeFile << "encryption[i] = " << encryption[i] << endl;
			
					
	//		
	

		
	
	
	
	
	
	
	
	
	
	
	
	
	

/*
while(!readFile.eof()){

	getline (readFile,placeHolder);
	
	if (placeHolder[0]=='E'){
		
	}
	
	else if (placeHolder[0]=='D'){
		
	}
	
	else {
		
		secretKey(writeFile, placeHolder, codeWord);
			
	}
	
	cout << placeHolder << endl;
}*/
	return 0;
}
