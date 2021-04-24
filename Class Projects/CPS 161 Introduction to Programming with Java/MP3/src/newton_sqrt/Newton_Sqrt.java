package newton_sqrt;
import java.util.Scanner;


public class Newton_Sqrt {

	public static void main(String[] args) {

		Scanner fromConsole = new Scanner(System.in);
		double root = 0.0, guess = 0.0, userInput = 0.0;
		
		System.out.print("Hello and welcome to The Root! \n\nPlease enter a number, for which you want to know the square root: ");
		
		userInput = fromConsole.nextDouble();
		
		if (userInput == 0) 
			System.out.printf("The square root of % 7.9f is % 7.9f \n",userInput, userInput);
		
		else if (userInput < 0)
			System.out.printf("The square root of % 7.9f is not a rational number. Use your imagination!!!\n",userInput, root);
					
		else 
		{
			guess = userInput/2;
			
			while(true)
			{
				root = (guess + userInput/guess)/2;
											
				if (Math.abs(guess-root) <= 0.000001)
				{
					System.out.printf("The square root of %.3f using the Newton method is = \t % 7.9f \n",userInput, root);
					System.out.printf("The square root of %.3f using Math.sqrt() is = \t\t % 7.9f \n",userInput, Math.sqrt(userInput));
					break;
				}
				else guess = root;
			}
		}
	}
}
