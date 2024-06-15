#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);
    
    int l1 = line1.length();
    int l2 = line2.length();
    int i = 0, j = 0;
    unordered_set<char> goodkeys;
    char silly = ' ';
    char wrong = ' ';
    char quiet = '-';
    
    while (i < l1 && j < l2) {
        if (line1[i] == wrong) {
            quiet = silly;
            silly = ' ';
            wrong = ' ';
            i++;
            continue;
        }
        if (line1[i] == quiet) {
            i++;
            continue;
        }
        if (line1[i] == line2[j]) {
            goodkeys.insert(line1[i]);
            i++;
            j++;
        } else if (goodkeys.find(line2[j]) == goodkeys.end()) {
            silly = line1[i];
            wrong = line2[j];
            i++;
            j++;
        } else {
            quiet = line1[i];
            i++;
        }
    }
    
    if (i < l1 && i == j) {
        quiet = line1[i];
    }
    
    // Output results
    cout << silly << " " << wrong << endl;
    cout << quiet << endl;

    return 0;
}
