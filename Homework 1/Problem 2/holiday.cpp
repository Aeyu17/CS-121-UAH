#include <iostream>
#include <fstream>
#include <iomanip>
#include <string> 

using namespace std;

int main(){
    unsigned int month, day;
    char slash;

    cout << "Please enter a day in the year. (MM/DD)\n";
    cin >> month >> slash >> day;

    if (month > 12 || month < 1 || day > 31 || day < 1){ // invalid inputs
        cout << "Invalid input. Exiting...\n";
        return 0;
    }

    if (month == 1 && day == 16){
        cout << "Dr. King's Birthday is on 01/16.\n";
    } else if (month == 2 && day == 14){
        cout << "Valentine's Day is on 02/14.\n";
    } else if (month == 3 && day == 17){
        cout << "St. Patrick's Day is on 03/17.\n";
    } else if (month == 4 && day == 9){
        cout << "Easter is on 04/09.\n";
    } else if (month == 5 && day == 29){
        cout << "Memorial Day is on 05/29.\n";
    } else if (month == 6 && day == 19){
        cout << "Juneteenth is on 06/19.\n";
    } else if (month == 7 && day == 4){
        cout << "Independence Day is on 07/04.\n";
    } else if (month == 9 && day == 4){
        cout << "Labor Day is on 09/04.\n";
    } else if (month == 10 && day == 31){
        cout << "Halloween is on 10/31.\n";
    } else if (month == 11 && day == 23){
        cout << "Thanksgiving is on 11/23.\n";
    } else if (month == 12 && day == 25){
        cout << "Christmas is on 12/25.\n";
    } else {
        cout << "There is no holiday on " << month << "/" << day << ".\n";
    }

    return 0;
}