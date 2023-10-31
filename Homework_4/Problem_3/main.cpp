#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("/Users/jamie/Documents/GitHub/CS-121-UAH/Homework_4/Data/weather_station_five_column.txt");

    if (!file) {
        std::cout << "The file could not be opened.\n";
        return 1;
    }

    std::string data_line;
    getline(file, data_line);

    unsigned int tmax_col = data_line.find("TMAX");
    unsigned int tmin_col = data_line.find("TMIN");
    unsigned int station_col = data_line.find("STATION");

    if (tmax_col > data_line.length() || tmin_col > data_line.length() || station_col > data_line.length()) {
        std::cout << "One of the fields is invalid.\n";
        return 2;
    }

    getline(file, data_line); // get rid of dashes

    getline(file, data_line);
    float recorded_max = std::stof(data_line.substr(tmax_col, 5));
    float recorded_min = std::stof(data_line.substr(tmin_col, 5));
    std::vector<std::string> station_mins = {data_line.substr(station_col, 50)};
    std::vector<std::string> station_maxs = {data_line.substr(station_col, 50)};

    while (!file.eof()) {
        getline(file, data_line);
        float tmax = std::stof(data_line.substr(tmax_col, 5));
        float tmin = std::stof(data_line.substr(tmin_col, 5));
        std::string station = data_line.substr(station_col, 50);

        if (tmax > recorded_max) {
            recorded_max = tmax;

            station_maxs.clear();
            station_maxs.push_back(station);

        } else if (tmax == recorded_max) {
            station_maxs.push_back(station);
        }

        if (tmin < recorded_min) {
            recorded_min = tmin;

            station_mins.clear();
            station_mins.push_back(station);

        } else if (tmin == recorded_min) {
            station_mins.push_back(station);
        }
    }

    std::cout << std::fixed << std::left << std::setprecision(2);
    std::cout << "The maximum temperature recorded is " << recorded_max << '\n';
    std::cout << "The minimum temperature recorded is " << recorded_min << "\n\n";

    for (const auto & station_max : station_maxs) {
        std::cout << station_max << " Recorded a low of " << recorded_max << '\n';
    }

    for (const auto & station_min : station_mins) {
        std::cout << station_min << " Recorded a low of " << recorded_min << '\n';
    }

    return 0;
}
