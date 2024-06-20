#include <iostream>
#include <vector>
#include <set>
#include <map>  // Include this header to use std::map

using namespace std;

int rows, columns;
vector<vector<char>> patch;
set<pair<int, int>> visited;
int total_value = 0;
map<char, int> value_dict = {{'S', 1}, {'M', 5}, {'L', 10}}; // Declare this as a global variable

void dfs_recursive(int x, int y) {
    if (x < 0 || x >= rows || y < 0 || y >= columns) return; // Check for out-of-bounds
    if (patch[x][y] == '*' || visited.find({x, y}) != visited.end()) return; // Check if visited or blocked

    visited.insert({x, y}); // Mark this cell as visited

    // Add value if it exists in the map
    if (value_dict.find(patch[x][y]) != value_dict.end()) {
        total_value += value_dict[patch[x][y]];
    }

    // Recurse for all adjacent cells
    dfs_recursive(x - 1, y); // up
    dfs_recursive(x + 1, y); // down
    dfs_recursive(x, y - 1); // left
    dfs_recursive(x, y + 1); // right
}

int main() {
    cin >> rows >> columns;
    patch.resize(rows, vector<char>(columns));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> patch[i][j];
        }
    }

    int posx, posy;
    cin >> posx >> posy;

    dfs_recursive(posx, posy); // Start DFS from the given position

    cout << total_value << endl; // Output the total value collected

    return 0;
}
