package date_array;

public class Date_Array {

	
	public static void main(String[] args) {


		MyDate[] dateArr = { new MyDate("May",16,1984), new MyDate("November", 14, 1978),
												new MyDate("September", 21, 1980), new MyDate("July", 3, 1987)}; 
		
		for (MyDate someDate : dateArr)
		System.out.println(someDate.toString());
	
		System.out.println("---------------------------------------------");
		
		for (int i = dateArr.length -1; i >= 0 ; i--)
		{
			System.out.println(dateArr[i].toString());
		}

	}

}
