import sys

inp = sys.argv[1] if len(sys.argv) >= 2 else 'in'

G, D = open(inp).read().strip().split('\n\n')
G = G.split('\n')

R = len(G)
C = len(G[0])

G = [[G[r][c] for c in range(C)] for r in range(R)]

sr = sc = -1
for r in range(R):
    for c in range(C):
        if G[r][c] == '@':
            sr, sc = r, c
            G[r][c] = '.'

r, c = sr, sc
for d in D:
    if d == '\n':
        continue
    dr, dc = {'^': (-1, 0), '>': (0, 1), 'v': (1, 0), '<': (0, -1)}[d]
    nr, nc = r+dr, c+dc
    if G[nr][nc] == '#':
        continue
    elif G[nr][nc] == '.':
        r, c = nr, nc
    elif G[nr][nc] == 'O':
        while G[nr][nc] == 'O':
            nr += dr
            nc += dc
        if G[nr][nc] == '#':
            continue
        else:
            while (nr, nc) != (r, c):
                G[nr][nc] = G[nr-dr][nc-dc]
                nr -= dr
                nc -= dc
            r += dr
            c += dc

ans = 0
for r in range(R):
    for c in range(C):
        if G[r][c] == 'O':
            ans += 100*r + c

print(ans)
