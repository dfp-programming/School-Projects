//Hello!
//
//This program will take two fractions and will either add, substract, miltiply, or divide them according to your input. The code was made with 
//safeguards against bad data, denominator zero, or if the result will end up with denominator zero.  After the calculation takes place, 
//The result will be simplified so the numbers are are small as possible, and give you a mixed fraction if the numerator is bigger than the denominator. 
//
//I hope you like my program. 
//
//Made by Diego F. Perez - CPS 271 -D01


#include "fraction.h"


int main()
{
    int choice{ 0 };

  Fraction my_Fraction_1, my_Fraction_2;
  Fraction_Math math_;
  get_Numbers_Safely myNumber;

      while (choice != 5) {

          cout << "******** FIRST FRACTION" << endl;

          my_Fraction_1.get_Data(myNumber);

          cout << "******** SECOND FRACTION" << endl;
   
          my_Fraction_2.get_Data(myNumber);

              cout << setw(31) << right << "WHAT WOULD YOU LIKE TO DO?\n" << endl;
              cout << setw(30) << left << "1 - Add.";
              cout << setw(30) << left << "2 - Substract." << endl;
              cout << setw(30) << left << "3 - Multiply.";
              cout << setw(30) << left << "4 - Divide." << endl;
              cout << setw(30) << left << "5 - Quit.\n" << endl;

              // get a number that is between 1 and 5 and can't be decimal. If you enter something else or bad data, you get an error.    
              choice = myNumber.get_Number(1, 5, 'y', 'y','n');
              
              if (choice == 1)
                  math_.add(my_Fraction_1, my_Fraction_2);
              if (choice == 2)
                  math_.substract(my_Fraction_1, my_Fraction_2);
              if (choice == 3)
                  math_.multiply(my_Fraction_1, my_Fraction_2);
              if (choice == 4)
                  math_.divide(my_Fraction_1, my_Fraction_2);
              if (choice == 5)
                  return 0;

     
              math_.simplify();
            
      }
  
  }

