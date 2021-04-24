package library;

public class Book {

	private Author bookAuthor;
	private String bookName, ISBN;
	private int price;	//in cents
	
	//constructors
	Book()
	{
		this.bookName= "Generic Book";
		this.bookAuthor = new Author();
		this.ISBN = "000-00-00000-00-0";
		this.price = 0;
	}
	
	Book(String bookName, Author writer, String ISBN, int price)
	{
		this.setBookName(bookName);
		this.setBookAuthor(writer);
		this.setISBN(ISBN);
		this.setPrice(price);
	}
	
	Book(String bookName, String firstName, String lastName, String DOB, String ISBN, int price)
	{
		this.setBookName(bookName);
		this.setBookAuthor(firstName,lastName,DOB);
		this.setISBN(ISBN);
		this.setPrice(price);
	}
	
	//book author setters and getters
	public void setBookAuthor(String firstName, String lastName, String DOB) 
	{
		this.bookAuthor.setAuthor(firstName, lastName, DOB);
	}
	
	public void setBookAuthor(Author writer) 
	{
		this.bookAuthor.setAuthor(writer);
	}
		
	public Author rBookAuthor() 
	{
		return this.bookAuthor;
	}
	
	//ISBN setters and getters
	public String returnISBN() 
	{
		return this.ISBN;
	}

	public void setISBN(String ISBN) 
	{
		this.ISBN = ISBN;
	}

	//book name setters and getters
	public String rBookName() {
		return this.bookName;
	}

	public void setBookName(String bookName) 
	{
		this.bookName = bookName;
	}

	//price setters and getters
	public int returnPrice() 
	{
		return this.price;
	}

	public void setPrice(int price)
	{
		this.price = price;
	}
	//set entire book
	
	public void setBook(String bookName, Author writer, String ISBN, int price) 
	{
		this.setBookName(bookName);
		this.setBookAuthor(writer);
		this.setPrice(price);
		this.setISBN(ISBN);
	}
	
	//other methods
	public boolean compareBook(Book misteryBook)
	{
		if (this.rBookName() == misteryBook.rBookName() && this.bookAuthor.compareAuthor(misteryBook.rBookAuthor()) == true
					&& this.returnISBN() == misteryBook.returnISBN())
				return true;
		else return false;
	}
	
	public String toString()
	{
		return this.rBookName() + " " + this.returnISBN() + " Price: $" + (float)this.returnPrice()/100 + "\n\t\t" + this.bookAuthor.toString() ;
	}
	
}
