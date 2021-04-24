package registration;

public class Person 
{
//	Person class should have:
//		• name, age, and email.
//		• Constructor which takes 3 parameters for name, age and email.
	
	String name, email;
	int age;
	
	Person()
	{
		this.name = "No name on file";
		this.email = "No email on file";
		this.age = 0;
	}
	
	Person(String name, int age, String email)
	{
		this.name = name;
		this.email = email;
		this.age = age;
	}
	
	public boolean equals(Object isItEqual)
	{
		if(isItEqual == null)
			return false;
		else if (this.getClass() != isItEqual.getClass())
			return false;
		else
		{
			Person myObj = (Person)isItEqual;
			return this.name.equalsIgnoreCase(myObj.name) && this.email.equalsIgnoreCase(myObj.email) && 
					this.age == myObj.age;
		}
	}
	
	public String toString()
	{
		return String.format("%1$-" +  (this.name.length() + 10) + "s", "NAME: "+  this.name) +
					String.format("%1$-" + (this.email.length() + 11) + "s", "EMAIL: "+  this.email ) +
						String.format("%1$-" + 10 + "s", "AGE: " +  this.age);
	}

}
