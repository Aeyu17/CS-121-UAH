#include <iostream>
#include <fstream>
#include <iomanip>
#include <string> 

using namespace std;

int main(){
    // init variables
    string title, author;
    float cost;
    char continue_flag;

    cout << fixed << left << setprecision(2) << setfill('.');

    while (true){
        cout << "Please enter the book title.\n";
        getline(cin, title);
        cout << "Please enter the author's last name and first initial.\n";
        getline(cin, author);
        cout << "Please enter the cost of the book.\n";
        cin >> cost;

        cout << setw(40) << title << setw(20) << author << "$" << cost << endl;

        cout << "Continue? (Y/N)\n";
        cin >> continue_flag;
        if (continue_flag == 'Y' || continue_flag == 'y'){
            getline(cin, title); // clear buffer
        } else {
            break;
        }
    }
    cout << "Exiting program...\n";
	return 0;
}