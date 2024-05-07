rows = int(input())
cols = int(input())
num_lines = int(input())

row_swipes = [0] * (rows + 1)
col_swipes = [0] * (cols + 1)

for _ in range(num_lines):
    direction, index = input().split()
    index = int(index)
    if direction == "R":
        row_swipes[index] += 1
    elif direction == "C":
        col_swipes[index] += 1

gold_count = 0
for i in range(1, rows + 1):
    for j in range(1, cols + 1):
        if (row_swipes[i] + col_swipes[j]) % 2 == 1:
            gold_count += 1

print(gold_count)
