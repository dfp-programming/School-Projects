package zoo;

public class Snake extends Animal
{
		private int num_fangs;
		
		Snake()
		{
			super();
			this.num_fangs= 0;
		}
		
		Snake(String name, double weight, int age, int num_fangs)
		{
			super(name,weight,age);
			this.num_fangs = num_fangs;
		}
		
		
		public String makeNoise()
		{
			return "Hisssssss";
		}
		
		public String toString() 
		{
			String myClass = this.getClass().getName();
			myClass = myClass.substring(myClass.lastIndexOf('.') + 1);
			return String.format("%1$-" + 15 + "s", "I am a " + myClass + ",") + super.toString() +
					String.format("%1$-" + 22 + "s", "I have" + num_fangs + " fangs");
		}

}
