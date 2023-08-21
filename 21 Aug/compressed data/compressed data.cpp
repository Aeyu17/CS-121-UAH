#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	// Variables for packed data YYYY.MM.DDPLXDC
    unsigned int year;              // YYYY : Year
    unsigned int month;             // MM : Month
    unsigned int day;               // DD : Day
    char product_id;                // P : Product ID
    unsigned int factory_loc;       // L : Factory Location (integer)
    char quality_flag;              // X : Quality Flag
    char inspector;                 // D : Inspector
    char package_type;              // C : Package Type
	char dot;

    cout << fixed << setfill('.') << left;
    

	cout << "PRODUCT CODE" << endl << endl;
	cout << "Enter the product code as YYYY.MM.DDPLXDC" << endl;

	cin >> year >> dot >> month >> dot >> day >> product_id 
        >> factory_loc >> quality_flag >> inspector >> package_type;

    cout << setw(20) << "Year:" << year << endl;
    cout << setw(20) << "Month:" << month << endl;
    cout << setw(20) << "Day:" << day << endl;
    cout << setw(20) << "Product ID:" << product_id << endl;
    cout << setw(20) << "Factory Location:" << factory_loc << endl;
    cout << setw(20) << "Quality Flag:" << quality_flag << endl;
    cout << setw(20) << "Inspector:" << inspector << endl;
    cout << setw(20) << "Package Type:" << package_type << endl;


    cout << endl << endl;
	return 0;
}