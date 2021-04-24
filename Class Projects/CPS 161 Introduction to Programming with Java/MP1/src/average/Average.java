package average;
import java.util.Scanner;

public class Average 
{

	public static void main(String[] args) 
	{
		//creating variables
		  double[] myArray = new double[3];
		  double average = 0.0;
		  Scanner fromConsole =  new Scanner(System.in);
		  
		  //getting user input
		  System.out.println("Welcome to the \"Middle Child\" average calculator!\n" + "Please enter a number."); 
		  myArray[0] = fromConsole.nextDouble();
		  
		  System.out.println("Enter another number"); 
		  myArray[1] = fromConsole.nextDouble();
		  
		  System.out.println("Enter the last number"); 
		  myArray[2] = fromConsole.nextDouble();
		  	  
		  //calculating average
		  average = (myArray[0] + myArray [1] + myArray[2])/myArray.length;
		  
		  System.out.printf("You have entered: %-7.2f %-7.2f and %-7.2f\n", myArray[0], myArray [1], myArray[2]); 
		  System.out.printf("The average of these numbers is: %.2f %n", average);

	}

}
