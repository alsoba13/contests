def slv(lines):
    sol = 0
    for line in lines:
        p = [line]
        while True:
            p.append([p[-1][i+1]-p[-1][i] for i in range(len(p[-1])-1)])
            if set(p[-1]) == {0}: break
        sol += sum([x[-1] for x in p])
    return sol

lines = []
while True:
    try: lines.append([int(x) for x in input().rstrip().split(' ')])
    except EOFError: break

print("Problem1: {}".format(slv(lines)))
print("Problem2: {}".format(slv([line[::-1] for line in lines])))