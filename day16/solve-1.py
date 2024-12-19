import sys
import heapq

inp = sys.argv[1] if len(sys.argv) >= 2 else 'in'

D = open(inp).read().strip().split()

R = len(D)
C = len(D[0])
G = [[D[r][c] for c in range(C)] for r in range(R)]

sr, sc = -1, -1
er, ec = -1, -1
for r in range(R):
    for c in range(C):
        if G[r][c] == 'S':
            sr, sc = r, c
            G[r][c] = '.'
        if G[r][c] == 'E':
            er, ec = r, c
            G[r][c] = '.'

dir = [(-1, 0), (0, 1), (1, 0), (0, -1)]
dist = 0
Q = [(sr, sc, 1, 0)]
vis = {}
ans = 2**30

while Q:
    r, c, d, dist = heapq.heappop(Q)
    if (r, c, d) in vis and vis[(r, c, d)] <= dist:
        continue
    vis[(r, c, d)] = dist
    if (r, c) == (er, ec):
        ans = min(ans, dist)
        continue
    dr, dc = dir[d]
    nr, nc = r + dr, c + dc
    if G[nr][nc] != '#':
        heapq.heappush(Q, (nr, nc, d, dist+1))
    heapq.heappush(Q, (dist+1000, r, c, (d+1) % 4))
    heapq.heappush(Q, (dist+1000, r, c, (d-1) % 4))

print(ans)
