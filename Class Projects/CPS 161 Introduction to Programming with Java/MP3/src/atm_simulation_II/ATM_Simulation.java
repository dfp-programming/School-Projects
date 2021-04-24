package atm_simulation_II;

public class ATM_Simulation 
{

	public static void main(String[] args) 
	{

		int choice = 0;
		Bank myAccount = new Bank();
		
		while(choice != 4)
		{
			System.out.print("Main menu:\n 1: check balance \n 2: withdraw \n 3: deposit \n 4: exit \nEnter a choice: ");
			choice = Bank.fromConsole.nextInt();
			
			switch(choice)
			{
			case 1:
				myAccount.check_Balance();
				choice = 0;
				break;
			case 2:
				myAccount.withdraw();
				choice = 0;
				break;
			case 3:
				myAccount.deposit();
				choice = 0;
				break;
			case 4:
				System.out.print("Thank you for using the CPS 161 banking system.  Good bye!");
				choice = 4;
			}
		}			
	}
}
