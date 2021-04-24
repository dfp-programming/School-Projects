package library;

public class Library {

	static void printBooks(Book[] inStock)
	{
		for (int i= 0; i < inStock.length; i++)
		{
			inStock[i].toString();
		}
	}
	
	static void fillLibraty(Book[] inStock)
	{
		Author JK_Rollings = new Author("Joanne","Rowling","1965-07-31");
		Author Michael_Crinton = new Author("Michael","Crichton","1942-10-03");
		Author William_Goldman = new Author("William","Goldman","1931-08-12");
		
		inStock[0].setBook("Harry Potter and the Philosopher’s Stone",JK_Rollings,"978-1338299144",487);
		inStock[1].setBook("Harry Potter and the Chamber of Secrets",JK_Rollings,"978-0439064873",659);
		inStock[2].setBook("Harry Potter And The Prisoner Of Azkaban",JK_Rollings,"978-0439136365",576);
		inStock[3].setBook("Harry Potter And The Goblet Of Fire",JK_Rollings,"978-0439139601",799);
		inStock[4].setBook("Harry Potter And The Order Of The Phoenix",JK_Rollings,"978-0439358071",779);
		inStock[5].setBook("Harry Potter and the Half-Blood Prince",JK_Rollings,"978-0439785969",779);
		inStock[6].setBook("Harry Potter and the Deathly Hallows",JK_Rollings,"978-1338299205",627);
		inStock[7].setBook("Jurassic Park: A Novel ",Michael_Crinton,"978-0375401077",1334);
		inStock[8].setBook("The Lost World: A Novel",Michael_Crinton,"978-0345538994",515);
		inStock[9].setBook("The Princess Bride",William_Goldman,"978-0156035217",1399);
		inStock[10].setBook("The Princess Bride",William_Goldman,"978-0156035217",2499);
	}

	static void printLibrary(Book[] inStock)
	{
		int count = 1;
		for(Book i : inStock)
		{
			System.out.printf("%4d - %s\n",count,i);
			count++;
		}
	
	}
	
	
	public static void main(String[] args) 
	{
		
		Book[] inStock = new Book[11];
		
		for( int i = 0 ; i < inStock.length ; i++)
		{
			inStock[i] = new Book();
		}
		
		fillLibraty(inStock);
		
		System.out.println("Welcome to Diego's bookstore. My selection is limited, this is what I can offer:\n");
		
		printLibrary(inStock);
		
		System.out.println("\nYou may be wondering about books 10 and 11, are they the same?: " + inStock[9].compareBook(inStock[10]));
		System.out.println("The more expensive book as a shorter lead time.\n");
		
		
		System.out.println("\nYou may also have questions about books 8 and 9, are they the same?: " + inStock[7].compareBook(inStock[8]));
		System.out.println("They are part one and two for the same book series, but often confused.\n");
		
		
		
	}

}
