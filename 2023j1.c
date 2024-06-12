#include <iostream>
using namespace std;

int main() {
    int P, C;
    cin >> P >> C;
    
    int score = 50 * P - 10 * C;
    
    if (P > C) {
        score += 500;
    }
    
    cout << score << endl;
    
    return 0;
}
