package roman_calculator;
import java.util.Scanner;

public class RomanCalculator {
	public static Scanner kbInput = new Scanner(System.in);

	public static String doMath(char operator, int firstNum, int secondNum) {
		/*
		 * This method will perform the arithmetic
		 * indicated by the operator (+ -* /),
		 * invoke convertToRoman to convert answer to Roman number,
		 * then return answer
		 * */
		
		int result = 0;
		String outputMessage = "Result = ";
		
		//Roman numerals didn't allow for negative numbers.
		if(firstNum < 0 || secondNum < 0)
		{
			return "Invalid Calculation";
		}
		
		else
		{
				
			switch (operator)
			{
			case '+':
				
				result = (firstNum + secondNum);
				return outputMessage + convertToRoman(result);
				
			case '-':
				
				result = (firstNum - secondNum);
				
				//check if the result would be negative
				if (result > 0)
					return outputMessage + convertToRoman(result);
				else
					return outputMessage + "Nullus";
							
			case '/':
				
				//first check if there is division by zero, which would crash the program
				if(secondNum == 0)
					return "Division by zero is not allowed";
				
				//Otherwise, return the appropriate result
				else
				{
					result = (firstNum / secondNum);
					
					if (result == 0)
						return outputMessage + "Nullus";
					
					else
						return outputMessage + convertToRoman(result);
				}
				
				
			case '*':
				
				result = (firstNum * secondNum);
				return outputMessage + convertToRoman(result);
				
			default:
				
				return "Invalid calculation";
				
			}
		}		
	}

	public static char getOperator() {
		
		System.out.print("Please choose an operator: +, - , * , or /: ");
		
		char input = ' ';
		
		while(true)
		{
			input = kbInput.next().charAt(0);
			
			if (input == '+' || input == '-' || input == '/' || input == '*')
				return input;
			else
				System.out.print("Invalid operator..... use: +, - , * , or /: ");
		
		}
	}

	public static int getOperands() 
	{
		/*This routine should prompt the user to enter Roman number. 
		  convertFromRoman needs to be invoked to convert the Roman number to an integer.
		  If the input is invalid (-1 returned from convertFromRoman)
		  then complain and prompt the user again. 
		*/
		String input = new String();
				
		System.out.print("Enter a roman number, or input \'q\' to quit: ");
		
		while(true)
		{
			input = kbInput.next();
			
			if (input.charAt(0) == 'q' || input.charAt(0) == 'Q')
				{
					System.out.print("Vale te videre deinde tempore!!");
					System.exit(0);
				}
			
			else if(convertFromRoman(input) == -1)
			{
				System.out.print("Invalid Roman.... Try again or \'q\' to quit: ");	
				continue;
			}
			
			else
				return convertFromRoman(input);
				
		}
		
	}
	
	public static int convertFromRoman(String romanNum)
	{
		/*
		 * This method will convert Roman number to integer
		 * return -1 when input is invalid
		 * 
		 * */
		int romanDecimal = 0;
	
		for (int i = 0 ; i < romanNum.length(); i++)
		{
			/*
			I 1
			V 5
			X 10
			L 50
			C 100
			D 500
			M 1000
			*/
									
			switch (romanNum.charAt(i))
			{
			//I decided to use the ASCII table instead of simply writing the char value.
			//I then realized the code would work regardless, but since it worked fine the first time,
			//It was just easier to leave it.  
			
			
				//I or i
				case 73:
				case 105:
					romanDecimal +=1;
					break;
				//V or v
				case 86:
				case 118:
					romanDecimal +=5;
					break;
				//X or x
				case 88:
				case 120:
					romanDecimal +=10;
					break;
				//L or l
				case 76:
				case 108:
					romanDecimal +=50;
					break;
				//C or c
				case 67:
				case 99:
					romanDecimal +=100;
					break;
				//D or d
				case 68:
				case 100:
					romanDecimal +=500;
					break;
				//M or m
				case 77:
				case 109:
					romanDecimal +=1000;
					break;
				//default
				default:
					System.out.println(romanNum.toUpperCase() + " has a bad character at position " + i);
					return -1;
					
			}
		}
		
	return romanDecimal;
		
	}
	
	public static String convertToRoman(int num) {
		/*
		 * This method will convert integer to Roman number
		 * */
		String romanNum = new String();
	
		//way out in case of bad input
		if(num == -1)
			return "Invalid Roman";
		else
		{
			while(true)
			{
				//I felt using if statements was more appropriate. 
				if(num-1000 >= 0)
				{
					num -= 1000;
					romanNum += 'M';
				}

				else if(num-500 >= 0)
				{
					num -= 500;
					romanNum += 'D';
				}

				else if(num-100 >= 0)
				{
					num -= 100;
					romanNum += 'C';
				}
	
				else if(num-50 >= 0)
				{
					num -= 50;
					romanNum += 'L';
				}
				
				else if(num-10 >= 0)
				{
					num -= 10;
					romanNum += 'X';
				}
				
				else if(num-5 >= 0)
				{
					num -= 5;
					romanNum += 'V';
				}
				
				else if(num-1 >= 0)
				{
					num -= 1;
					romanNum += 'I';
				}
				
				if(num <= 0)
					return romanNum;
			}
		}
	}

	public static void main(String[] args) {
		
		String result;
		
		do {

			result = doMath(getOperator(), getOperands(), getOperands());

			System.out.println(result);
			System.out.println("do you want to continue? y/n");
			kbInput.nextLine();
		} while (kbInput.nextLine().charAt(0) == 'y');
		System.out.println("Have a nice day!");
	}

}
