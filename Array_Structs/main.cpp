#include <iostream>
#include <fstream>

struct date {
    unsigned int month;
    unsigned int day;
    unsigned int year;
};

struct reservation {
    std::string name;
    unsigned int size = 0;
    date day{};
    std::string time;
    std::string phone;
    std::string email;
    unsigned long credit_card = 0;
    date expiration{};
};

void print_reservation(reservation *reservation);

int main() {
    reservation reservations[10];
    std::string data_line;
    std::ifstream file("/Users/jamie/Documents/GitHub/CS-121-UAH/Array_Structs/dinner_reservations.txt");

    if (!file) {
        std::cout << "The file could not be opened.\n";
        return 1;
    }

    getline(file, data_line);

    unsigned int name_col = data_line.find("NAME");
    unsigned int size_col = data_line.find("SIZE");
    unsigned int day_col = data_line.find("DATE");
    unsigned int time_col = data_line.find("TIME");
    unsigned int phone_col = data_line.find("PHONE");
    unsigned int email_col = data_line.find("EMAIL");
    unsigned int credit_card_col = data_line.find("CREDIT CARD NO");
    unsigned int expiration_col = data_line.find("EXPIRE");

    if (name_col > data_line.length() || size_col > data_line.length() || day_col > data_line.length()
        || time_col > data_line.length() || phone_col > data_line.length() || email_col > data_line.length()
        || credit_card_col > data_line.length() || expiration_col > data_line.length()) {

        std::cout << "One of the fields could not be found. Please check the file.\n";
        return 2;
    }

    unsigned int iterator = 0;
    while (!file.eof()) {
        reservation *current_reservation = reservations+iterator;
        getline(file, data_line);

        current_reservation->name = data_line.substr(name_col, 10);
        current_reservation->size = std::stoi(data_line.substr(size_col, 1));

        date* reserve_date = &current_reservation->day;
        reserve_date->month = std::stoi(data_line.substr(day_col, 1));
        reserve_date->day = std::stoi(data_line.substr(day_col+2, 2));
        reserve_date->year = std::stoi(data_line.substr(day_col+5, 4));

        current_reservation->time = data_line.substr(time_col, 4);
        current_reservation->phone = data_line.substr(phone_col, 12);
        current_reservation->email = data_line.substr(email_col, 11);
        current_reservation->credit_card = std::stol(data_line.substr(credit_card_col, 12));

        date *expire_date = &current_reservation->expiration;
        expire_date->month = std::stoi(data_line.substr(expiration_col, 1));
        expire_date->day = std::stoi(data_line.substr(expiration_col+2, 2));
        expire_date->year = std::stoi(data_line.substr(expiration_col+5, 4));

        iterator++;
    }

    file.close();

    unsigned int month, day, year;
    std::cout << "Please give a date to find reservations on (MM DD YYYY).\n";
    std::cin >> month >> day >> year;

    for (auto & reservation : reservations) {
        if (reservation.day.month == month && reservation.day.day == day && reservation.day.year == year) {
            print_reservation(&reservation);
        }
    }

    return 0;
}

void print_reservation(reservation *current_reservation) {
    std::cout << std::left;
    std::cout << "Name: " << current_reservation->name << '\n';
    std::cout << "Size: " << current_reservation->size << '\n';
    std::cout << "Date: " << current_reservation->day.month << ' ' << current_reservation->day.day << ' ' << current_reservation->day.year << '\n';
    std::cout << "Time: " << current_reservation->time << '\n';
    std::cout << "Phone Number: " << current_reservation->phone << '\n';
    std::cout << "Email: " << current_reservation->email << '\n';
    std::cout << "Credit Card Number: " << current_reservation->credit_card << '\n';
    std::cout << "Expiration Date: " << current_reservation->expiration.month << ' ' << current_reservation->expiration.day << ' ' << current_reservation->expiration.year << '\n';
    std::cout << '\n';
}