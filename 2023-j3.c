#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    int dayCount[5] = {0};  // 用来记录每一天能够参加活动的人数

    for (int i = 0; i < N; ++i) {
        string schedule;
        cin >> schedule;
        for (int j = 0; j < 5; ++j) {
            if (schedule[j] == 'Y') {
                dayCount[j]++;
            }
        }
    }

    int maxAvailability = 0;
    for (int i = 0; i < 5; ++i) {
        if (dayCount[i] > maxAvailability) {
            maxAvailability = dayCount[i];
        }
    }

    bool first = true;
    for (int i = 0; i < 5; ++i) {
        if (dayCount[i] == maxAvailability) {
            if (!first) {
                cout << ",";
            }
            cout << (i + 1);
            first = false;
        }
    }
    cout << endl;

    return 0;
}
