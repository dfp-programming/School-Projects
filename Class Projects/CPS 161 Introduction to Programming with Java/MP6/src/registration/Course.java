package registration;

public class Course
{
//	Course class should have:
//		• department, course name, max class size, current enrollment number, roster (an array
//		of students) and instructor.
//		• Constructor which takes 3 parameters for department, course name, and max class size.
//		• toString method that lists course name, department, max class size, current enrollment
//		number and instructor if one has been assigned.
//		• Method to display the class roster
	
	String department, courseName;
	int maxClassSize, currentEnrollment;
	Person roster[];
	Faculty instructor;
	
	Course()
	{
		this.department = "No department";
		this.courseName = "No course name";
		this.maxClassSize = 0;
		this.currentEnrollment = 0;
		this.instructor = null;
		roster = null;
	}
	
	Course(String department, String courseName, int size)
	{
		this.department = department;
		this.courseName = courseName;
		this.maxClassSize = size;
		this.currentEnrollment = 0;
		this.instructor = null;
		roster = new Person[maxClassSize];
	}
	
	void displayRoster()
	{
		System.out.println("CLASS ROSTER FOR: " + this.courseName + ".\n");
		
		for (int i = 0; i < roster.length; i++) 
		{
			if(roster[i] == null)
			{
					System.out.println((i + 1) + ". Empty Student Seat\n");
			}
			
			else
				System.out.println((i+1) + ". " + roster[i].toString());
		}
	}
	
	public void assignInstructor(Faculty instructor)
	{

			if(!this.department.contentEquals(instructor.department))
			{
				System.out.println(instructor.name + " does not belongs to the " + this.department + " department, and can't teach this course.\n");
					
			}
			else if(this.instructor == null)
			{
				this.instructor = instructor;
				System.out.println(instructor.name + " is now assigned to "+ this.courseName + ".");
			}

			else if(instructor.equals(this.instructor))
			{
				System.out.println(instructor.name + " is already an instructor in this course.");
			}
			else 
				System.out.println(instructor.name + " can't be an instructor for this course. There is already one assigned.\n");
	}
			
	
	
	public void addStudent(Student attendee)
	{
		//check if class is full
		if(maxClassSize == currentEnrollment)
		{
			System.out.println(attendee.name + " can't be registered, because the class is full.");
			return;
		}
			
		//Check if this attendee is already registered
		for(int i = 0; i < maxClassSize; i++) 
		{
			if(attendee.equals(roster[i]))
			{
				System.out.println(attendee.name + " is already attending this course.");
				return;
			}
		}
		
		if(roster[currentEnrollment] == null)
		{
			roster[currentEnrollment] = attendee;
			++currentEnrollment;
			System.out.println(attendee.name + " is now enrolled in "+ this.courseName + ".");
			return;
		}
	
	
			
	}
	
	public String toString()
	{
		String courseInstructor;
		
		if (this.instructor == null)
			courseInstructor = "Not Assigned\n";
		else
			courseInstructor = this.instructor.toString();
		
		return String.format("%1$-" + (department.length() + 16) + "s", "DEPARTMENT: " + department) +
				String.format("%1$-" + (courseName.length() + 17) + "s", "COURSE NAME: " +  courseName) +
					String.format("%1$-" + 17 + "s", "CLASS SIZE: " +  maxClassSize) + 
						String.format("%1$-" + 20 + "s", "STUDENTS ENROLLED: " +  currentEnrollment + "\n") + 
							String.format("%1$-" + (courseInstructor.length() + 16) + "s", "\tINSTRUCTOR: " +  courseInstructor);
	}

}
