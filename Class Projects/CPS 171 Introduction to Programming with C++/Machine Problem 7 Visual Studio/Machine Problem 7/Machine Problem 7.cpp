#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>


using namespace std;

struct Diver {

	vector <float> scores;
	float addedScores, finalScore;
	
	//using the construtor to zero some key variables
	Diver() {
		addedScores = 0.0;
		finalScore = 0.0;
	}
	
	//storing and sorting the data
	void dataStorage(ofstream &writeFile, float sa, float sb, float sc, float sd, float se, float sf, float sg, float sh, float si, float sj) {

		//storing into the vector and sorting
		scores = { sa,sb,sc,sd,se,sf,sg,sh,si,sj };
		sort(scores.begin(), scores.end());
	}

	float totalScore(string currentDiver, string& winner, float& highScore) {

		//deleting the highest and lowest scores for the current diver
		scores.erase(scores.begin() + 1);
		scores.pop_back();

		//finding the diver's total score
		for (int i = 1; i < scores.size(); i++) {
			addedScores += scores[i];
		}
		finalScore = addedScores * scores[0];

		//if the new diver's total score is higher than the previous diver, then make the current diver the winner.
		if (finalScore > highScore) {
			winner = currentDiver;
			highScore = finalScore;
		}

		return finalScore;
	}
};



int main() {

	ifstream readFile("m7dive.txt");
	ofstream writeFile("mp7output.txt");
		
	float a, b, c, d, e, f, g, h, i, j, highScore{ 0.0 };
	string diverName, winner;
	

	//Writing the header
	writeFile << left << setw(12) << "NAME" << setw(6) << "DIFF" << setw(35) << right << "SORTED SCORES" << setw(29) << right << "POINTS" << endl;
	
	//loop to read each line of the file
	while (readFile >> diverName >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j) {

		//creating an object for the struct and feeding the data into some functions
		Diver currentDiver;
		currentDiver.dataStorage(writeFile, a, b, c, d, e, f, g, h, i, j);
		
		//Writing the sorted and processed data into the output file
		writeFile << setw(12) << left << diverName << setw(6) << fixed << setprecision(1) << currentDiver.scores[0];

		for (int i = 1; i < currentDiver.scores.size(); i++) {
			writeFile << setw(6) << right << currentDiver.scores[i];
		}
		writeFile << setw(10) << right <<currentDiver.totalScore(diverName,winner,highScore) << endl;
	}

	//conclusion
	writeFile << "\nThe winner is " << winner << " with the points of " << highScore;
	
	//closing the file streams
	writeFile.close();
	readFile.close();

	return 0;
}