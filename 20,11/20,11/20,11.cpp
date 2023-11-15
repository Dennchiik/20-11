#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("text.txt"); 
    if (!file.is_open()) {
        std::cerr << "Unable to open file!" << std::endl;
        return 1;
    }

    std::string line;
    int maxLength = 0;

    while (std::getline(file, line)) {
        int length = static_cast<int>(line.length());
        maxLength = (length > maxLength) ? length : maxLength;
    }

    file.close();

    if (maxLength > 0) {
        std::cout << "Length of the longest line in the file: " << maxLength << " characters." << std::endl;
    }
    else {
        std::cout << "The file is empty." << std::endl;
    }

    return 0;
}
