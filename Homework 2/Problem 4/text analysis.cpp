#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    unsigned int char_counts[26] = {0};
    unsigned int wordlen_counts[10] = {0};
    unsigned int wordlen = 0, ascii;
    const unsigned int width = 15;
    char currentChar;
    string word;
    ifstream file;

    file.open("/Users/jamie/Documents/GitHub/CS-121-UAH/Homework 2/Problem 4/UAH_Sample.txt");

    while (file >> word){
        wordlen = word.length();
        for (int i = 0; i < word.length(); i++){
            if (!isalpha(word[i]) && word[i] != '\'' && word[i] != '-'){
                wordlen--;
            }
        }
        if (wordlen > 0) {
            wordlen_counts[wordlen - 1]++;
        }  
        
    }

    file.close();
    // reset file
    file.open("/Users/jamie/Documents/GitHub/CS-121-UAH/Homework 2/Problem 4/UAH_Sample.txt");
    // reinit the counter
    for (int i = 0; i < 26; i++) {
        char_counts[i] = 0;
    }

    while (file.get(currentChar)) {
        // counting letters
        if (isalpha(currentChar)) {
            // convert char to ascii to index
            ascii = tolower(currentChar);
            char_counts[ascii - 97]++;
        }
    }
    file.close();

    cout << left << fixed;

    cout << setw(width) << "Word Length" << setw(width) << "Count" << endl;
        for (int i = 0; i < 10; i++) {
        cout << setw(width) << i + 1 << setw(width) << wordlen_counts[i] << endl;
    }
    cout << endl;
    
    cout << setw(width) << "Letter" << setw(width) << "Count" << endl;
    for (int i = 0; i < 26; i++) {
        cout << setw(width) << (char)(i + 97) << setw(width) << char_counts[i] << endl;
    }
    cout << endl;

    
    return 0;
}