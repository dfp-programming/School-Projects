package string_methods;
import java.util.Scanner;

public class MyStringMethods {
	
	private String myStr="";
	public Scanner fromConsole = new Scanner(System.in);
	
	public void readString()
	{
	// Prompt the user and read in a String from a Scanner class from the keyboard
	// with the nextLine() method and store it in "myStr"
		
	System.out.print("Please enter a string:\n");
	setString(fromConsole.nextLine());
	
	}
	
	public void setString(String s)
	{
	myStr = s;
	}
	
	public int countOccurrences(String s)
	{
		//use indexOf and return the number of occurrences of the string "s" in "myStr"
		int count = 0, currentIndex = 0;
				
		for(int i=0; i< myStr.length(); i++)
		{
			//if it returns -1, there are zero occurrences
			if (myStr.indexOf(s) == -1)
				return 0;
			
			else if (myStr.indexOf(s,currentIndex) >= 0)
			{
				currentIndex = myStr.indexOf(s,currentIndex);
				currentIndex += s.length();
				++count;
			}
			
			if (currentIndex >= myStr.length())
					return count;
		}
		
		return count;
	
	}
	
	
	public int countOccurrences(char c)
	{
		//I didn't want to type the code again, so I reused the method. 
		int count = countOccurrences(Character.toString(c));
		return count;
	}
	
	int countUpperCaseLetters()
	{
		// return the number of upper case letters in "myStr"
		
		int count = 0;
		char myCharArray[] = myStr.toCharArray();
	
		for (int i=0; i < myCharArray.length; i++)
		{
			if (Character.isUpperCase(myCharArray[i])==true)
				++count;
		}
		
		return count;
		
	}
	
	
	int countLowerCaseLetters()
	{
	// return the number of lower case letters in "myStr"
		
		int count = 0;
		char myCharArray[] = myStr.toCharArray();
	
		for (int i=0; i < myCharArray.length; i++)
		{
			if (Character.isLowerCase(myStr.charAt(i)) == true)
				++count;
		}
		
		return count;
		
	}
	
	public void printCounts(String s, char c)
	{
	System.out.println("***************************************");
	System.out.println("Analyzing: myStr="+myStr);
	System.out.println("Number of Upper case letters="+ countUpperCaseLetters());
	System.out.println("Number of Lower case letters="+ countLowerCaseLetters());
	System.out.println("Number of "+s + " is "+ countOccurrences(s));
	System.out.println("Number of "+c + " is "+ countOccurrences(c));
	}
	

}
