grid = []
with open('in', 'r') as inp:
    grid = [i.strip() for i in inp.read().splitlines()]

R = len(grid)
C = len(grid[0])
vis = set()
connected = []


def in_grid(i, j):
    return (0 <= i < R) and (0 <= j < C)


dir = [[1, 0], [0, 1], [-1, 0], [0, -1]]
for i in range(R):
    for j in range(C):
        if (i, j) in vis:
            continue
        stack = [(i, j)]
        connected.append([grid[i][j], []])
        while len(stack) > 0:
            r, c = stack.pop()
            if (r, c) in vis:
                continue
            if not in_grid(r, c):
                continue
            elif grid[r][c] != grid[i][j]:
                continue
            vis.add((r, c))
            connected[-1][1].append((r, c))

            for xd, yd in dir:
                ni, nj = r + xd, c + yd
                stack.append((ni, nj))


def fence_length(a):
    perimeter = 0
    for i, j in a:
        for xd, yd in dir:
            ni, nj = i + xd, j + yd
            if not in_grid(ni, nj):
                perimeter += 1
            elif grid[i][j] != grid[ni][nj]:
                perimeter += 1
    return perimeter


ans = 0
for c, a in connected:
    ans += len(a)*fence_length(a)

print(ans)
