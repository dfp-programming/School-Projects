package zoo;

public class Cow extends Animal {

	//Cow will have an instance variable called:
	private int num_spots;
	
	Cow()
	{
		super();
		num_spots=0;
		
	}
	
	Cow(String name, double weight, int age, int num_spots)
	{
		super(name,weight,age);
		this.num_spots = num_spots;
	}
	
	public String makeNoise()
	{
			return "Moooo";
	}
	
	public String toString()
	{
		String myClass = this.getClass().getName();
		myClass = myClass.substring(myClass.indexOf('.') + 1);
		return String.format("%1$-" + 15 + "s", "I am a " + myClass + ",") + super.toString() + 
					String.format("%1$-" + 26 + "s", "I have " + num_spots + " spots");
		
	}
}
