#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <map> // Include this header for std::map

using namespace std;

int main() {
    int rows, columns;
    cin >> rows >> columns;
    vector<vector<char>> patch(rows, vector<char>(columns));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> patch[i][j];
        }
    }

    int posx, posy;
    cin >> posx >> posy;
    set<pair<int, int>> visited;
    int total_value = 0;

    map<char, int> value_dict = {{'S', 1}, {'M', 5}, {'L', 10}};

    // Implementing DFS using a stack
    stack<pair<int, int>> stk;
    stk.push({posx, posy});

    while (!stk.empty()) {
        auto [x, y] = stk.top();
        stk.pop();

        if (visited.find({x, y}) != visited.end() || patch[x][y] == '*') {
            continue;
        }
        visited.insert({x, y});

        // Directions: up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto& dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;
            if (nx >= 0 && nx < rows && ny >= 0 && ny < columns) {
                stk.push({nx, ny});
            }
        }
    }

    // Calculating total value based on visited cells
    for (auto p : visited) {
        if (value_dict.find(patch[p.first][p.second]) != value_dict.end()) {
            total_value += value_dict[patch[p.first][p.second]];
        }
    }

    cout << total_value << endl;

    return 0;
}
