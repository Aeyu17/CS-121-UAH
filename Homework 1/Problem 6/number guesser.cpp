#include <iostream>
#include <fstream>
#include <iomanip>
#include <string> 

using namespace std;

int main(){
    unsigned int answer = 57, guess;

    cout << "Enter a guess between 1 and 100.\n";
    while (true){
        cin >> guess;
        if (guess > answer){
            cout << "Guess is too high. Guess again.\n";
        } else if (guess < answer){
            cout << "Guess is too low. Guess again.\n";
        } else { // guess is correct
            cout << "Congratulations! You guessed the magic number.\n";
            break;
        }
    }
    return 0;
}