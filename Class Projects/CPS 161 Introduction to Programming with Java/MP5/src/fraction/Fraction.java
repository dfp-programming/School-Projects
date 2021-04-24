package fraction;
import java.util.*;


public class Fraction
{
	private Scanner scan = new Scanner(System.in);
	private int num=1;
	private int denom=1;
	
	public Fraction()
	{
		num=0;
		denom =1;
	}
	
	public Fraction(int n, int d)
	{
	// Fill in code (good to use setFraction)
		setFraction(n,d);
	}
	
	public void setFraction(int n, int d)
	{
	//Fill in code ... don't forget to reduce
		
		this.num = n;
		this.denom = d;
		reduce();		
		
	}
	
	public int returnNum()
	{
		return num;
	}
	
	public int returnDenom()
	{
		return denom;
	}
	
	public Fraction add(Fraction op)
	{
	//Fill in code ... don't forget to reduce
	// Algebra HINT: a/b + c/d = (a*d + b*c)/(b*d)
		
		op.num = (this.num * op.denom + this.denom*op.num);
		op.denom *= this.denom;
		op.reduce();
		return op;
	}
	public Fraction subtract(Fraction op)
	{
	//Fill in code ... don't forget to reduce
	// Algebra HINT: a/b - c/d = (a*d - b*c)/(b*d)
		op.num = (this.num * op.denom - this.denom*op.num);
		op.denom *= this.denom;
		op.reduce();
		return op;
	}
	public Fraction multiply(Fraction op)
	{
	//Fill in code ... don't forget to reduce
	// Algebra HINT: a/b * c/d = (a*c)/ (b*d)
		
	if(this.denom == 0 || op.denom == 0 )
	{
		System.out.println("Denominator will equal zero, which is not allowed.");
		System.out.println("Returning default value: 0/1");
		
		return new Fraction();
	}
	else
	{
		op.num *= this.num;
		op.denom *= this.denom;
		op.reduce();
		return op;
	}

	}
	public Fraction divide(Fraction op)
	{
	//Fill in code ... don't forget to reduce
	// Algebra HINT: a/b / c/d = (a*d)/ (b*c)
		
		if(this.denom == 0 || op.num == 0 )
		{
			System.out.println("Denominator will equal zero, which is not allowed.");
			System.out.println("Returning default value: 0/1");
			
			return new Fraction();
		}
		else
		{
			op.num *= this.denom;
			op.denom *= this.num;
			op.reduce();
			return op;
		}
	}
	
	private void reduce()
	{
	// Pseudo code:
	// set smaller = minimum ( abs(num), abs(denom));
	// Loop through the possible divisors: 2, 3, 4, ... smaller
	// For each possible divisor:
	// while (num and denom are evenly divisible by divisor)
	// {
	// num /= divisor;
	// denom /= divisor;
	// smaller /= divisor;
	// }
		int temp = 2;	
		
		if(Math.abs(num)% Math.abs(denom) == 0)
		{
			num = num/denom;
			denom = 1;
		}
		
		else if (num == denom)
		{
			num = 1;
			denom = 1;
		}
		
		else
		{
			
			while (temp <= num )
			{	
				//Line for simple troubleshooting of the reduce method
				//System.out.println("Reducing: "+this.toString() + "  temp = " + temp);
				if(num%temp == 0 && denom%temp == 0)
				{
					num /= temp;
					denom /= temp;
				}
				++temp;
			}
			
		}
				
				
	}
	
	public boolean equals(Fraction f)
	{
	// Assuming all fractions are reduced. Fill in code
		if (this.num == f.num && this.denom == f.denom)
			return true;
		else
			return false;
	}
	
	public String toString()
	{
	// Fill in code
		return num + "/" + denom;
	}
	
	public void readin(String label)
	{
		while (true) // Keep trying if bad input is received
		{
			System.out.print(label);
			String temp = scan.next();
			temp = temp.trim(); // get rid of white space at the beginning and end
			int index = temp.indexOf('/');
			
			if (index >= 0)
			{
				String numStr = temp.substring(0, index);
				String denomStr = temp.substring(index+1);
				int n = Integer.parseInt(numStr);
				int d = Integer.parseInt(denomStr);
				setFraction(n,d);
				return;
			}
			else
				System.out.println("Input Fraction missing / ");
		}//Keep trying until you get it right
}
	
	
public static void main(String[] args)
{
	Fraction f1= new Fraction();
	Fraction f2= new Fraction();
	Fraction f3=null;
	Scanner scan = new Scanner(System.in);
	
while(true)
	{
	System.out.println(); // Add a blank line
	System.out.print("Enter operation: + - * / q (q ==> quit) : ");
	String input = scan.next();
	
	if (input.charAt(0) == 'q')
	break; // All done

	f1.readin("Enter Fraction 1: ");
	f2.readin("Enter Fraction 2: ");
	System.out.println("f1 = " + f1);
	System.out.println("f2 = " + f2);
	
	if (f1.equals(f2))
	System.out.println("f1 and f2 are equal");
	else
	System.out.println("f1 and f2 are not equal");
	
	switch (input.charAt(0))
	{
		case '+':
			f3 = f1.add(f2);
			System.out.println("f1+f2=" + f3);
			break;
		
		case '-':
			f3 = f1.subtract(f2);
			System.out.println("f1-f2=" + f3);
			break;
		
		case '*':
			f3 = f1.multiply(f2);
			System.out.println("f1*f2="+f3);
			break;
			
		case '/':
			f3 = f1.divide(f2);
			System.out.println("f1/f2="+f3);
			break;
		
		default:
			System.out.println("Illegal command: " + input );
			break;
	}
}// end of while loop

System.out.println("Bye");
scan.close();

} // end of main
}