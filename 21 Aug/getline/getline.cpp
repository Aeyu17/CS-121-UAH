#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    string sentence;
    cout << "Enter a sentence.\n";

    getline(cin, sentence);

    cout << "You entered: " << sentence;

    return 0;
}