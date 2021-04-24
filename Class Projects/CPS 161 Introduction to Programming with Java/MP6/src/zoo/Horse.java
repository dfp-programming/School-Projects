package zoo;

public class Horse extends Animal
{

		private double top_speed;
		
		Horse()
		{
			super();
			top_speed = 0;
		}
		
		Horse(String name, double weight, int age, double top_speed)
		{
			super(name,weight,age);
			this.top_speed = top_speed;
		}
		
		public String makeNoise()
		{
			return "Whinny";
		}
		
		public String toString()
		{
			String myClass = this.getClass().getName();
			myClass = myClass.substring(myClass.indexOf('.') + 1);
			return String.format("%1$-" + 15 + "s", "I am a " + myClass + ",") +  super.toString() +
						String.format("%1$-" + 26 + "s", "My top speed is " + top_speed + " mph");
		}

}
