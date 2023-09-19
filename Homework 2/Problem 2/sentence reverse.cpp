#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string sentence, rsentence, temp;
    cout << "Type a sentence to be reversed.\n";

    getline(cin, sentence);

    for (int i = sentence.length() - 1; i >= 0; i--) {
        if (sentence[i] == ' ') {
            rsentence.append(temp + " ");
            temp = "";
        } else if (sentence[i] == '.') {
            continue;
        } else {
            // add to front
            temp = sentence[i] + temp;
        }
    }
    // add the rest to the end
    rsentence.append(temp);
    cout << rsentence;

    return 0;
}