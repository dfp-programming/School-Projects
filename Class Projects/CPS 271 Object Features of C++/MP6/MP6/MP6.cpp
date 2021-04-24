#include <iostream>
#include "myArray.h"
#include <string>

int main()
{
    int count(0);
    myArray<string> safeString(0,5);
    myArray<char> safeChar(-10,16);
    myArray<float> safeFloat(30, 45);
            
    //filling this array with random data
    for (int j=0, i = safeString.returnBegin(); i < safeString.returnEnd(); i++)
    {
        string fillerString("Filler String " + to_string(j));
        safeString.putValue( fillerString, i);
        ++j;
    }

    //filling this array with random data
    for (int j=0, i = safeChar.returnBegin(); i < safeChar.returnEnd(); i++)
    {
        safeChar.putValue(65+j, i);
        ++j;
    }
    
    //filling this array with random data
    for (int j = 0, i = safeFloat.returnBegin(); i < safeFloat.returnEnd(); i++)
    {
        safeFloat.putValue(5.5*j, i);
        ++j;
    }

    //Printing all three arrays
    cout << "myArray<string> safeString(5) ***************\n" << endl;
    safeString.printArray();
    
    cout << "\nmyArray<char> safeChar(-10,16) ***************\n" << endl;
    safeChar.printArray();
    
    cout << "\nmyArray<float> safeFloat(30, 45) ***************\n" << endl;
    safeFloat.printArray();

    //overwriting an out of bounds index
    cout << "\nOverwriting safeString(5) before and after bounds ***************\n" << endl;
    for (int i = -10; i < 10; i++)
    {
        cout << "overwriting index " << setw(3) << right << i << "\t";
        safeString.putValue("This string was overwriten with usesless text  " + to_string(i), i);
        cout << endl;
    }
    
    //Accessing an out of bounds index
    cout << "\nPrinting safeString(5) before and after bounds ***************\n" << endl;
    for (int i = -10; i < 10; i++)
    {
        cout << "Accesing index " << setw(3) << right << i << "\t";
        cout << safeString.returnValue(i) << endl;
    }
    
    return 0;
}
