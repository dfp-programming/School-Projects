package registration;

public class Student extends Person 
{
//	Student class should have:
//		• Major and gpa.
//		• Constructor which sets all necessary data in Person and Student class.
//		• toString method that lists student name, age, email, major and gpa.
//		• Method to register for a course. The method should make sure that the course has not
//		reached max capacity and the student is not already in the course. Otherwise sysout a
//		message and reject the student. Message can be generic. It is optional to specify the
//		reason of rejection. (There is a method in the Course class that uses the same logic. Try
//		to not duplicate it.
	
	
	String major;
	double gpa;
	
	Student()
	{
		super();
		this.major = "No major declared";
		this.gpa = 0;
	}
	
	Student(String name, int age, String email, String major, double gpa)
	{
		super(name,age,email);
		this.major = major;
		this.gpa = gpa;
	}
	
	public String toString()
	{
		return String.format("%1$-" + 11 + "s","STUDENT") + 
					String.format("%1$-" + (this.major.length() + 11) + "s", "MAJOR: "+  this.major) +
						String.format("%1$-" + 25 + "s", "GPA: "+  this.gpa) + "\n\t" + super.toString() + "\n";
	}
	
	public void registerCourse(Course desiredCourse)
	{
		desiredCourse.addStudent(this);
	}
	
	
}
