#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string input;
    std::getline(std::cin, input);  // Read a line of input from standard input

    std::string strings;  // Used to store a group of strings
    int inputSize = static_cast<int>(input.size());  // Convert size_t to int once
    int i = 0;  // Use int for indexing

    while (i < inputSize) {
        // Extract the letters for a group of strings
        strings.clear();
        while (i < inputSize && isalpha(input[i])) {
            strings.push_back(input[i]);
            i++;
        }

        // Extract the sign (+ or -)
        char sign = input[i++];
        
        // Extract the number (the extent of adjustment)
        std::string number;
        while (i < inputSize && isdigit(input[i])) {
            number.push_back(input[i]);
            i++;
        }

        // Output the tuning instruction
        std::cout << strings << " ";
        if (sign == '+') {
            std::cout << "tighten ";
        } else if (sign == '-') {
            std::cout << "loosen ";
        }
        std::cout << number << std::endl;
    }

    return 0;
}
