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
Q = [(0, sr, sc, 1)]
vis = {}
seen = set()
min_dist = 2**30

while Q:
    dist, r, c, d = heapq.heappop(Q)
    if (r, c, d) not in vis:
        vis[(r, c, d)] = dist
    if (r, c, d) in seen:
        continue
    seen.add((r, c, d))
    if (r, c) == (er, ec):
        min_dist = min(min_dist, dist)
        continue
    dr, dc = dir[d]
    nr, nc = r + dr, c + dc
    if G[nr][nc] != '#':
        heapq.heappush(Q, (dist+1, nr, nc, d))
    heapq.heappush(Q, (dist+1000, r, c, (d+1) % 4))
    heapq.heappush(Q, (dist+1000, r, c, (d-1) % 4))

print(min_dist)

Q = []
for d in range(4):
    heapq.heappush(Q, (0, er, ec, d))

vis2 = {}
seen = set()
while Q:
    dist, r, c, d = heapq.heappop(Q)
    if (r, c, (d + 2) % 4) not in vis2:
        vis2[(r, c, (d + 2) % 4)] = dist
    if (r, c, d) in seen:
        continue
    seen.add((r, c, d))
    dr, dc = dir[d]
    nr, nc = r + dr, c + dc
    if G[nr][nc] != '#':
        heapq.heappush(Q, (dist+1, nr, nc, d))
    heapq.heappush(Q, (dist+1000, r, c, (d+1) % 4))
    heapq.heappush(Q, (dist+1000, r, c, (d-1) % 4))

in_path = set()
for r in range(R):
    for c in range(C):
        for d in range(4):
            if (r, c, d) in vis and (r, c, d) in vis2 and vis[(r, c, d)] + vis2[(r, c, d)] == min_dist:
                in_path.add((r, c))

print(len(in_path))
