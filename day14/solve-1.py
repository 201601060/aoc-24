import re


lines = open('in').read().strip().split('\n')

W = 101
H = 103
wm = (W - 1)/2
hm = (H - 1)/2
q0 = q1 = q2 = q3 = 0
for line in lines:
    ps, vs = line.split()

    p = [tuple(map(int, match))
         for match in re.findall(r"p=(-?\d+),(-?\d+)", ps)]
    v = [tuple(map(int, match))
         for match in re.findall(r"v=(-?\d+),(-?\d+)", vs)]

    x = (p[0][0] + 100*v[0][0]) % W
    y = (p[0][1] + 100*v[0][1]) % H

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

print(q0 * q1 * q2 * q3)
