#include <iostream>
#include "Fraction.h"

int main()
{
    Fraction<unsigned char> F1, F2, F3;
    

    while (1)
    {
        cout << "Enter the first Fraction " << endl;
        F1.get_Data();
        cout << "Enter the second Fraction " << endl;
        F2.get_Data();

        cout << "Basic calculations for F1 and F2 " << endl;
        F3 = F1 + F2;
        F3.simplify();
        cout << "F1 + F2 = " << +F3.print_Numerator() << "/" << +F3.print_Denominator() << endl;
        F3 = F1 - F2;
        F3.simplify();
        cout << "F1 - F2 = " << +F3.print_Numerator() << "/" << +F3.print_Denominator() << endl;
        F3 = F1 * F2;
        F3.simplify();
        cout << "F1 * F2 = " << +F3.print_Numerator() << "/" << +F3.print_Denominator() << endl;
        F3 = F1 / F2;
        F3.simplify();
        cout << "F1 / F2 = " << +F3.print_Numerator() << "/" << +F3.print_Denominator() << endl;

    }
}
