stones = []

with open('in', 'r') as inp:
    stones = inp.read().split()
    stones = [int(i) for i in stones]

for _ in range(25):
    temp = []
    for s in stones:
        if s == 0:
            temp.append(1)
            continue

        t = str(s)
        n = len(t)
        if n % 2 == 0:
            temp.append(int(t[:n//2]))
            temp.append(int(t[n//2:]))
        else:
            temp.append(s*2024)

    stones = temp

print(len(stones))
