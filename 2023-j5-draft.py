
word_list = list(input())
rows = int(input())
columns = int(input())
grid = []
for i in range(rows):
    grid.append(input().split(' '))
path_dict = {key: 0 for key in word_list}
findings = set()

def dfs_stack(start_x, start_y):
    result = 0
    stack = [((start_x, start_y), [[0, 0], (start_x, start_y)])]
    while stack:
        (x, y), path = stack.pop()
        if len(path) -1 >= len(word_list):
            result+=1
            continue
        next_key= word_list[len(path)-1]

        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1), (-1, 1), (1, 1), (-1, -1), (1, -1)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < rows and 0 <= ny < columns and grid[nx][ny] == next_key:
                step = abs(nx - x) + abs(ny - y)
                turning = path[0][1]
                if len(path) == 2:
                    stack.append(((nx, ny), [[step, 0]] + path[1:] + [(nx, ny)]))
                if len(path) > 2:
                    lx, ly = path[-2][0], path[-2][1]
                    px, py = 2 * x - lx, 2 * y - ly
                    if (px, py) == (nx, ny):
                        stack.append(((nx, ny), [(step, turning)] + path[1:] + [(nx, ny)]))
                    elif path[0][0] == step and path[0][1] == 0:
                        stack.append(((nx, ny), [(step, 1)] + path[1:] + [(nx, ny)]))
    return result


leading_elements = []
for i in range(rows):
    for j in range(columns):
        if grid[i][j] == word_list[0]:
            leading_elements.append((i, j))
total = 0
for l in leading_elements:
    total += dfs_stack(l[0], l[1])

print(total)

