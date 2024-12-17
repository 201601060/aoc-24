import re


lines = open('in').read().strip().split('\n')

W = 101
H = 103
wm = W//2
hm = H//2

sflist = []
pos = []
vel = []
npos = set()
for line in lines:
    ps, vs = line.split()

    p = [tuple(map(int, match))
         for match in re.findall(r"p=(-?\d+),(-?\d+)", ps)]
    v = [tuple(map(int, match))
         for match in re.findall(r"v=(-?\d+),(-?\d+)", vs)]

    pos.append((p[0][0], p[0][1]))
    vel.append((v[0][0], v[0][1]))


def printGrid():
    for i in range(H):
        for j in range(W):
            if (i, j) in npos:
                print('#', end='')
            else:
                print('.', end='')
        print()
    npos.clear()


def calcPos(n):
    for (p, v) in zip(pos, vel):
        x = (p[0] + n*v[0]) % W
        y = (p[1] + n*v[1]) % H
        npos.add((x, y))


def calcSafetyFactor(n):
    q0 = q1 = q2 = q3 = 0
    for (p, v) in zip(pos, vel):
        x = (p[0] + n*v[0]) % W
        y = (p[1] + n*v[1]) % H
        if x == wm or y == hm:
            continue
        if y < hm:
            if x > wm:
                q0 += 1
            else:
                q1 += 1
        else:
            if x > wm:
                q3 += 1
            else:
                q2 += 1
    s = q0*q1*q2*q3
    sflist.append((s, n))
    sflist.sort()


for i in range(10000):
    calcSafetyFactor(i)


print(sflist[0][1])
calcPos(sflist[0][1])
printGrid()
