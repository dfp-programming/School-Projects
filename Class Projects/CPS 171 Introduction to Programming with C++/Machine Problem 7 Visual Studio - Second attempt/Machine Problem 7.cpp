
/*
Hello! this program will read a file that contains a set of strings with the names of participants in a diving competition.
In addition to the name, the files also contains the score given by each judge and the difficulty of the five. 

This program will read each line, organize the judge scores in ascending order, calculate the total score base on the sum of all the socres
(excet the lowest and the highest), and print this information to file.  In the end the program will determine the winner and print it to file as well. 

I had fund making this program.  There were some difficulties but I was able to overcome them. 

Diego F. Perez - CPS171, section D01 - MACHINE PROBLEM 7.

*/


#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//creating an enum in order to keep certain things contant or easy to change. 
const enum constants{JUDGES=9, NAME_WIDTH=12, DIFF_WIDTH=4, SORTED_SCORES_WIDTH=54, SCORE_WIDTH = 4, POINTS_WIDTH = 8};

//struct to store all of the diver's data
struct Diver {

	string name;
	double judgeScores[JUDGES];	//This way, the array size can be changed easily for the entire program by simply changing the ENUM.
	double difficulty{ 0.0 }, finalScore{0.0};

};

//Function to sort out an array inside a struct from low to high by reference. 
void sortScores(Diver& diver_) {
			
	double handoff{ 0.0 };

	for (int i = 0; i < JUDGES; i++) {
		for (int j = 0; j < JUDGES; j++) {
			
			if (diver_.judgeScores[j] > diver_.judgeScores[i]) {
				
				handoff = diver_.judgeScores[i];
				diver_.judgeScores[i] = diver_.judgeScores[j];
				diver_.judgeScores[j] = handoff;
			}
		}
	}
}

//Function to calculate the final score for each diver
void scoreCalculations(Diver& diver_) {
	
	//The lowest and highest score must not be taken into account, hence the start and end of the loop. 
	for (int i = 1; i < JUDGES-1; i++) {
		diver_.finalScore += diver_.judgeScores[i];
	}
	diver_.finalScore = diver_.finalScore * diver_.difficulty;
}


int main() {

	ifstream readFile("m7dive.txt");
	ofstream writeFile("mp7output.txt");
	double currentHighScore{ 0.0 };
	int numDivers{ 0 }, count{ 0 };
	Diver diver_[50];					//creating a struct array that can store data for up to 50 divers if needed.
	
	//Writing the header
	writeFile << left << setw(NAME_WIDTH) << "NAME" << setw(DIFF_WIDTH) << "DIFF" << setw(SORTED_SCORES_WIDTH / 2) << right << "SORTED";
	writeFile << setw(SORTED_SCORES_WIDTH/2) << left << " SCORES" << setw(POINTS_WIDTH) << right << "POINTS" << endl;

	//loop to read each line of the file and store the data of each diver into a struct.
	readFile >> numDivers;
	for (int i = 0; i < numDivers; i++) {
		readFile >> diver_[i].name >> diver_[i].difficulty;

		for (int j = 0; j < JUDGES; j++) {
			readFile >> diver_[i].judgeScores[j];
		}
	}
	
	//sorting the data for all the divers
	for (int i = 0; i < numDivers; i++) {
		sortScores(diver_[i]);
	}
	
	//calculating the score and the winer
	currentHighScore = diver_[count].finalScore;
	for (int i = 0; i < numDivers; i++) {
		scoreCalculations(diver_[i]);

		//determining the winner
		if (diver_[i].finalScore > currentHighScore) {
			
			currentHighScore = diver_[i].finalScore;
			count = i;
		}
	}
	
	//Writing the sorted and processed data into the output file
	writeFile << fixed << setprecision(1);
	for (int i = 0; i < numDivers; i++) {
		writeFile << setw(NAME_WIDTH) << left << diver_[i].name << setw(DIFF_WIDTH) << diver_[i].difficulty;

		for (int j = 0; j < JUDGES; j++) {
			writeFile << setw(6) << right << diver_[i].judgeScores[j];
		}
		writeFile << setw(POINTS_WIDTH) << right << diver_[i].finalScore << endl;
	}

	//conclusion
	writeFile << "\nThe winner is " << diver_[count].name << " with the points of " << diver_[count].finalScore;

	//closing the file streams
	writeFile.close();
	readFile.close();

	return 0;
}