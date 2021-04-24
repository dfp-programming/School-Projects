package classDemo;

import java.awt.GraphicsDevice;
import java.util.Scanner;

public class GradeBook {

	double[][] grades;
	double[] studentAverage;
	double[] quizAverage;
	Scanner kbInput = new Scanner(System.in);
	int numberOfStudents;
	int numberOfQuizes;
	public GradeBook() {
		System.out.println("please enter the number of students:");
		numberOfStudents = kbInput.nextInt();
		System.out.println("please enter the number of quizes");
		numberOfQuizes = kbInput.nextInt();
		grades = new double[numberOfStudents][numberOfQuizes];
		for (int i = 0; i<grades.length;i++ ) {
			for(int j= 0; j< grades[i].length;j++) {
				System.out.println("please enter the grade for student"+i+" quiz"+j);
			    grades[i][j]= kbInput.nextDouble();
			}
		}
		studentAverage = new double[numberOfStudents];
		quizAverage = new double[numberOfQuizes];
		
	}
	public void getStudentAverage() {
		int sum, average;
		for (int i =0; i<numberOfStudents; i++) {
			sum =0;
			for (int j=0; j<numberOfQuizes; j++)
				sum += grades[i][j];
			studentAverage[i] = sum/numberOfQuizes;
		}
	}
	public void getQuizAverage() {
		int sum, average;
		for (int i =0; i<numberOfQuizes; i++) {
			sum =0;
			for (int j=0; j<numberOfStudents; j++)
				sum += grades[j][i];
			quizAverage[i] = sum/numberOfStudents;
		}
	}
	public void display() {
		for (int i = 0; i< grades.length;i++) {
			for (int j =0; j<grades[i].length;j++) {
				System.out.print(grades[i][j]+" ");
			}
		    System.out.println();	
		}
		
		for (double  x : quizAverage)
			System.out.println(x);
		
		for (double  x : studentAverage)
			System.out.println(x);
		
		
	}

	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		GradeBook myBook = new GradeBook();
		myBook.getStudentAverage();
		myBook.getQuizAverage();
		myBook.display();
	}

}
