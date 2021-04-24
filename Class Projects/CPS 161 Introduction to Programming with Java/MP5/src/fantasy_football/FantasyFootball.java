package fantasy_football;
import java.util.Scanner;

public class FantasyFootball
{
	private int numberOfTeams; // Same as teamAverage.length.
	private int numberOfWeeks; // Same as weekAverage.length.
	private int[][] scores; //numberOfTeams rows and numberOfWeeks columns.
	private double[] weekAverage; // contains an entry for each week
	private double[] teamAverage; // contains an entry for each team
	private String[] teamName; // contains an entry for each team
	
	public Scanner keyboard = new Scanner(System.in);
	
	public void enterInData( )
	{
		
		
		System.out.println("Enter number of teams:");
		numberOfTeams = keyboard.nextInt( );
		
		System.out.println("Enter number of weeks:");
		numberOfWeeks = keyboard.nextInt( );
		
		// ************** Fill in Code ***************
		// Allocate array memory for teamName to store the team names.
		// Allocate array memory for scores (2 dimensional array) to store a
		// score for each team for each week.
	
		teamAverage = new double[numberOfTeams];
		weekAverage = new double[numberOfWeeks];
		teamName = new String[numberOfTeams];
		scores = new int[numberOfTeams][numberOfWeeks];
		
		for (int team = 0; team < numberOfTeams; team++)
		{
			System.out.println("Enter team name");
					// ************* Fill in Code **************
			// Read in Team name and store it in teamName
			teamName[team] = keyboard.next();
		
			for (int week = 0; week < numberOfWeeks; week++)
			{
				System.out.println("Enter score for team "+ teamName[team]);
				System.out.println("on week number " + (week+1));
				// ************ Fill in Code ***************
				// Read in a score and store it in the proper spot in the scores array
				scores[team][week] = keyboard.nextInt();
			}
		}
	}
	
	public void fillTeamAverage( )
	{
		//********* Fill in Code *************
		// Allocate memory for the teamAverage.
		// Each entry in this array will contain the
		// average weekly score for a given team.
		
		for (int team = 0; team < numberOfTeams; team++)
		{
			for (int week = 0; week < numberOfWeeks; week++)
			{
				teamAverage[team] += scores[team][week];

				if(week == numberOfWeeks -1)
					teamAverage[team] /= numberOfWeeks;
			}
				
		}
			
	}
	
	public void fillWeekAverage( )
	{
		//*********** Fill in Code *************
		// Allocate memory for the weekAverage instance variable.
		// Each entry in this array will contain the average of
		// all teams for a given week.
		
		for (int week = 0; week < numberOfWeeks; week++)
		{
			for (int team = 0; team < numberOfTeams; team++)
			{
				weekAverage[week] += scores[team][week];
				
				if(team == numberOfTeams -1)
					weekAverage[week] /= numberOfTeams;
			}
				
		}
		
	}
	
	public void display( )
	{
		//********* Fill in Code ****************
		// This method will print out the display that was shown above.
		// At this point all of the information can be found in the
		// private instance variables of the FantasyFootball class
		
		System.out.printf("%-20s%9s%9s%9s\n" ,"Team name", "Week 1", "Week 2", "Week 3");
		
		for (int team = 0; team < numberOfTeams; team++)
		{
			System.out.printf("%-20s", teamName[team]);
			
			for (int week = 0; week < numberOfWeeks; week++)
			{
				System.out.printf("%9d", scores[team][week]);
				
				if(week == numberOfWeeks -1)
					System.out.printf(" ave = %.0f \n", teamAverage[team]);
			}
			
		}
		
		System.out.printf("%-20s" ,"Weekly Ave:");
		for (int week = 0; week < numberOfWeeks; week++)
		{
			System.out.printf("%9d", (int)weekAverage[week]);
		}
		
	
	}
	
	public static void main(String[] args)
	{
		FantasyFootball f= new FantasyFootball();
		f.enterInData();
		f.fillTeamAverage();
		f.fillWeekAverage();
		f.display();
	}
}