with open('day4.input', 'r') as file:
    inp = file.read().strip().splitlines()

n = len(inp)
m = len(inp[0])
patts = ['MS', 'SM']


def found_xmas(i, j):
    if inp[i][j] != 'A':
        return False

    dg1 = f'{inp[i-1][j-1]}{inp[i+1][j+1]}'
    dg2 = f'{inp[i-1][j+1]}{inp[i+1][j-1]}'
    if dg1 in patts and dg2 in patts:
        return True

    return False


ans = 0
for i in range(1, n-1):
    for j in range(1, m-1):
        ans += found_xmas(i, j)

print(ans)
