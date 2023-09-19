#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string line;
    float temp;
    const int width = 15;

    ofstream table;
    ifstream temperature_file;
    temperature_file.open("./temps.txt");
    table.open("./table.txt");

    table << left << setprecision(2) << fixed;
    table << setw(width) << "Celsius" << setw(width) << "Fahrenheit" << setw(width) << "Kelvin" << endl;

    while (getline(temperature_file, line)) {

        if (line.back() == '\n'){
            // remove new lines
            line.pop_back();
        }
        temp = stof(line);
        
        table << setw(width) << temp << setw(width) << (9/5) * temp + 32 << setw(width) << temp + 273.15 << endl;
    }

    temperature_file.close();
    table.close();
    return 0;
}