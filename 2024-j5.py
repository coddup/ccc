rows = int(input())
columns = int(input())
patch = []
for i in range(rows):
    patch.append(list(input()))
posx = int(input())
posy = int(input())
visited = set()
total_value = 0

value_dict = {'S': 1, 'M': 5, 'L': 10}

def dfs_stack(start_x, start_y):
    stack = [(start_x, start_y)]
    while stack:
        x, y = stack.pop()
        if (x, y) in visited or patch[x][y] == '*':
            continue
        visited.add((x, y))
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < rows and 0 <= ny < columns:
                stack.append((nx, ny))

dfs_stack(posx, posy)
for p in visited:
    if patch[p[0]][p[1]] in value_dict:
        total_value += value_dict[patch[p[0]][p[1]]]
print(total_value)
