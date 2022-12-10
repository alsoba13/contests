def slv(cmds):
    op = None
    x, cycle = 1, 0
    problem1, problem2 = 0, ['\n']
    while len(cmds)>0: # or op is not None:
        cycle += 1
        if op is None:
            op, cmds = cmds[0].split(' '), cmds[1:]
            ttl = len(op)

        if cycle % 40 == 20: problem1 += x * cycle
        
        problem2.append('#' if abs((cycle-1)%40-x)<=1 else '.')
        if cycle % 40 == 0: problem2.append('\n')
        
        ttl -= 1
        if ttl == 0: 
            if op[0] == 'addx': x += int(op[1])
            op = None
    return problem1, ''.join(problem2)

lines = []
while True:
    try: 
        line = input().rstrip()
        lines.append(line)
    except EOFError: break

sols = slv(lines)
print("Problem1: {}".format(sols[0]))
print("Problem2: {}".format(sols[1]))