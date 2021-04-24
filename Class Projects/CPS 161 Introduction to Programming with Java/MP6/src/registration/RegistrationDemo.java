package registration;

public class RegistrationDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//construct some students:
		Student jane = new Student("Jane",20,"jane@wccnet.edu","Computer Science",3.45);
		Student kurtis = new Student("Kurtis",36,"kurtis@wccnet.edu","Math",3.60);
		Student teddy = new Student("Teddy",25,"Teddy@wccnet.edu","Computer Science",3.20);
		Student mike = new Student("Mike",22,"Mike@wccnet.edu","Biology",3.58);
		Student sally = new Student("Sally",40,"Sally@wccnet.edu","Computer Science",3.80);
		Student nicole = new Student("Nicole",18,"kurtis@wccnet.edu","Physics",3.20);
		
		//construct course:
		Course introJava = new Course("CSIT","Intro Java",5);
		System.out.println("------display course and roster:-----");
		
		System.out.println(introJava);
		introJava.displayRoster();
		
		//construct faculty:
		Faculty jing = new Faculty("Jing",40,"jswanson@wccnet.edu","CSIT","BE231");
		Faculty jim = new Faculty("Jim",35,"jim@wccnet.edu","MATH","GM200");
		
		
		System.out.println("\n\n------assign instructor to the course:-----");
		
		introJava.assignInstructor(jim);
		introJava.assignInstructor(jing);
		
		System.out.println("\n\n------display course again:-----");
		System.out.println(introJava);
		
		
		System.out.println("\n\n------adding some students to the course:-----");
	
		introJava.addStudent(jane);
		introJava.addStudent(kurtis);
		introJava.addStudent(kurtis);
		teddy.registerCourse(introJava);
		introJava.addStudent(teddy);
		System.out.println("\n\n------display course again:-----");
		System.out.println(introJava);
		System.out.println("\n\n------display roster:-----");
		introJava.displayRoster();
		
		System.out.println("\n\n------adding more students to the course:-----");
		mike.registerCourse(introJava);
		sally.registerCourse(introJava);
		nicole.registerCourse(introJava);
		
		System.out.println("\n\n------display roster:-----");
		introJava.displayRoster();
		
	}

}
