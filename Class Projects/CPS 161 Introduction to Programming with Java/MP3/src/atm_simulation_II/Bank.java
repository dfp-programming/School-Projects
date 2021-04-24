package atm_simulation_II;
import java.util.Scanner;

public class Bank 
{

	public static Scanner fromConsole = new Scanner(System.in);
	int centsBalance = 10000;
	
	public void check_Balance()
	{
		System.out.printf("You have $% .2f in your account.\n\n",(float)centsBalance/100);
	}

	public void withdraw()
	{
		int totalWithdraw = 0;
		System.out.print("Enter the amount you would like to withdraw\n");
		
		System.out.print("Whole dollars: ");
		totalWithdraw = Math.abs(fromConsole.nextInt());
		totalWithdraw *= 100;
		
		System.out.print("Cents: ");
		totalWithdraw += Math.abs(fromConsole.nextInt());
		
		if (Math.abs(totalWithdraw) > centsBalance)
		{
			System.out.print("You do not have enough balance. Transaction ignored\n\n");
			
		}
			
		else 
		{
			centsBalance -= Math.abs(totalWithdraw);
			System.out.printf("$% .2f Have been withdrawn from your account\n\n", (float)totalWithdraw/100);
		}
	}
		
	public void deposit()
	{
		int totalDeposit = 0;
		System.out.print("Enter the amount you would like to deposit\n");
		
		System.out.print("Whole dollars: ");
		totalDeposit = fromConsole.nextInt();
		totalDeposit *= 100;
		
		System.out.print("Cents: ");
		totalDeposit += fromConsole.nextInt();
		
		if (totalDeposit < 0)
		{
			System.out.print("Negative deposits are not allowed. Transaction ignored\n\n");
		}
			
		else
		{
			centsBalance += totalDeposit;
			System.out.printf("$% .2f Have been deposited to your account\n\n", (float)totalDeposit/100);
		}
			
	}
	
}





