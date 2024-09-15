#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <set>

using namespace std;

// 判断点是否共线的函数
bool are_points_collinear(const vector<pair<int, int>>& points) {
    // 如果点的数量小于3，它们自然在一条直线上
    if (static_cast<int>(points.size()) < 3) return true;

    // 获取前两个点的坐标
    int x0 = points[0].first, y0 = points[0].second;
    int x1 = points[1].first, y1 = points[1].second;
    int dx = x1 - x0;
    int dy = y1 - y0;

    // 计算其余点的斜率
    for (int i = 2; i < static_cast<int>(points.size()); i++) {
        int x = points[i].first, y = points[i].second;
        if (dx * (y - y0) != dy * (x - x0)) {
            return false;
        }
    }
    return true;
}

// 深度优先搜索栈实现
int dfs_stack(int start_x, int start_y, const vector<vector<string>>& grid, const vector<char>& word_list, int rows, int columns) {
    int result = 0;
    stack<vector<pair<int, int>>> s;
    s.push({{start_x, start_y}});

    while (!s.empty()) {
        vector<pair<int, int>> path = s.top();
        s.pop();
        int x = path.back().first;
        int y = path.back().second;

        if (path.size() == word_list.size()) {
            result++;
            continue;
        }

        char next_key = word_list[path.size()];

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, 1}, {1, 1}, {-1, -1}, {1, -1}};

        for (auto& dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;

            // 检查是否越界并且下一个字母是否匹配
            if (nx >= 0 && nx < rows && ny >= 0 && ny < columns && grid[nx][ny] == string(1, next_key)) {
                int step = abs(nx - x) + abs(ny - y);

                // 如果路径长度为1，直接推进栈
                if (path.size() == 1) {
                    s.push(path);
                    s.top().emplace_back(nx, ny);
                }

                // 如果路径长度大于1，进行更多检查
                if (path.size() > 1) {
                    int lx = path[path.size() - 2].first;
                    int ly = path[path.size() - 2].second;
                    int px = 2 * x - lx;
                    int py = 2 * y - ly;
                    int step01 = abs(path[0].first - path[1].first) + abs(path[0].second - path[1].second);

                    if (make_pair(px, py) == make_pair(nx, ny)) {
                        s.push(path);
                        s.top().emplace_back(nx, ny);
                    } else if (step01 == step && are_points_collinear(path)) {
                        s.push(path);
                        s.top().emplace_back(nx, ny);
                    }
                }
            }
        }
    }
    return result;
}

int main() {
    // 读取输入
    string input_word;
    cin >> input_word;

    vector<char> word_list(input_word.begin(), input_word.end());

    int rows, columns;
    cin >> rows >> columns;

    vector<vector<string>> grid(rows, vector<string>(columns));

    // 读取网格
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cin >> grid[i][j];
        }
    }

    // 查找与word_list第一个字符匹配的元素
    vector<pair<int, int>> leading_elements;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (grid[i][j] == string(1, word_list[0])) {
                leading_elements.emplace_back(i, j);
            }
        }
    }

    // 统计符合条件的路径
    int total = 0;
    for (auto& l : leading_elements) {
        total += dfs_stack(l.first, l.second, grid, word_list, rows, columns);
    }

    // 输出结果
    cout << total << endl;
    return 0;
}
