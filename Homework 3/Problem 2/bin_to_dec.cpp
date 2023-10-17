#include <iostream>
#include <cmath>

int bin_to_dec(std::string binary);

int main() {
    std::string binary;
    int decimal;

    std::cout << "What binary number would you like to convert?\n";
    std::cin >> binary;

    decimal = bin_to_dec(binary);
    std::cout << "Decimal: " << decimal << '\n';

    return 0;
}

int bin_to_dec(std::string binary) {
    int result = 0;
    for (int i = 0; i < binary.length(); i++) {
        char bit = binary.at(i);

        if (int(bit) == 49) {
            result += std::pow(2, (binary.length() - i - 1));
        }

    }
    return result;
}