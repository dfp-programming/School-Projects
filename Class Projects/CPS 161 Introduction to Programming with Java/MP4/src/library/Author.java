package library;

import java.time.LocalDate;

public class Author {
	private String firstName, lastName;
	private LocalDate DOB;

	//constructors
	Author()
	{
		this.firstName = new String("Unknown");
		this.lastName = new String("Unknown");
		this.DOB = LocalDate.parse("1900-01-01");
	}
	
	Author(String firstName, String lastName, String DOB)
	{
		this.firstName = new String(firstName);
		this.lastName = new String(lastName);
	    this.DOB = LocalDate.parse(DOB);
	}
	
	Author(Author writer)
	{
		this.firstName = writer.rFirstName();
		this.lastName = writer.rLastName();
		this.DOB = writer.returnDOB();
	}
	
	//name and last name setters and getters
	public void setFirstName(String firstName)
	{
		this.firstName = firstName;
	}
	
	
	public String rFirstName()
	{
		return firstName;
	}
	
	public void setLastName(String lastName)
	{
		this.lastName = lastName;
	}
	
	public String rLastName()
	{
		return lastName;
	}
	
	public String returnFullName()
	{
		return rFirstName() + " " + rLastName();
	}
	
	//DOB setters and getters
	public void setDOB(LocalDate DOB)
	{
		this.DOB = DOB;
	}
	
	public void setDOB(String DOB)
	{
		this.DOB = LocalDate.parse(DOB);
	}
	
	
	public LocalDate returnDOB()
	{
           return this.DOB; 
	}
		
	
	
	//other methods
	public void setAuthor(String firstName, String lastName, String DOB)
	{
		this.setFirstName(firstName);
		this.setLastName(lastName);
		this.setDOB(DOB);		
	}
	
	public void setAuthor(Author writer)
	{
		this.setFirstName(writer.rFirstName());
		this.setLastName(writer.rLastName());
		this.setDOB(writer.returnDOB());		
	}
	
	public boolean compareAuthor(Author misteryPerson)
	{
		if (this.returnFullName().equals(misteryPerson.returnFullName()) && this.DOB.equals(misteryPerson.returnDOB()))
			return true;
		else
			return false;
	}
	
	public String toString() 
	{
		return this.rFirstName() + " " + this.rLastName() 
				+ " DOB: " + this.returnDOB();
	}
}
