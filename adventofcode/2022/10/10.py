def slv(cmds):
    op = None
    x, cycle = 1, 0
    problem1, problem2 = 0, ['\n']
    while len(cmds)>0 or op is not None:
        cycle += 1
        if op is None:
            cmd, cmds = cmds[0], cmds[1:]
            if cmd == 'noop': ttl, op = 1, cmd
            else: ttl, op, incr = 2, cmd.split(' ')[0], int(cmd.split(' ')[1])

        if cycle % 40 == 20: problem1 += x*cycle
        
        problem2.append('#' if abs((cycle-1)%40-x)<=1 else '.')
        if cycle % 40 == 0: problem2.append('\n')
        
        ttl -= 1
        if ttl == 0: 
            if op == 'addx': x += incr
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