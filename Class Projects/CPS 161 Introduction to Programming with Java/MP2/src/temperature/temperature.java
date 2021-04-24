package temperature;
import java.util.Scanner;


public class temperature {

	public static void main(String[] args)
	{
	
		//creating variables
		int count = 0;
		float cent = 0, lifeTimeCent = 0;
		Scanner fromConsole = new Scanner(System.in);
			
		System.out.printf("Welcome to the \"Metric is Much Better\" temperature converter!\n\n");	
		
		//getting input data
		while(cent>-100) 
		{
			System.out.printf("Please enter your temp in Celcius.  Enter -100 or less to quit.\n");
			cent = fromConsole.nextFloat();
			
			// a way out
			if(cent <= -100) continue;
			
			//calculations
			if(cent > -100)
			{
				lifeTimeCent += cent;
				++count;
			}
			
			//printing
			System.out.printf("C(%.2f)\tF(%.2f)\n",cent,((cent*1.8) + 32));	
			
		}
		
		System.out.printf("Average:\tCentigrade(%.2f)\tFahrenheit(%.2f)\n",(lifeTimeCent/count),(((lifeTimeCent/count)*1.8) + 32));
		
	}
}
