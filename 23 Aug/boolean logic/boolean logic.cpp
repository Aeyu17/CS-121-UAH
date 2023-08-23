#include <iostream> 
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main() {
	int num1, num2, num3;

	cout << "Enter three integer values: " << endl;
	cin >> num1 >> num2 >> num3;
	cout << "You entered: " <<  num1 << setw(3) << num2 << setw(3) << num3 << endl << endl;

    if (num1 > num2) {
        cout << num1 << " is greater than " << num2 << endl;
    }

	cout << "CASE I. Nested if statements " << endl;

    if (num1 > num2) {
        if (num1 > num3) {
            cout << num1;
        } else {
            cout << num3;
        }
    } else {
        if (num2 > num3) {
            cout << num2;
        } else {
            cout << num3;
        }
    }
    cout << " is the largest number.\n";

	cout << endl;

	cout << "CASE II. The and logical operator (&&)" << endl;

    // if (num1 >= num2 && num1 >= num3){

    // }
    // god i'm so fucking bored in this class i'm just gonna stop listening

	cout << endl;

	cout << "CASE III. The if - else if - else statement." << endl;

	cout << endl;

	cout << endl << endl;
	system("pause");
	return 0;
}