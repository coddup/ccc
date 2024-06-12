#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    unordered_map<string, int> pepperSHU = {
        {"Poblano", 1500},
        {"Mirasol", 6000},
        {"Serrano", 15500},
        {"Cayenne", 40000},
        {"Thai", 75000},
        {"Habanero", 125000}
    };

    int totalSpiciness = 0;
    for (int i = 0; i < N; ++i) {
        string pepper;
        cin >> pepper;
        totalSpiciness += pepperSHU[pepper];
    }

    cout << totalSpiciness << endl;
    return 0;
}
