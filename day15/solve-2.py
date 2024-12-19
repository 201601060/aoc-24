import sys
from collections import deque

inp = sys.argv[1] if len(sys.argv) >= 2 else 'in'

G, D = open(inp).read().strip().split('\n\n')
G = G.split('\n')

R = len(G)
C = len(G[0])
G = [[G[r][c] for c in range(C)] for r in range(R)]

RR = R
CC = 2*C
GG = []

sr = sc = -1
for r in range(R):
    row = []
    for c in range(C):
        if G[r][c] == '.':
            row.append('.')
            row.append('.')
        elif G[r][c] == '#':
            row.append('#')
            row.append('#')
        elif G[r][c] == '@':
            sr, sc = r, 2*c
            row.append('.')
            row.append('.')
        else:
            assert (G[r][c] == 'O')
            row.append('[')
            row.append(']')
    GG.append(row)

r, c = sr, sc
for d in D:
    if d == '\n':
        continue
    dr, dc = {'^': (-1, 0), '>': (0, 1), 'v': (1, 0), '<': (0, -1)}[d]
    nr, nc = r+dr, c+dc
    if GG[nr][nc] == '#':
        continue
    elif GG[nr][nc] == '.':
        r, c = nr, nc
    elif GG[nr][nc] in ['[', ']']:
        boxes = set()
        Q = deque([(r, c)])
        ok = True
        while Q:
            nr, nc = Q.popleft()
            if (nr, nc) in boxes:
                continue

            boxes.add((nr, nc))
            nr2, nc2 = nr+dr, nc+dc
            if GG[nr2][nc2] == '#':
                ok = False
                break
            elif GG[nr2][nc2] == ']':
                assert GG[nr2][nc2-1] == '['
                Q.append((nr2, nc2-1))
                Q.append((nr2, nc2))
            elif GG[nr2][nc2] == '[':
                assert GG[nr2][nc2+1] == ']'
                Q.append((nr2, nc2))
                Q.append((nr2, nc2+1))
        if not ok:
            continue
        while len(boxes):
            for nr, nc in sorted(boxes):
                nr2, nc2 = nr+dr, nc+dc
                if (nr2, nc2) not in boxes:
                    assert GG[nr2][nc2] == '.'
                    GG[nr2][nc2] = GG[nr][nc]
                    GG[nr][nc] = '.'
                    boxes.remove((nr, nc))
        r += dr
        c += dc

ans = 0
for r in range(RR):
    for c in range(CC):
        if GG[r][c] == '[':
            ans += 100*r + c

print(ans)
