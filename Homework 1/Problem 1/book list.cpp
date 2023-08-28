#include <iostream>
#include <fstream>
#include <iomanip>
#include <string> 

using namespace std;

int main(){
	/*
    Write a program that will prompt the user to enter a list of book titles, authors and prices and then print out the information formatted as shown below:

    Title left justified in a 40 space field (You will need to read the title with getline not cin)
    Author last name and initial left justified in a 20 space field
    Dollar sign ($) printed next.
    Price left justified in a 7 space field with 2 digits of precision
    Fill the intermediate space between values with dots instead of spaces.
    You can pick the five books and the cost of each. 
        Examples:

        Flash Boys . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . Lewis M. . . . . . . . . . . . . $24.95

        Endless Forms Most Beautiful . . . . . . . . . . . . . .Carroll S. . . . . . . . . . . . . $17.95

    Show the output for at least 5 entries. You may run your program 5 times or use one of the loop constructs.
    */
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
        cout << setw(40) << title << setw(20) << author << "$" << setw(7) << cost << endl;
        cout << "Continue? (Y/N)\n";
        cin >> continue_flag;
        if (!(continue_flag == 'Y' || continue_flag == 'y')){
            break;
        } else {
            getline(cin, title); // clear buffer
        }
    }
    cout << "Exiting program...\n";
	return 0;
}