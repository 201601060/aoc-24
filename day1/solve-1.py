list1 = []
list2 = []

with open('input.txt', 'r') as input:
    for i in input:
        n1, n2 = map(int, i.split())
        list1.append(n1)
        list2.append(n2)

list1.sort()
list2.sort()

sum_diff = sum(abs(a - b) for a, b in zip(list1, list2))

print(sum_diff)
