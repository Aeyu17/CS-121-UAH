#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    string first_name, last_name;
    char initial;
    unsigned int employee_num;
    float wage, hours;

    cout << "Employee Record Database\n\n";

    cout << "Enter the following information for each employee:\n";
    cout << "Last Name  First Name   Middle Initial  ID Number  Wage    Hours Worked\n\n";

    cin >> last_name >> first_name >> initial >> employee_num >> wage >> hours;

    cout << endl;
    cout << fixed << setprecision(2);
    cout << setfill('.'); // sets fill char to . (default is space)
    cout << left; // left justifies output

    cout << setw(20) << "Last Name:" << last_name << endl;
    cout << setw(20) << "First Name:" << first_name << endl;
    cout << setw(20) << "Middle Initial:" << initial << endl;
    cout << setw(20) << "Employee ID:" << employee_num << endl;
    cout << setw(20) << "Wage:" << "$" << wage << endl;
    cout << setw(20) << "Hours Worked:" << hours << endl;
    cout << setw(20) << "Pay:" << "$" << wage * hours << endl;


    return 0;
}