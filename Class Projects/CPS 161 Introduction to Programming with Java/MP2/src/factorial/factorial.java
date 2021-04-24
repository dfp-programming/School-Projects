package factorial;
import java.util.Scanner;
public class factorial {

	public static void factorialCal(int n)
	{
		int temp = 1;
		
		if(n < 0) 
		{
			System.out.println("Factorial of a negative number is pure imagination");
			return;
		}
		
		if(n == 0) 
		{
			System.out.println("Factorial of " + n +" = " + n);
			return;
		}
		
		else
		{
			System.out.print("Factorial of " + n +" = ");
			
			for(int i = 1; i <= n; i++)
			{
				temp *= i; 
				System.out.print(i);
				if (i < n) 
					System.out.print("x");
			}
			
			System.out.println(" = " + temp);
		}
	}
	
	public static void main(String[] args) 
	{
		String stayOrGo=" ";
		int myInt = 0;
		Scanner fromConsole = new Scanner(System.in);
		
		System.out.println("Welcome to the \"Crazy Multiplicator 9000\" factorial calculator!");
		
		while((stayOrGo.startsWith("N") || stayOrGo.startsWith("n") )== false)
		{
		
			System.out.println("Please enter an integer to be factored");
			
			if(!fromConsole.hasNextInt())
			{
				String temp = fromConsole.next();
				System.out.println("What? \"" + temp + "\" is not an integer, let's try that again!\n");
				continue;
			}
			else 
			{
				myInt = fromConsole.nextInt();
				factorialCal(myInt);
			}
						
			System.out.println("\nDo another one? N/n to quit, anything else to continue.");
			
			stayOrGo = fromConsole.next();

		}
		
		System.out.println("Chao!");
	}

}
