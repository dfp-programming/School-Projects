#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int MAX_STUDENTS = 20;

struct student {
	string studentFName, studentLName;
	float testScore;
	string grade;

	student(){
		studentFName = "No_Name";
		studentLName = "Unknown";
		testScore = 0;
		grade = "W";
	}
		
};

void readStudentsFromFile(ifstream& readFile, student mp1_Student[]) {

	int count{ 0 };

	while (readFile >> mp1_Student[count].studentFName >> mp1_Student[count].studentLName >> mp1_Student[count].testScore) {

		++count;
		//if (count >= MAX_STUDENTS) break;

	}

}

void gradeMe(student mp1_Student[]) {

	/*A	93– 100 %
	A - 90 – 92 %
	B + 88 – 89 %
	B	82 – 87 %
	B - 80 – 81 %
	C + 78 – 79 %
	C	72 – 77 %
	C - 70 – 71 %
	D + 68 – 69 %
	D	62 – 67 %
	D - 60 – 61 %
	F	59 % and below*/

	for (int count = 0; count < MAX_STUDENTS; count++) {

		if (mp1_Student[count].testScore >= 93) mp1_Student[count].grade = " A";
		if (mp1_Student[count].testScore >= 90 && mp1_Student[count].testScore <= 92) mp1_Student[count].grade = "-A";
		if (mp1_Student[count].testScore >= 88 && mp1_Student[count].testScore <= 89) mp1_Student[count].grade = "+B";
		if (mp1_Student[count].testScore >= 82 && mp1_Student[count].testScore <= 87) mp1_Student[count].grade = " B";
		if (mp1_Student[count].testScore >= 80 && mp1_Student[count].testScore <= 81) mp1_Student[count].grade = "-B";
		if (mp1_Student[count].testScore >= 78 && mp1_Student[count].testScore <= 79) mp1_Student[count].grade = "+C";
		if (mp1_Student[count].testScore >= 72 && mp1_Student[count].testScore <= 77) mp1_Student[count].grade = " C";
		if (mp1_Student[count].testScore >= 70 && mp1_Student[count].testScore <= 71) mp1_Student[count].grade = "-C";
		if (mp1_Student[count].testScore >= 68 && mp1_Student[count].testScore <= 69) mp1_Student[count].grade = "+D";
		if (mp1_Student[count].testScore >= 62 && mp1_Student[count].testScore <= 67) mp1_Student[count].grade = " D";
		if (mp1_Student[count].testScore >= 60 && mp1_Student[count].testScore <= 61) mp1_Student[count].grade = "-D";
		if (mp1_Student[count].testScore <= 59) mp1_Student[count].grade = " F";
	}

 }

void print_Students(ofstream& writeFile, student mp1_Student[]) {

	writeFile << left << setw(25) << "Last Name, First Name" << setw(10) << "SCORE" << "GRADE\n" << endl;

	writeFile << fixed << setprecision(2);
	for (int i = 0; i < MAX_STUDENTS; i++) {

		writeFile << setw(20) << left << (mp1_Student[i].studentLName + ", " + mp1_Student[i].studentFName) << setw(10) << right << mp1_Student[i].testScore << setw(8) << mp1_Student[i].grade << endl;
	}
}

void high_Score(ofstream& writeFile, student mp1_Student[]) {

	writeFile << "\nThe students with the highest scores are\n" << endl;
	writeFile << fixed << setprecision(2);
	for (int i = 0; i < MAX_STUDENTS; i++) {

		if (mp1_Student[i].grade == " A") {
			writeFile << setw(20) << left << (mp1_Student[i].studentLName + ", " + mp1_Student[i].studentFName) << setw(10) << right << mp1_Student[i].testScore << setw(8) << mp1_Student[i].grade << endl;
		}
	}
}


int main()
{
	ifstream readFile("MP1_Students.txt");
	ofstream writeFile("MP1_Result.txt");
	student mp1_Student[50];

	readStudentsFromFile(readFile, mp1_Student);
	gradeMe(mp1_Student);
	print_Students(writeFile, mp1_Student);
	high_Score(writeFile, mp1_Student);

	readFile.close();
	writeFile.close();

}

