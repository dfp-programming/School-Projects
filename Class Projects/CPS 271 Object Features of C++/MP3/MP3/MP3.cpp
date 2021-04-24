//Hello!
//
//This program will take two fractions and will do several types of operations using overloaded operators. The code was made with 
//safeguards against bad data, denominator zero, or if the result will end up with denominator zero.  After the calculation takes place, 
//The result will be simplified so the numbers are are small as possible. 
//
//I hope you like my program. 
//
//Made by Diego F. Perez - CPS 271 -D01

#include "fraction.h"

int main()
{
    Fraction* f_Ptr_Arr = new Fraction[2];
    Choice this_is_;
    int wayOut(1);

    while (1)
    {
        std::cout << "\n******** FIRST FRACTION ********" << std::endl;
        wayOut = f_Ptr_Arr[0].get_Data();
        if (wayOut == 0) break;

        std::cout << "\n******** SECOND FRACTION ********" << std::endl;
        wayOut = f_Ptr_Arr[1].get_Data();
        if (wayOut == 0) break;
       
        this_is_.myChoice(&f_Ptr_Arr[0], &f_Ptr_Arr[1]);
      
    }
   
    return 0;
}

