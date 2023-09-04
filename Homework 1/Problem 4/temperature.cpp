#include <iostream>
#include <fstream>
#include <iomanip>
#include <string> 

using namespace std;

int main(){
    float start, end, inc, num;
    unsigned int width = 12;
    cout << fixed << right << setprecision(2);
    
    cout << "WHILE LOOP\n\n";

    cout << "Enter a starting temperature in degrees Celsius.\n";
    cin >> start;
    cout << "Enter an ending temperature in degrees Celsius.\n";
    cin >> end;
    cout << "Enter the increment between temperatures in degrees Celsius.\n";
    cin >> inc;

    cout << setw(width) << "Celsius" << setw(width) << "Fahrenheit" << setw(width) << "Kelvin" << endl;

    num = start;
    while (num <= end){
        cout << setw(width) << num << setw(width) << 9/5 * num + 32 << setw(width) << num + 273.15 << endl;
        num += inc;
    }


    cout << "DO WHILE LOOP\n\n";

    cout << "Enter a starting temperature in degrees Celsius.\n";
    cin >> start;
    cout << "Enter an ending temperature in degrees Celsius.\n";
    cin >> end;
    cout << "Enter the increment between temperatures in degrees Celsius.\n";
    cin >> inc;

    num = start;
    do {
        cout << setw(width) << num << setw(width) << 9/5 * num + 32 << setw(width) << num + 273.15 << endl;
        num += inc;
    }
    while (num <= end);


    cout << "FOR LOOP\n\n";

    cout << "Enter a starting temperature in degrees Celsius.\n";
    cin >> start;
    cout << "Enter an ending temperature in degrees Celsius.\n";
    cin >> end;
    cout << "Enter the increment between temperatures in degrees Celsius.\n";
    cin >> inc;

    for (num = start; num <= end; num += inc){
        cout << setw(width) << num << setw(width) << 9/5 * num + 32 << setw(width) << num + 273.15 << endl;
    }

    return 0;
}