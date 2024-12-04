with open('day4.input', 'r') as file:
    inp = file.read().strip().splitlines()

n = len(inp)
m = len(inp[0])

dir = []
for i in range(-1, 2):
    for j in range(-1, 2):
        if i != 0 or j != 0:
            dir.append((i, j))


def found_xmas(i, j, dir):
    x_dir, y_dir = dir
    for k, ch in enumerate('XMAS'):
        ni = i + k*x_dir
        nj = j + k*y_dir
        if not (0 <= ni < n and 0 <= nj < m):
            return False
        if inp[ni][nj] != ch:
            return False
    return True


ans = 0
for i in range(n):
    for j in range(m):
        for d in dir:
            ans += found_xmas(i, j, d)

print(ans)
