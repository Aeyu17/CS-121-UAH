#include <iostream>
#include <iomanip>

int main() {
    unsigned int entry, page, column, line, temp;
    // 60 lines per column, 3 columns per page

    std::cout << std::setprecision(0);
    std::cout << "Which entry do you want?\n";
    std::cin >> entry;

    line = entry % 60;
    temp = entry / 60;
    column = temp % 3 + 1;
    temp = temp / 3;
    page = temp + 1;

    std::cout << "Answer: Page " << page << ", Column " << column << ", Line " << line << '\n';

    return 0;
}