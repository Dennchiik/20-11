#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int countWordOccurrences(const std::string& filename, const std::string& word) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file!" << std::endl;
        return -1;
    }

    std::string line;
    int count = 0;

    while (file >> line) {
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (line == word) {
            count++;
        }
    }

    file.close();
    return count;
}

int main() {
    std::string filename = "text.txt"; 
    std::string wordToFind;

    std::cout << "Enter the word to find in the file (only lowercase letters): ";
    std::cin >> wordToFind;

    int occurrences = countWordOccurrences(filename, wordToFind);
    if (occurrences != -1) {
        std::cout << "The word '" << wordToFind << "' appears " << occurrences << " times in the file." << std::endl;
    }

    return 0;
}
