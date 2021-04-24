package gas_mileage;
import java.util.Scanner;

public class Gas_mileage 
{
	public static void main(String[] arg)
	{
		//defining variables
		Scanner fromConsole = new Scanner(System.in);
		
		//Getting user data
		System.out.println("Hello and welcmome to the \'Wish I Own A Tesla\" gas mileage calculator!\n" + "Please enter how many miles you drove in your car.");
		double miles = fromConsole.nextDouble();
		
		System.out.println("Great! now tell me how many gallons of fuel you used.");	
		double gallons = fromConsole.nextDouble();
		
		//output
		System.out.printf("The estimated gas mileage from your car is: %.2f m/gal", (miles/gallons) );	
	}

}
