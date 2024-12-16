inp = open('in').read().strip()

machines = inp.split('\n\n')


def solveTokens(ax, ay, bx, by, px, py):
    ans = 0
    DP = {}

    def f(x, y):
        if (x, y) in DP:
            return DP[(x, y)]
        if x == 0 and y == 0:
            return 0
        if x < 0 or y < 0:
            return 10**30

        ans = min((3 + f(x-ax, y-ay)), (1+f(x-bx, y-by)))
        DP[(x, y)] = ans
        return ans

    ans = f(px, py)

    if ans < 500:
        return ans
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
