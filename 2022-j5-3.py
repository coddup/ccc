
N = int(input())
T = int(input())
trees = []
for i in range(T):
    a, b = map(int, input().split())
    trees.append((a - 1, b - 1))
trees.append((-1,-1))
trees.append((N, N))
trees.sort()
biggestSquare = 0
for i in range(len(trees)):
    horizontal = [-1, N]
    for j in range(i + 1, len(trees)):
        width = 0
        height = trees[j][0] - trees[i][0] - 1
        horizontal.sort()
        for k in range(1, len(horizontal)):
            width = max(width, horizontal[k] - horizontal[k - 1]-1)
        biggestSquare = max(biggestSquare, min(height, width))
        horizontal.append(trees[j][1])

print(biggestSquare)


