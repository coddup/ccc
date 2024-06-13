#include <iostream>

int main() {
    int R, S;
    std::cin >> R >> S; // Input for number of regular and small boxes

    // Constants for the number of cupcakes in each type of box
    const int regularCupcakes = 8;
    const int smallCupcakes = 3;

    // Calculate total number of cupcakes
    int totalCupcakes = R * regularCupcakes + S * smallCupcakes;

    // There are 28 students in the class
    int students = 28;
    
    // Calculate the number of leftover cupcakes
    int leftovers = totalCupcakes - students;

    // Output the number of leftover cupcakes
    std::cout << leftovers << std::endl;

    return 0;
}
