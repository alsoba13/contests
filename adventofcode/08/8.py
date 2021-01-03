n = int(input())
ins = [input().rstrip().split(' ') for _ in range(0, n)]
sol1 = None
for i in range(0, n):
    if sol1 and ins[i][0] == 'acc': continue
    acc = line = 0
    s = set()
    while line not in s and line < n:
        s.add(line)
        if ins[line][0] == 'acc':
            acc += int(ins[line][1])
            line += 1
        else:
            if ins[line][0] == 'jmp':
                line += int(ins[line][1]) if line != i else 1
            else:
                line += 1 if line != i else int(ins[line][1])
    if ins[i][0] == 'acc': sol1 = acc
    if line >= n: sol2 = acc; break
print("Problem1: {}\nProblem2: {}".format(sol1, sol2))