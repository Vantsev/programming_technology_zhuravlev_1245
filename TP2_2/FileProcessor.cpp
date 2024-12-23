#include "FileProcessor.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cctype>

bool startsWithVowel(const std::string& word) {
    char firstChar = std::tolower(word[0]);
    return firstChar == 'a' || firstChar == 'e' || firstChar == 'i' || firstChar == 'o' || firstChar == 'u' || firstChar == 'y';
}

void processFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Не удалось открыть файл.\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string word;
        while (ss >> word) {
            if (startsWithVowel(word)) {
                std::cout << word << std::endl;
            }
        }
    }

    file.close();
}
