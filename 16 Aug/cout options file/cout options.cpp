//
// Program to illustrate cout options with a type double constant
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(void)
{
	double PI = 3.14159256;
    double bigNum = 34456.12356092;

	cout << "OUTPUT OPTIONS" << endl << endl;

	// Set scientific 
    cout << "Scientific Format" << endl;
    cout << scientific;
    cout << "Pi = " << PI << endl; // always have 6 decimal places
    cout << "Big Num = " << bigNum << endl << endl;
	
	// Set fixed
    cout << "Fixed" << endl;
    cout << fixed;
    cout << "Pi = " << PI << endl;
    cout << "Big Num = " << bigNum << endl << endl;
		

	// Set field width and precision

	cout << "PI in Fixed Format with width and precision set "<< endl;
	
	// 4 digits right of decimal
    cout << "4 decimal places" << endl;
    cout << setprecision(4);
    cout << "Pi = " << PI << endl;
    cout << "Big Num = " << bigNum << endl << endl;


	// 15 space output field
    cout << "15 space output field" << endl;
    cout << setw(15) << PI << endl;
    cout << setw(15) << bigNum << endl << endl;

	// Width of 6 with 2 digits right of decimal
    cout << "Width of 6, 2 decimal places" << endl;
    cout << setprecision(2);
    cout << setw(6) << PI << endl;
    cout << setw(6) << bigNum << endl << endl;

	// Width of 6 with 6 digits right of decimal. Output expands to cover the number.
    cout << "Width of 6, 6 decimal places" << endl;
    cout << setprecision(6);
	cout << setw(6) << PI << endl;
    cout << setw(6) << bigNum << endl << endl;	
	return 0;
}