inp = open('in').read().strip()
regs, progs = inp.split('\n\n')

rega, regb, regc = regs.split('\n')

A = int(rega.split()[2])
B = int(regb.split()[2])
C = int(regc.split()[2])

prog = progs.split()[1].split(',')

print(A, B, C, prog)


def combo(k):
    op = -1
    if 0 <= k <= 3:
        op = k
    elif k == 4:
        op = A
    elif k == 5:
        op = B
    elif k == 6:
        op = C
    else:
        print('INVALID')
    return op


i = 0
while 0 <= i < len(prog):
    ins = int(prog[i])
    op = int(prog[i+1])

    if ins == 0:
        A = A >> combo(op)
    elif ins == 1:
        B = B ^ op
    elif ins == 2:
        B = combo(op) % 8
    elif ins == 3:
        if A != 0:
            i = op
        else:
            i += 2
    elif ins == 4:
        B = B ^ C
    elif ins == 5:
        print(f'{combo(op) % 8},', end='')
    elif ins == 6:
        B = A >> combo(op)
    elif ins == 7:
        C = A >> combo(op)
    else:
        print('INVALID')

    if ins == 3:
        continue
    else:
        i += 2
