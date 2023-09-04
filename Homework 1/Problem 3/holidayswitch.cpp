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
        return 1;
    }

    switch (month) {
        case 1:
            if (day == 16){
                cout << "Dr. King's Birthday is on 01/16.\n";
                break;
            } 
        case 2:
            if (day == 14){
                cout << "Valentine's Day is on 02/14.\n";
                break;
            }
        case 3:
            if (day == 17){
                cout << "St. Patrick's Day is on 03/17.\n";
                break;
            }
        case 4:
            if (day == 9){
                cout << "Easter is on 04/09.\n";
                break;
            }
        case 5:
            if (day == 29){
                cout << "Memorial Day is on 05/29.\n";
                break;
            }
        case 6:
            if (day == 19){
                cout << "Juneteenth is on 06/19.\n";
                break;
            }
        case 7:
            if (day == 4){
                cout << "Independence Day is on 07/04.\n";
                break;
            }
        case 9:
            if (day == 4){
                cout << "Labor Day is on 09/04.\n";
                break;
            }
        case 10:
            if (day == 31){
                cout << "Halloween is on 10/31.\n";
                break;
            }
        case 11:
            if (day == 23){
                cout << "Thanksgiving is on 11/23.\n";
                break;
            }
        case 12:
            if (day == 25){
                cout << "Christmas is on 12/25.\n";
                break;
            }
        case 8:
        default:
            cout << "There is no holiday on " << month << "/" << day << ".\n";
            
    }

    return 0;
}