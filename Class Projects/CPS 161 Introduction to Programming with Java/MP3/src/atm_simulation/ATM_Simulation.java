package atm_simulation;
import java.util.Scanner;

public class ATM_Simulation 
{
	
	public static Scanner fromConsole = new Scanner(System.in);
	
	public static void check_Balance(int money)
	{
		System.out.printf("You have $% .2f in your account.\n\n",(float)money/100);
	}

	public static int withdraw(int balance)
	{
		int totalWithdraw = 0;
		System.out.print("Enter the amount you would like to withdraw\n");
		
		System.out.print("Whole dollars: ");
		totalWithdraw = Math.abs(fromConsole.nextInt());
		totalWithdraw *= 100;
		
		System.out.print("Cents: ");
		totalWithdraw += Math.abs(fromConsole.nextInt());
		
		if (Math.abs(totalWithdraw) > balance)
		{
			System.out.print("You do not have enough balance. Transaction ignored\n\n");
			return balance;
		}
			
		else 
		{
			System.out.printf("$% .2f Have been withdrawn from your account\n\n", (float)totalWithdraw/100);
			return (balance - Math.abs(totalWithdraw));
		}
	}
		
	

	public static int deposit(int balance)
	{
		int totalDeposit = 0;
		System.out.print("Enter the amount you would like to deposit\n");
		
		System.out.print("Whole dollars: ");
		totalDeposit = fromConsole.nextInt();
		totalDeposit *= 100;
		
		System.out.print("\nCents: ");
		totalDeposit += fromConsole.nextInt();
		
		if (totalDeposit < 0)
		{
			System.out.print("Negative deposits are not allowed. Transaction ignored\n\n");
			return balance;
		}
			
		else
		{
			System.out.printf("$% .2f Have been deposited to your account\n\n", (float)totalDeposit/100);
			return balance+totalDeposit;
		}
			
	}
	
	public static void main(String[] args)
	{
		int choice = 0, totalCents = 10000;
		
		while(choice != 4)
		{
			System.out.print("Main menu:\n 1: check balance \n 2: withdraw \n 3: deposit \n 4: exit \nEnter a choice: ");
			choice = fromConsole.nextInt();
			
			switch(choice)
			{
			case 1:
				check_Balance(totalCents);
				choice = 0;
				break;
			case 2:
				totalCents = withdraw(totalCents);
				choice = 0;
				break;
			case 3:
				totalCents = deposit(totalCents);
				choice = 0;
				break;
			case 4:
				System.out.print("Thank you for using the CPS 161 banking system.  Good bye!");
				choice = 4;
			}
						
		}

	}

}

