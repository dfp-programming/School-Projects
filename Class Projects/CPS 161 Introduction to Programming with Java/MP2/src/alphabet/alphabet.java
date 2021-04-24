package alphabet;

public class alphabet {

	public static void main(String[] args) 
	{
		System.out.println("Welcome to \"Las Vocales\" alphabet classificator!\n");
		
		for(int i = 'a';i <= 'z'; i++)
		{
			if(i=='a'||i=='e'||i=='i'||i=='o'||i=='u') 
				System.out.printf("%c is a vowel\n",i);
			else 
				System.out.printf("%c is a consonant\n",i);
		}
	
	}

}
