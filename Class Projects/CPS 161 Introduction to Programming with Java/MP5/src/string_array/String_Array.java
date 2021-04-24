package string_array;


public class String_Array {

	public static void main(String[] args) {
	
		String[] firstNames = new String[] {"George", "Fred", "Sam", "Mary", "Sarah", "Bella",
				"Joy", "Rita", "Marta", "Sue", "Nancy"};
		
		
		for( String name : firstNames)
		{
			 System.out.print(name + "\t");
		}
		
		 System.out.print("\n");
		 
		for( int i = firstNames.length -1 ; i >= 0 ; i--)
		{
			 System.out.print(firstNames[i] + "\t");
		}
		
	}

}
