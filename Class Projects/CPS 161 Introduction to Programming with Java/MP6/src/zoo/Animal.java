package zoo;



public abstract class Animal {
	
	private String name;
	private double weight;
	private int age;
	
	Animal()
	{
		name = "nameless";
		weight = 0;
		age = 0;
	}
	
	Animal(String n, double weight, int age)
	{
		this.name = n;
		this.weight = weight;
		this.age = age;
	}
	
	public abstract String makeNoise();
	{
		//this will be an abstract method
	}
	double getWeight()
	{
		//returns the weight of this animal
		return weight;
	}
	public String toString()
	{
		//returns a String with information about this Animal
		
		return String.format("%1$-" + 21 + "s", "My name is "+  this.name +",") + 
					String.format("%1$-" + 21 + "s", "I am " + age + " year(s) old,") + 
						String.format("%1$-" + 27 + "s", "My weight is " + weight + " lbs,");
		
	}

}
