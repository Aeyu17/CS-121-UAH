#include <iostream>
#include <fstream>

void trimString(std::string &str);

int main() {
    std::ifstream file("/Users/jamie/Documents/GitHub/CS-121-UAH/Homework_4/Data/weather_station_five_column.txt");

    if (!file) {
        std::cout << "The file could not be opened.\n";
        return 1;
    }

    std::string data_line;
    getline(file, data_line); // header

    unsigned int prcp_col = data_line.find("PRCP");
    unsigned int tmax_col = data_line.find("TMAX");
    unsigned int tmin_col = data_line.find("TMIN");
    unsigned int date_col = data_line.find("DATE");
    unsigned int station_col = data_line.find("STATION NAME");

    if (prcp_col > data_line.length() || tmax_col > data_line.length() || tmin_col > data_line.length()
        || date_col > data_line.length() || station_col > data_line.length()) {
        std::cout << "Could not find one of the columns. Please try again.\n";
        return 2;
    }

    std::string station;
    std::cout << "Please enter the full station name.\n";
    getline(std::cin, station);

    unsigned int date;
    std::cout << "Enter the day of the month.\n";
    std::cin >> date;

    if (date <= 0 || date > 31) {
        std::cout << "Invalid date entered.\n";
        return 3;
    }

    getline(file, data_line); // dashes

    float prcp = -9999, tmax = -9999, tmin = -9999;

    while (!file.eof()) {
        getline(file, data_line);
        std::string found_station = data_line.substr(station_col, 50);
        trimString(found_station);
        int found_date = stoi(data_line.substr(date_col+3, 2));


        if (found_station != station || found_date != date) {
            continue;
        }

        prcp = stof(data_line.substr(prcp_col, 5));
        tmax = stof(data_line.substr(tmax_col, 5));
        tmin = stof(data_line.substr(tmin_col, 5));

        break;
    }

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "The station " << station << " on " << date << " March 2018 recorded these results:\n\n";
    std::cout << "Precipitation: " << prcp << '\n';
    std::cout << "Maximum Temperature: " << tmax << '\n';
    std::cout << "Minimum Temperature: " << tmin << '\n';

    return 0;
}

void trimString(std::string &str) {
    for (int i = str.length() - 1; i >= 0; i--) {
        if (str[i] != ' ') {
            str = str.substr(0, i+1);
            break;
        }
    }
}