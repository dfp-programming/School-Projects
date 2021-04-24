package zoo;

public class Zoo
{
	private int actual_num_animals;
	private int num_cages;
	private Animal[] animals;
	
	//You will have the constructors:
	
	Zoo()
	{
		this.num_cages = 3;
		this.actual_num_animals = 0;
		animals = new Animal[num_cages];
	}
	
	Zoo(int num_cages)
	{
		this.num_cages = num_cages;
		this.actual_num_animals = 0;
		animals = new Animal[num_cages];
	}
	
	//You will have the following methods:
	
	void add(Animal a) 
	{
		//adds an animal to your Zoo
		if(actual_num_animals < num_cages)
		{
			animals[actual_num_animals] = a;
			++this.actual_num_animals;
		}
		else System.out.println("\nSorry, can't add more animals because the zoo is full! Due to concerns with the Covid-19 virus, we don't allow too many animals."
				+ "\nAnimal social distancing is our priority!.\n");
	}
	
	double total_weight()
	{
		// the total weight of all animals in the zoo
		double temp = 0.0;
		
		for (Animal animal : animals) 
		{
			if(animal!=null) 
			{
			temp += animal.getWeight();
			}
		}
		
		return temp;
	}
	
	void make_all_noises()
	{
		//Print out the noises made by all of the animals.
		for (Animal animal : animals)
		{
			if(animal!=null) 
			{
			String myClass = animal.getClass().getName();
			myClass = myClass.substring(myClass.lastIndexOf('.') + 1);
			System.out.println(myClass + " goes: " + animal.makeNoise());
			}
		}
		
	}

	
	void print_all_animals()
	{
		//prints the results of calling toString() on all 	animals in the zoo.
		for (Animal animal : animals)
		{
			if(animal!=null) 
			{
			System.out.println(animal.toString());
			}
		}
	}

	
	
	public static void main(String[] args)
	{
		Zoo z = new Zoo();
		Snake sly = new Snake("Sly", 5.0 , 2, 2);
		Snake sly2 = new Snake("Slyme", 10.0 , 1, 2);
		Cow blossy = new Cow("Blossy", 900., 5, 10);
		Horse prince = new Horse("Prince", 1000., 5, 23.2);
		
		// Following not allowed because Animal is abstract
		//Animal spot = new Animal("Spot", 10., 4);
		
		z.add(sly);
		z.add(sly2);
		z.add(blossy);
		z.add(prince);
		
		z.make_all_noises();
			
		System.out.println("Total weight = " + z.total_weight());
		System.out.println("**************************");
		System.out.println("Animal Printout:");
		
		z.print_all_animals();
		
		System.out.println("********* Now we will make the Second Zoo");
		
		Zoo z2 = new Zoo(5);
		z2.add(sly);
		z2.add(sly2);
		z2.add(blossy);
		z2.add(prince);
		z2.add( new Horse("Warrior", 1200, 6, 25.3));
		z2.add( new Horse("Harry", 1100, 4, 21.3));
		
		System.out.println("Total weight of z2 = "+z2.total_weight());
		
		z2.make_all_noises();
		z2.print_all_animals();
	}

}
