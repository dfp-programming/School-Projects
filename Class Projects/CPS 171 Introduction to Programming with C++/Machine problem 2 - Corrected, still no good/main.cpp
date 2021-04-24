/*Hi, this program is meant to read a file containing information of college aplicants such as the school they applied to, their grades, and if their parents attended the same college previously or not.
After it reads the information, the program will evaluate each applicant and decide if they get accepted or not based on the schools's criteria.  The information of the people accepted gets stored 
in a another text file called mp2accept.txt. At the same time, this program will echo the information for each applicant and will print in the file if they were accepted or not, and the reason for rejection. 

To get into Liberal Arts, a minimum combinated SAT of 1200 and a GPA of 3.5 or higer is required if the applicant's parents never attended that school. Otherwise, combined SAT of 1000 and GPA 3.0 or higher.
Only the first five applicants can get in even if their parents are alumni. To get into Music, a minimum verbal SAT of 500 is required. Only the first three applicants can get in. 

I hope you enjoy my program, for I spent a great deal of time putting it together and making it match as close as I could to the requirements of MP2.

Diego F. Perez - CPS171, section D01 - MACHINE PROBLEM 2. */

#include <iostream>  
#include <fstream>    
#include <iomanip>    
using namespace std;


int main() {
	
	//Declaring variables to store applicants data, and to count the total number of them.
	char school, alumnus;
	double gpa{0.0};
	int liberalCount{0}, musicCount{0}, totalCount{0}, combinedSat{0.0}, verbalSat{0.0}, mathSat{0.0};
	
	//Inventing two objects to read and write into a file. It also creates the file to record the appliants that will get accepted.
	ifstream readFromFile("applicant_list.txt");
	ofstream writeToFile("mp2accept.txt");


	//Main loop. All the magic happens here and I will break it down in steps. The statement !readFromFile.oef() allows the while loop to continue until the end of the file is reached.
	//It is important the input file doesn't contain a ghost blank line at the end or it will read the last line twice!!
	while(!readFromFile.eof()){
	
		++totalCount;	// since this loop evaluates one line at the time before starting over, I need to count each time this happens to know the number of applicants. 
		
		readFromFile >> school >> gpa >> mathSat >> verbalSat >> alumnus; // reading applicants data into the variables
				
		//This screens applicants who's parents never attended liberal arts school and have the right scores. Only the first five will get in. 
		if((school=='L')&&(alumnus=='N')&&(gpa>=3.5)&&(verbalSat+mathSat)>=1200&&(liberalCount<5)){
		
		
			//print a message with the applicants info and acceptance into Liberal Arts school. Also adding one to the acceptance count
			++liberalCount;
			writeToFile << "Applicant #: " << totalCount <<endl;
			writeToFile << "School = " << school << " GPA = "  << showpoint << setprecision(2) << gpa <<" math = " << setprecision(0) << mathSat << " verbal = " << verbalSat << " alumnus = " << alumnus << endl;
			writeToFile << "Applying to Liberal Arts" << endl;
			writeToFile << "Accepted to Liberal Arts!! " << endl;
			writeToFile << "*******************************\n" << endl;
				
	  		}
		//This screens applicants who's parents attended liberal arts school and have the right scores. Only the first five will get in.
		else if((school=='L')&&(alumnus=='Y')&&(gpa>=3.0)&&(verbalSat+mathSat)>=1000&&(liberalCount<5)){
			
			
					
				//print a message with the applicants info and acceptance into Liberal Arts school.  Also adding one to the acceptance count
				++liberalCount;
				writeToFile << "Applicant #: " << totalCount <<endl;
				writeToFile << "School = " << school << " GPA = " << showpoint << setprecision(2) << gpa <<" math = " << mathSat << " verbal = " << verbalSat << " alumnus = " << alumnus << endl;
				writeToFile << "Applying to Liberal Arts" << endl;
				writeToFile << "Accepted to Liberal Arts!! " << endl;
				writeToFile << "*******************************\n" << endl;
			}
		
		//this screens applicants elegible for Music school.	
		else if ((school=='M')&&(mathSat>=500)&&(verbalSat>=500)&&(musicCount<3)){
			
					
					//print a message with the applicants info and acceptance into Music school.  Also adding one to the acceptance count
					++musicCount;
					writeToFile <<  "Applicant #: " << totalCount <<endl;
					writeToFile <<  "School = " << school << " GPA = " << showpoint << setprecision(2) << gpa <<" math = " << mathSat << " verbal = " << verbalSat << " alumnus = " << alumnus << endl;
					writeToFile <<  "Applying to Music" << endl; 
					writeToFile <<  "Accepted to Music!! " << endl;
					writeToFile <<  "*******************************\n" << endl;
					}
		
		// The next set of  statements will print to file messsages with the applicant's info that didn't get into school, and will state why. 
		else{
			writeToFile <<  "Applicant #: " << totalCount <<endl;
			writeToFile <<  "School = " << school << " GPA = " << showpoint << setprecision(2) << gpa <<" math = " << mathSat << " verbal = " << verbalSat << " alumnus = " << alumnus << endl;
			
			//this bit if for applicants rejected from liberal arts
			if(school=='L'){
				
				writeToFile <<  "Applying to Liberal Arts" << endl;
				
				//This part is for applicants who's parents are alumni. They either have PGA less than 3.0, combined SAT less than 1000, or the school was full.
				if(alumnus=='Y'){
					
					if (gpa<3.0){
						writeToFile <<  "Rejected - " << "GPA too low" << endl;
						writeToFile <<  "*******************************\n" << endl;
						}
					else if((mathSat+verbalSat)<1000){
						writeToFile <<  "Rejected - "<< "SAT too low" << endl;
						writeToFile <<  "*******************************\n" << endl;
						}
					else if(liberalCount>=5){
						writeToFile <<  "Rejected - " << "The school is full" << endl;
						writeToFile <<  "*******************************\n" << endl;
						}
					}
				//This part is for applicants who's parents are not alumni.  They either have GPA less than 3.5, combined SAT less than 1200, or the school was full. 
				if(alumnus=='N'){
					
					if (gpa<3.5){
						writeToFile <<  "Rejected - " << "GPA too low" << endl;
						writeToFile <<  "*******************************\n" << endl;
						}
					else if((mathSat+verbalSat)<1200){
						writeToFile <<  "Rejected - "<< "SAT too low" << endl;
						writeToFile <<  "*******************************\n" << endl;
						}
					else if(liberalCount>=5){
						writeToFile <<  "Rejected - " << "The school is full" << endl;
						writeToFile <<  "*******************************\n" << endl;
						}
					}	
					
				}
			
			//This part is for applicants rejected from music. They either have verbal SAT less than 500 or the school was full. 
			else if(school=='M'){
				writeToFile <<  "Applying to Music" << endl;
					
				if(verbalSat<500){
					writeToFile <<  "Rejected - "<< "SAT too low" << endl;
					writeToFile <<  "*******************************\n" << endl;
						}
				else if(mathSat<500){
					writeToFile <<  "Rejected - "<< "SAT too low" << endl;
					writeToFile <<  "*******************************\n" << endl;
						}
						
				else if (musicCount>=3){
						writeToFile <<  "Rejected - "<< "The school is full" << endl;
						writeToFile <<  "*******************************\n" << endl;
						}
					}
				}
				
			}
	
		
//Print to file the total applicant and acceptance count for each school to summarize the entire process.
writeToFile <<  "There were " << setw(2) << setfill('0') << totalCount << " applicants in the file"<< endl; 
writeToFile <<  "There were " << setw(2) << liberalCount << " acceptances to Liberal Arts"<< endl;
writeToFile <<  "There were " << setw(2) << musicCount << " acceptances to Music"<< setfill(' ') << endl;
 
// Close the streams. The files no longer need to be opened. 
readFromFile.close();   
writeToFile.close();

return 0;
}
