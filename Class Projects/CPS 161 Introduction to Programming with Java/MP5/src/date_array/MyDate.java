package date_array;

public class MyDate {

	private String month;
	private int day, year;
	
	MyDate(String month, int day, int year)
	{
		this.month = month;
		this.day = day;
		this.year = year;
	}
	
	public String toString()
	{
		return month + " " + day + ", " + year; 
	}
	
}
