#include <iostream>

using namespace std;

int main(){
    int number = 7;			// Integer variable
    int age = 30;				// Integer variable
    float pressure =  45.7;		// Float variable
    float mass = 2.3489;		// Float variable
    string name = "John";		// String variable

    int *p_value = nullptr;		// Pointer to an integer
    int *p_data = nullptr;		// Pointer to another integer
    float *p_one = nullptr;		// Pointer to a float type
    float *p_two = nullptr;		// Pointer to a float type
    string *p_name = nullptr; 		// Pointer to a string type
    int j = 0, k = 0;			// For use in loops
    int array_one[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20}; // An array

    // Initialize the pointers. NOTE: * is not used here.

    p_data = &age;
    p_value = &number;
    p_one = &pressure;
    p_two = &mass;
    p_name = &name;

    cout << age << '\t' << number << '\t' << pressure << '\t' << mass << '\t' << name << '\n';
    cout << p_data << '\t' << p_value << '\t' << p_one << '\t' << p_two << '\t' << p_name << "\n\n";

    p_value = p_data;
    age = 17;
    number = 45;
    *p_two = *p_one;
    *p_one = 56.5;
    *p_name = "Jane";

    cout << age << '\t' << number << '\t' << pressure << '\t' << mass << '\t' << name << '\n';
    cout << p_data << '\t' << p_value << '\t' << p_one << '\t' << p_two << '\t' << p_name << "\n\n";

    *array_one = 3;
    array_one[2] = 5;
    *(array_one + 4) = 7;
    array_one[8] = *array_one + 1;
    p_data = array_one + 9;
    *p_data = 11;
    *(p_data - array_one[1]) = 13;
    p_data -= 3;
    *p_data = 17;
    p_data++;
    *p_data = array_one[array_one[2]];

    for (int i = 0; i < 10; i++) {
        cout << array_one[i] << '\t';
    }


    return 0;
}
