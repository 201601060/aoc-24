from collections import defaultdict

stones = []
count = defaultdict(int)

with open('in', 'r') as inp:
    stones = inp.read().split()
    stones = [int(i) for i in stones]

for i in stones:
    count[i] += 1


def updateCount(count: dict):
    temp = defaultdict(int)
    for i in count:
        if i == 0:
            temp[1] += count[0]
            continue
        t = str(i)
        n = len(t)
        if n % 2 == 0:
            temp[int(t[:n//2])] += count[i]
            temp[int(t[n//2:])] += count[i]
        else:
            temp[i*2024] += count[i]

    return temp


for _ in range(75):
    count = updateCount(count)

ans = 0
for c in count:
    ans += count[c]

print(ans)
