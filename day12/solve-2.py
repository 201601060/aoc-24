from collections import deque

inp = open('in').read().strip()
grid = inp.split()
R = len(grid)
C = len(grid[0])


def in_grid(i, j):
    return (0 <= i < R) and (0 <= j < C)


ans = 0

dir = [[1, 0], [0, 1], [-1, 0], [0, -1]]
vis = set()

for i in range(R):
    for j in range(C):
        if (i, j) in vis:
            continue
        Q = deque([(i, j)])
        area = 0
        PERIM = dict()

        while Q:
            r, c = Q.popleft()
            if (r, c) in vis:
                continue
            vis.add((r, c))
            area += 1

            for xd, yd in dir:
                ni, nj = r + xd, c + yd
                if in_grid(ni, nj) and grid[ni][nj] == grid[r][c]:
                    Q.append((ni, nj))
                else:
                    if (xd, yd) not in PERIM:
                        PERIM[(xd, yd)] = set()
                    PERIM[(xd, yd)].add((r, c))

        sides = 0
        for d, boundary in PERIM.items():
            vis_perim = set()
            for (r, c) in boundary:
                if (r, c) not in vis_perim:
                    sides += 1
                    Q = deque([(r, c)])

                    while Q:
                        r2, c2 = Q.popleft()
                        if (r2, c2) in vis_perim:
                            continue
                        vis_perim.add((r2, c2))

                        for xd, yd in dir:
                            nr, nc = r2 + xd, c2 + yd
                            if (nr, nc) in boundary:
                                Q.append((nr, nc))

        ans += area*sides

print(ans)
