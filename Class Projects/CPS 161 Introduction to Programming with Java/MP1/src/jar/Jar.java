package jar;
import java.util.Scanner;

public class Jar 
{
	public static void main(String[] args) 
	{
		
		//creating variables
		  int quarters = 0, dimes = 0, nickels = 0, pennies = 0, total = 0;
		  Scanner fromConsole = new Scanner(System.in);
		  
		  System.out.println("Welcome to the \"Jar Magic\" counter.");
		  
		  //Getting user input
		  System.out.println("Enter in the number of Quarters in the Jar: "); 
		  quarters = fromConsole.nextInt();
		  
		  System.out.println("Enter in the number of Dimes in the Jar: "); 
		  dimes = fromConsole.nextInt();
		  
		  System.out.println("Enter in the number of Nickels in the Jar: "); 
		  nickels = fromConsole.nextInt();
		  
		  System.out.println("Enter in the number of Pennies in the Jar: "); 
		  pennies = fromConsole.nextInt();
		  
		  //calculating total cents
		  total = (quarters *25) + (dimes*10) + (nickels*5) + pennies;
		  
		  System.out.println("The jar contains " + total + " cents.");
		 

	}

}
