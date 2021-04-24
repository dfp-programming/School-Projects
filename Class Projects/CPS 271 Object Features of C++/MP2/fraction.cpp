#include "fraction.h"
//using namespace std;

	Fraction::Fraction() {

		numerator = 0;
		denominator = 1;
		
	}

	void Fraction::get_Data(get_Numbers_Safely my_Int) {
		
		cout << "Numerator:" << endl;
		numerator = my_Int.get_Number(0, 0, 'n', 'n','y');

		cout << "Denominator:" << endl;
		denominator = my_Int.get_Number(0, 0, 'n', 'y', 'n');
		cout << endl;

			   
		//if there are too many decimals the calculation tends to go bad. I limited the amount to 7 decimal places
		numerator = floor(numerator * 10000000) / 10000000;
		denominator = floor(denominator * 10000000) / 10000000;


	}

	double long Fraction::print_Numerator(){

		return numerator;
		
	}

	int long Fraction::print_Denominator() {

		return denominator;

	}


	Fraction_Math::Fraction_Math()
	{
		temp_Num = 0;
		temp_Den = 0;
		numerator_ = 0;
		rounded_Num_ = 0;
		denominator_ = 1;
		whole_number_ = 0;

	}

	void Fraction_Math::add(Fraction fraction1, Fraction fraction2){

		//To find the LCM, make i equal to any of the denomiators to start. Then keep increasing i until i%denominators == 0 
		//The LCM gets stored in denominator_
		for (int i = abs(fraction1.print_Denominator()); i < INT_MAX; i++) {

			if ((i % abs(fraction1.print_Denominator()) == 0)&&(i % abs(fraction2.print_Denominator()) == 0)) {
								
				denominator_ = i;
				break;
			}

		}

		numerator_ = (denominator_ / fraction1.print_Denominator()) * fraction1.print_Numerator() + (denominator_ / fraction2.print_Denominator()) * fraction2.print_Numerator();


		numerator_ = floor(numerator_ * 10000000) / 10000000;
		denominator_ = floor(denominator_ * 10000000) / 10000000;

	}

	void Fraction_Math::substract(Fraction fraction1, Fraction fraction2)
	{
		//To find the LCM, make i equal to any of the denomiators to start. Then keep increasing i until i%denominators == 0 for both denominators
		//The LCM gets stored in denominator_
		for (int i = abs(fraction1.print_Denominator()); i < INT_MAX; i++) {

			if ((i % abs(fraction1.print_Denominator()) == 0) && (i % abs(fraction2.print_Denominator()) == 0)) {

				denominator_ = i;
				break;
			}

		}

		numerator_ = (denominator_ / fraction1.print_Denominator()) * fraction1.print_Numerator() - (denominator_ / fraction2.print_Denominator()) * fraction2.print_Numerator();

		numerator_ = floor(numerator_ * 10000000) / 10000000;
		denominator_ = floor(denominator_ * 10000000) / 10000000;

	}

	void Fraction_Math::multiply(Fraction fraction1, Fraction fraction2)
	{
		numerator_ = fraction1.print_Numerator() * fraction2.print_Numerator();
		denominator_ = fraction1.print_Denominator()* fraction2.print_Denominator();
		numerator_ = floor(numerator_ * 10000000) / 10000000;
		denominator_ = floor(denominator_ * 10000000) / 10000000;
		
	}

	void Fraction_Math::divide(Fraction &fraction1, Fraction &fraction2)
	{

		// check if numerator of fraction two is decimal. Use abs in case it is negative. 
		rounded_Num_ = static_cast<int> (fraction2.print_Numerator());
		rounded_Num_ = abs(rounded_Num_);
	
		if (rounded_Num_ - abs(fraction2.print_Numerator()) != 0) {

			cout << "THIS OPERATION WOULD RESULT IN A DECIMAL DENOMINATOR, WHICH IS NOT ALLOWED.\n" << endl;
			rounded_Num_ = 0;
		}

		if (abs(fraction2.print_Numerator())==0) {
			cout << "THIS OPERATION WOULD RESULT IN A ZERO DENOMINATOR, WHICH IS NOT ALLOWED.\n" << endl;

		}
		
		if ((rounded_Num_ - abs(fraction2.print_Numerator()) == 0) && (abs(fraction2.print_Numerator()) != 0)) {

			numerator_ = fraction1.print_Numerator() * fraction2.print_Denominator();
			denominator_ = fraction1.print_Denominator() * fraction2.print_Numerator();
			rounded_Num_ = 0;
			numerator_ = floor(numerator_ * 10000000) / 10000000;
			denominator_ = floor(denominator_ * 10000000) / 10000000;
		}

	}


	int long Fraction_Math::simplify() {

		//Using ceil() or floor() is not good because if not a decimal, then the value goes up/down by 1. static_cast workes well to take out decimals. 
		rounded_Num_ = static_cast<int> (numerator_);
										
		//if the calculation didnt take place, denominator_, numerator_, and whole_Number should remain unchanged.
		//This can also happen if the numerator is zero. If this is the case, throw a message and exit the function.
		if ((denominator_ == 1)&&(numerator_==0)&&(whole_number_==0)) {
			cout << "THE RESULT IS ZERO, OR THE CALCULATION DIDN'T TAKE PLACE\n" << endl;
			return 0;
		}

		//if the denominator_ == 1, and the numerator_ is not a decimal, the result is the numerator.
		if ((denominator_ == 1) && !(abs(rounded_Num_) < abs(numerator_))) {
			cout << "THE RESULT IS =  " << numerator_ << "\n" << endl;
			return 0;
		}

		//If numerator_==denominator, then, the result is 1. 
		if (denominator_ == numerator_) {
			cout << "THE RESULT IS =  " << 1 << "\n" << endl;
			return 0;
		}
							 
		// if rounded_Num is less than numerator_, then numerator must be a decimal.  If so, conver the fraction to integers.
		if (abs(rounded_Num_) < abs(numerator_)) {

			//multiply both numerator and denominator by 10, then check if numerator is still decimal. If not longer decimal, then break
			do {

				numerator_ = numerator_ * 10;
				denominator_ = denominator_ * 10;
				rounded_Num_ = ceil(numerator_);
								
				//for certain decimal values, the calculation will be either very very close to 1 or 0.  When that happens the fraction should be all integers.
				//We can start to simplify the fraction when that happens.
				if ((rounded_Num_ - numerator_) <= 0.0000001|| (rounded_Num_ - numerator_) >= 0.99999999) {
					
					cout << fixed << setprecision(0) << "BEFORE SIMPLIFICATION, THE FRACTION IS =  " << numerator_ << "/" << denominator_ << "\n" << endl;
											
					temp_Den = abs(denominator_);
					temp_Num = abs(numerator_);
					
					for (int i = 2; i <= denominator_; i++) {

						if ((temp_Num % i == 0) && (temp_Den % i == 0)) {

							temp_Num /= i;
							temp_Den /= i;
														
												}

						//If i reaches the same value as the denominator, the simplyfication process is over.
						if (i >= temp_Den) {

							//Check if the numerator is bigger than the denominator, and if so give it as a mixed fraction
							if (temp_Num > temp_Den) {

								whole_number_ = (temp_Num / temp_Den);
								temp_Num -= (temp_Den * whole_number_);

								if (numerator_ < 0)
									temp_Num *= -1;
								if (denominator_ < 0)
									temp_Den *= -1;

								cout << fixed << setprecision(0) << "YOUR FRACTION IS =  " << whole_number_<< " " << temp_Num << "/" << temp_Den << "\n" << endl;

								//run the constructor to make sure all values of the Fraction_Math class get reset for the next calculation. 
								Fraction_Math::Fraction_Math();
								return 0;

							}

							if (numerator_ < 0)
								temp_Num *= -1;
							if (denominator_ < 0)
								temp_Den *= -1;

							cout << fixed << setprecision(0) << "YOUR FRACTION IS =  " << temp_Num << "/" << temp_Den << "\n" << endl;

							//run the constructor to make sure all values of the Fraction_Math class get reset for the next calculation. 
							Fraction_Math::Fraction_Math();
							return 0;
						}

					}

				}

			} while (1);
		}
		
		if (abs(numerator_) > abs(denominator_)) {

			cout << fixed << setprecision(0) << "BEFORE SIMPLIFICATION, THE FRACTION IS =  " << numerator_ << "/" << denominator_ << "\n" << endl;

			temp_Num = abs(numerator_);
			temp_Den = abs(denominator_);

			whole_number_ = temp_Num/ temp_Den;
			temp_Num -= (temp_Den * whole_number_);

			if (numerator_ < 0)
				temp_Num *= -1;
			if (denominator_ < 0)
				temp_Den *= -1;

			//cout << fixed << setprecision(15) << "rounded_Num  " << rounded_Num_ << "  ||  numerator_  " << numerator_ << "  ||  (rounded_Num - numerator_)" << (rounded_Num_ - numerator_) << endl;
			cout << fixed << setprecision(0) << "YOUR FRACTION IS =  " << whole_number_ << " " << temp_Num << "/" << temp_Den << "\n" << endl;

			//run the constructor to make sure all values of the Fraction_Math class get reset for the next calculation. 
			Fraction_Math::Fraction_Math();
			return 0;
		}
		
		cout << fixed << setprecision(0) << "YOUR FRACTION IS =  " << numerator_ << "/" << denominator_ << "\n" << endl;
		
		//run the constructor to make sure all values of the Fraction_Math class get reset for the next calculation. 
		Fraction_Math::Fraction_Math();
		return 0;

		
	}


	get_Numbers_Safely::get_Numbers_Safely() {
		
		alarm1 = "ERROR 01 - NOT A VALID CHOICE\n";
		alarm2 = "ERROR 02 - INVALID DATA\n";
		alarm3 = "ERROR 03 - DIVISION BY ZERO IS NOT ALLOWED\n";
		alarm4 = "ERROR 04 - DECIMAL NOT ALLOWED\n";

		number = 0.0;
		temp_Number = 0;

		
	}

	double long get_Numbers_Safely::get_Number(int low_Range, int high_range, char check_Range, char check_Zero, char allow_Decimal)
	{
		while (1) {

			try {

				cout << "\t\t";
				cin >> number;

				if (cin.fail())
					throw 2;   //invalid data

				temp_Number = static_cast<int> (number);

				if ((temp_Number - number != 0) && (allow_Decimal == 'n')) {
					throw 4; // decimals not allowed
				}
										
				if ((check_Range == 'y') && (number < low_Range || number > high_range)) 
					throw 1;	//not a valid choice
				
				if ((check_Zero == 'y') && (number == 0))
					throw 3;	//zero not allowed
				
				else {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					return number;
					return number;
				}
				
			}
			catch (int error) {

				if (error == 1) {
					cout << alarm1;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					continue;
				}

				if (error == 2) {
					cout << alarm2;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					continue;
				}

				if (error == 3) {
					cout << alarm3;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					continue;
				}

				if (error == 4) {
					cout << alarm4;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					continue;
				}
			}
		}

	}
