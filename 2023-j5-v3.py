
word_list = list(input())
rows = int(input())
columns = int(input())
grid = []
for i in range(rows):
    grid.append(input().split(' '))
path_dict = {key: 0 for key in word_list}
findings = set()

def are_points_collinear(points):
    if len(points) < 3:  # 如果点的数量小于3，它们自然在一条直线上
        return True

    # 计算第一个点和第二个点的斜率
    (x0, y0), (x1, y1) = points[0], points[1]
    dx = x1 - x0
    dy = y1 - y0

    for i in range(2, len(points)):
        x, y = points[i]
        # 对于每个后续的点，计算与第一个点的斜率
        if dx * (y - y0) != dy * (x - x0):
            return False  # 如果斜率不相同，返回False

    return True  # 所有斜率相同，返回True

def dfs_stack(start_x, start_y):
    result = 0
    stack = [[(start_x, start_y)]]
    while stack:
        path = stack.pop()
        x, y = path[-1]
        if len(path)== len(word_list):
            result+=1
            continue
        next_key= word_list[len(path)]

        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1), (-1, 1), (1, 1), (-1, -1), (1, -1)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < rows and 0 <= ny < columns and grid[nx][ny] == next_key:
                step = abs(nx - x) + abs(ny - y)
                turning = path[0][1]
                if len(path) == 1:
                    stack.append( path+ [(nx, ny)])
                if len(path) > 1:
                    step01=abs(path[0][1] - path[1][1])+abs(path[0][0] - path[1][0])
                    lx, ly = path[-2][0], path[-2][1]
                    px, py = 2 * x - lx, 2 * y - ly
                    if (px, py) == (nx, ny):
                        stack.append(path+ [(nx, ny)])
                    elif step01 == step and are_points_collinear(path):
                        stack.append(path+ [(nx, ny)])
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

