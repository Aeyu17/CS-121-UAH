#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    string sentence, num_str;
    float sum;
    bool num_flag; // tells us if we're reading a number now or not
    cout << "Type in a sentence to perform an addition operation.\n";

    getline(cin, sentence);

    for (int i = 0; i < sentence.length(); i++) {
        if (num_flag) {
            if (isdigit(sentence[i]) || (sentence[i] == '.' && (i != sentence.length() - 1))) {
                num_str += sentence[i];
            } else {
                sum += stof(num_str);
                num_str = "";
                num_flag = false;
            }
        } else if (isdigit(sentence[i])) {
            num_flag = true;
            num_str += sentence[i];
        }
    }

    cout << "The sum is " << sum;

    return 0;
}