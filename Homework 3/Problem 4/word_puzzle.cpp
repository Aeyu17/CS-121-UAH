#include <iostream>
#include <fstream>

const unsigned int DICT_LENGTH = 4030;
std::string DICTIONARY[DICT_LENGTH] = {};

void init_dictionary(std::string dict[]);
bool binary_search(std::string dict[], std::string key, int left, int right);
int string_compare(std::string str1, std::string str2);
void init_puzzle(std::string puzzle[]);
void transpose_puzzle(std::string puzzle[], std::string trans_puzzle[]);
void reverse_puzzle(std::string puzzle[], std::string reverse_puzzle[]);
void get_words(std::string puzzle[]);

int main() {
    init_dictionary(DICTIONARY);

    std::string puzzle[10] = {""};
    std::string trans_puzzle[10] = {""};
    std::string reversed_puzzle[10] = {""};
    std::string reversed_trans_puzzle[10] = {""};

    init_puzzle(puzzle);
    transpose_puzzle(puzzle, trans_puzzle);
    reverse_puzzle(puzzle, reversed_puzzle);
    reverse_puzzle(trans_puzzle, reversed_trans_puzzle);

    std::cout << "Your puzzle is: \n";
    for (int i = 0; i < 10; i++) {
        std::cout << puzzle[i] << '\n';
    }
    std::cout << '\n';

    std::cout << "The words in your puzzle are: \n";

    get_words(puzzle);
    get_words(trans_puzzle);
    get_words(reversed_puzzle);
    get_words(reversed_trans_puzzle);

    return 0;
}

void init_dictionary(std::string dict[]) {
    std::ifstream file;
    file.open("/Users/jamie/Documents/GitHub/CS-121-UAH/Homework 3/Problem 3/dictionary_four_letter_words.txt");

    for (int i = 0; i < DICT_LENGTH; i++) {
        std::string word;
        file >> word;
        dict[i] = word;
    }

    file.close();
}

int string_compare(std::string str1, std::string str2) {
    // returns 1 if str1 > str2, 0 if str1 == str2, and -1 if str1 < str2
    // assumes str1 & str2 are the same length and are all lowercase
    for (int i = 0; i < str1.length(); i++) {
        if (str1.at(i) > str2.at(i)) {
            return 1;
        } else if (str1.at(i) < str2.at(i)) {
            return -1;
        }
    }
    return 0;
}

bool binary_search(std::string dict[], std::string key, int left, int right) {
    if (left > right) {
        return false;
    }

    int middle = left + (right - left)/2;
    int comp = string_compare(key, dict[middle]);

    if (comp == 0) {
        return true;
    } else if (comp == 1) { // key > dict[middle]
        return binary_search(dict, key, middle + 1, right);
    } else { // key < dict[middle]
        return binary_search(dict, key, left, middle - 1);
    }
}

void init_puzzle(std::string puzzle[]) {
    std::cout << "Input your puzzle.\n";
    std::string line;

    for (int i = 0; i < 10; i++) {
        std::cout << "Line " << i + 1 << ": ";
        std::cin >> line;
        puzzle[i] = line;
    }
}

void transpose_puzzle(std::string puzzle[], std::string trans_puzzle[]) {
    for (int i = 0; i < puzzle->length(); i++) {
        std::string word;
        for (int j = 0; j < puzzle->length(); j++) {
            word += puzzle[j][i];
        }
        trans_puzzle[i] = word;
    }
}

void reverse_puzzle(std::string puzzle[], std::string reverse_puzzle[]) {
    for (int i = 0; i < puzzle->length(); i++) {
        std::string word;
        for (int j = puzzle->length() - 1; j >= 0; j--) {
            word += puzzle[i][j];
        }
        reverse_puzzle[i] = word;
    }
}

void get_words(std::string puzzle[]) {
    for (int i = 0; i < puzzle->length(); i++) {
        for (int j = 0; j < puzzle->length() - 3; j++) {
            std::string word = puzzle[i].substr(j, 4);
            if (binary_search(DICTIONARY, word, 0, 4030)) { // found word
                std::cout << word << '\n';
            }
        }
    }
}