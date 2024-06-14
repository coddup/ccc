#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int points, fouls, starRating;
    bool isGoldTeam = true;
    int countOver40 = 0;

    for (int i = 0; i < N; i++) {
        std::cin >> points;
        std::cin >> fouls;

        starRating = points * 5 - fouls*3;
        if (starRating > 40) {
            countOver40++;
        }
        else {
            isGoldTeam = false;
        }
    }

    std::cout << countOver40;
    if (isGoldTeam) {
        std::cout << "+";
    }
    std::cout << std::endl;

    return 0;
}
