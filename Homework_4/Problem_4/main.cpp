#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("/Users/jamie/Documents/GitHub/CS-121-UAH/Homework_4/Data/weather_station_five_column.txt");

    if (!file) {
        std::cout << "The file could not be opened.\n";
        return 1;
    }

    std::string data_line;
    getline(file, data_line); // header

    unsigned int prcp_col = data_line.find("PRCP");
    unsigned int date_col = data_line.find("DATE");

    if (prcp_col > data_line.length() || date_col > data_line.length()) {
        std::cout << "Could not find one of the columns. Please try again.\n";
        return 2;
    }

    unsigned int date;
    std::cout << "Enter the day of the month you want to find the precipitation from.\n";
    std::cin >> date;

    if (date <= 0 || date > 31) {
        std::cout << "Invalid date entered.\n";
        return 3;
    }

    getline(file, data_line); // dashes

    float sum = 0.0;
    while (!file.eof()) {
        getline(file, data_line);
        int found_date = stoi(data_line.substr(date_col+3, 2));

        if (found_date != date) {
            continue;
        }

        float prcp = stof(data_line.substr(prcp_col, 5));
        sum += prcp;
    }

    std::cout << "The total precipitation on " << date << " March 2018 was " << sum << ".\n";

    return 0;
}
