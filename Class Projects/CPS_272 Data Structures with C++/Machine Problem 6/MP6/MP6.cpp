/*

Hello!

This program overloaded several functions to make it easier to write different comple numbers operations.
the heavy lifting is being done by the Complex class.  There are quite a few functions, all with notes. 

the work flow is to ask the user to enter a string an specific format.  If he doesn't then a new prompt comes up
again.  After the user enters two numbers the program will automatically perform all four basic operations +-/*

The user aso has the option to quit by pressing inputting anything that starts with q or Q.  


I hope you like my program!

Diego F. Perez - CPS272 - 19NOV2020


*/





#include <iostream>
#include "Complex.hpp"

int main()
{    
    Complex c1, c2;
    string quit{ " " };

    
    while (quit[0] != 'q' && quit[0] != 'Q') // compare to the first char in case the user types quit or something.  
    {
        
        try {
            
            cout << "Enter the first complex number in format a+bi, or q to quit:\t";
            cin >> c1;

            cout << "Enter the second complex number in format c+di or q to quit:\t";
            cin >> c2;

            cout << endl;
            
            cout << " c1 + c2 = " << c1 + c2 << endl;

            cout << " c1 - c2 = " << c1 - c2 << endl;

            cout << " c1 * c2 = " << c1 * c2 << endl;

            cout << " c1 / c2 = " << c1 / c2 << endl;

            cout  << endl;
        }
        catch (exception e) {
            
            string msg = e.what();

            cout << "\tThere was a problem: " << msg << endl;
           
            if (msg == "Quit request") {

                cout << "Are you sure? - press q to quit: ";
                getline(cin, quit);
              
            }
            
            cout << endl;
            continue;
        }

    }
    



}
