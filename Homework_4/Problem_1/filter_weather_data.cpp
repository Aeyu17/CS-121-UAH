#include <fstream>
#include <iostream>

int main() {
    std::ifstream raw_data("/Users/jamie/Documents/GitHub/CS-121-UAH/Homework_4/Data/AL_Weather_Station.txt");
    std::ofstream filtered_data("/Users/jamie/Documents/GitHub/CS-121-UAH/Homework_4/Data/Filtered_AL_Weather_Station.txt");
    std::ofstream five_col_data("/Users/jamie/Documents/GitHub/CS-121-UAH/Homework_4/Data/weather_station_five_column.txt");

    if (!raw_data) {
        std::cout << "Unable to open data file. Please try again.\n";
        return 1;
    }

    if (!filtered_data) {
        std::cout << "Unable to open filtered file. Please try again.\n";
        return 2;
    }

    if (!five_col_data) {
        std::cout << "Unable to open five column file. Please try again.\n";
        return 3;
    }

    std::string data_line;
    getline(raw_data, data_line); // get header
    filtered_data << data_line << '\n';
    five_col_data << std::fixed << std::left << std::setprecision(2);
    five_col_data << std::setw(51) << "STATION NAME" << std::setw(11) << "DATE" << std::setw(9) << "PRCP " <<
                     std::setw(9) << "TMAX" << std::setw(9) << "TMIN" << '\n';


    unsigned int prcp_col = data_line.find("PRCP");
    unsigned int tmax_col = data_line.find("TMAX");
    unsigned int tmin_col = data_line.find("TMIN");
    unsigned int date_col = data_line.find("DATE");
    unsigned int station_col = data_line.find("STATION_NAME");

    if (prcp_col > data_line.length() || tmax_col > data_line.length() || tmin_col > data_line.length()
        || date_col > data_line.length() || station_col > data_line.length()) {
        std::cout << "Could not find one of the columns. Please try again.\n";
        return 4;
    }

    getline(raw_data, data_line); // get rid of dashes
    filtered_data << data_line << '\n';
    five_col_data << std::setfill('-') << std::right;
    // formatted dashes
    five_col_data << std::setw(51) << ' ' << std::setw(11) << ' ' << std::setw(9) << ' ' << std::setw(9)
                  << ' ' << std::setw(9) << '\n';
    five_col_data << std::setfill(' ') << std::left << std::setprecision(2);

    float prcp, tmax, tmin;
    std::string date, station;
    unsigned int bad_records = 0;
    while (!raw_data.eof()) {
        getline(raw_data, data_line);

        prcp = stof(data_line.substr(prcp_col, 5));
        tmax = stof(data_line.substr(tmax_col, 5));
        tmin = stof(data_line.substr(tmin_col, 5));

        if (prcp == -9999 || tmax == -9999 || tmin == -9999) {
            bad_records++;
            continue;
        }

        filtered_data << data_line << '\n';

        date = data_line.substr(date_col, 8);
        // format date from YYYYMMDD to MMDDYYYY
        date = date.substr(4, 2) + ' ' + date.substr(6, 2) + ' ' + date.substr(0, 4);

        station = data_line.substr(station_col, 50);
        // remove white space out front
        for (int i = 0; i < station.length(); i++) {
            if (station.at(i) != ' ') {
                station = station.substr(i, station.length() - i);
                break;
            }
        }

        five_col_data << std::setw(50) << station << ' ' << std::setw(8) << date << ' ' << std::setw(8) << prcp
                << ' ' << std::setw(8) << tmax << ' ' << std::setw(8) << tmin << '\n';

    }

    filtered_data.close();
    raw_data.close();
    std::cout << "There were " << bad_records << " bad records detected.\n";

    return 0;
}