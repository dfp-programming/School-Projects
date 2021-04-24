package make_change;
import java.util.Scanner;

public class MakeChange 
{

	public static void main(String[] args)
	{
		//defining variables
		int totalCost = 0, receivedTotal = 0, totalChange = 0;
		int dollars = 0, quarters = 0, dimes = 0, nickels = 0, pennies = 0;
		Scanner fromConsole = new Scanner(System.in);
			
		//gathering amounts
		System.out.println("Welcome to the \"Nickel and Dime\" change calculator!");
		
		System.out.println("How many whole dollars does the item cost?");
		totalCost = fromConsole.nextInt()*100;
		
		System.out.println("How many cents?");
		totalCost = totalCost + fromConsole.nextInt();
		
		System.out.println("Total cost: " + totalCost + " cents");
			
		System.out.println("How many dollars did the customer give you?");
		receivedTotal = fromConsole.nextInt()*100;
		
		System.out.println("How many cents?");
		receivedTotal = receivedTotal + fromConsole.nextInt();
		
		System.out.println("Total payment: " + receivedTotal  + " cents");
		
		//calculating change refund
	
		totalChange = receivedTotal - totalCost;
		
		if (totalChange < 0)
			System.out.println("The customer still owes you " + (totalChange*-1) + " cents.");
			
		if (totalChange == 0)
			System.out.println("No Change is due.");
		
		if (totalChange > 0) 
		{
				
			System.out.printf("Change due: %d cents. Which can be broken down into:%n%n", totalChange);	
			dollars = totalChange / 100;
			totalChange %= 100;
			
			quarters = totalChange / 25;
			totalChange %= 25;
			
			dimes = totalChange / 10;
			totalChange %= 10;
			
			nickels = totalChange / 5;
			totalChange %= 5;
			
			pennies = totalChange;
			
			//printing the change due to the customer
			System.out.println("Change to be returned");
			System.out.printf("%-10s %d %n", "Dollars:", dollars);
			System.out.printf("%-10s %d %n","Quarters:", quarters);
			System.out.printf("%-10s %d %n","Dimes:", dimes);
			System.out.printf("%-10s %d %n","Nickels:", nickels);
			System.out.printf("%-10s %d %n","Pennies:", pennies);
		}

	}

}
