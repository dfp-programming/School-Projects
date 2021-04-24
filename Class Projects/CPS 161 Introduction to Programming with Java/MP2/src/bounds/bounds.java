package bounds;
import java.util.Scanner;

public class bounds 
{

	public static void main(String[] args) 
	{
		//bounds problem
		
		//defining variables
		double start = 0, step = 0, limit = 0;
		int count = 1;
		Scanner fromConsole = new Scanner(System.in);
		
		//getting user data
		System.out.println("Welcome to the \"Glass Ceiling\" bounds problem" + "\n" + 
					"Please enter a starting number");
		start = fromConsole.nextDouble();
		
		System.out.println("Enter the step size");
		step = fromConsole.nextDouble();
		
		System.out.println("Enter the max limit");
		limit = fromConsole.nextDouble();
		
		System.out.printf("You have entered: % 7.2f % 7.2f and % 7.2f \n", start,step,limit);
		
		//printing out the steps
		for(double i = start; i < limit; i += step) 
		{
			System.out.printf("% 7.2f  ",((step*(count-1))+(start)));
			if(count % 10 == 0) System.out.printf("\n");
			++count;
		}
	}
}
