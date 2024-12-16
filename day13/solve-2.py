inp = open('in').read().strip()

machines = inp.split('\n\n')


def solveTokens(ax, ay, bx, by, px, py):
    px += 10000000000000
    py += 10000000000000

    ac = (px * by - bx * py) // (by * ax - bx * ay)
    bc = (py - ay * ac) // by

    if (ax * ac + bx * bc == px) and (ay * ac + by * bc == py):
        return 3*ac + bc
    elif ac < 0 or bc < 0:
        return 0
    else:
        return 0


ans = 0
for m in machines:
    a, b, prize = m.splitlines()
    aa = a.split()
    ax = int(aa[2].split('+')[1].split(',')[0])
    ay = int(aa[3].split('+')[1].split(',')[0])
    bb = b.split()
    bx = int(bb[2].split('+')[1].split(',')[0])
    by = int(bb[3].split('+')[1].split(',')[0])
    pp = prize.split()
    px = int(pp[1].split('=')[1].split(',')[0])
    py = int(pp[2].split('=')[1].split(',')[0])

    ans += solveTokens(ax, ay, bx, by, px, py)

print(ans)
