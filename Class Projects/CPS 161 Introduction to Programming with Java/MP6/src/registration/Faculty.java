package registration;

public class Faculty extends Person
{
	//	Faculty class should have:
	//		• Department and office.
	//		• toString method that lists faculty name, age, email, department and office
	//		• Constructor which sets all necessary data in the Person and Faculty class.
	
	String department, office;
	
	Faculty()
	{
		super();
		this.department = "Not assigned";
		this.office = "Not assigned";
	}
	
	Faculty(String name, int age, String email, String department, String office)
	{
		super(name,age,email);
		this.department = department;
		this.office = office;
	}
	
	public String toString()
	{
		return String.format("%1$-" + 10 + "s", "FACULTY") + 
					String.format("%1$-" + (this.department.length() + 16) + "s", "DEPARTMENT: "+  this.department) +
						String.format("%1$-" + 25 + "s", "OFFICE: "+  this.office) + 
							"\n\t" + super.toString() +"\n" ;
	}
	
	

}
