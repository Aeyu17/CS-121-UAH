#include <iostream>
#include <fstream>

const unsigned int DICT_LENGTH = 4030;
std::string DICTIONARY[DICT_LENGTH] = {};

void init_dictionary(std::string dict[]);
int string_compare(std::string str1, std::string str2);
bool binary_search(std::string dict[], std::string key, int left, int right);

int main() {
    init_dictionary(DICTIONARY);

    std::string word;
    bool correctSpelling;

    std::cout << "Enter a word that is 4 letters long.\n";
    std::cin >> word;

    if (word.length() != 4) {
        std::cout << "Invalid word received.\n";
        return 1;
    }

    correctSpelling = binary_search(DICTIONARY, word, 0, DICT_LENGTH - 1);

    if (correctSpelling) {
        std::cout << word << " is spelled correctly.";
    } else {
        std::cout << word << " is not spelled correctly.";
    }

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