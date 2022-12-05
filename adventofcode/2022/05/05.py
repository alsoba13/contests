def slv(stacks, lines, reverse):
    for n, f, t in lines:
        stacks[t], stacks[f] = stacks[t]+stacks[f][-n:][::-1 if reverse else 1], stacks[f][:-n]
    return ''.join([stack[-1] for stack in stacks])
    
stacks_text = [input().rstrip() for _ in range(10)]
stacks = [[] for i in range(9)]
for i, j in [(i, j) for i in range(8) for j in range(9)]:
    if stacks_text[7-i][4*j+1] != ' ': stacks[j].append(stacks_text[7-i][4*j+1])
lines = []
while True:
    try:
        line = input().strip().split(' from ')
        s, (f, t) = int(line[0].split('move ')[1]), [int(i)-1 for i in line[1].split(' to ')]
        lines.append([s, f, t])
    except EOFError: break
print("Problem1: {}".format(slv(stacks.copy(), lines, True)))
print("Problem2: {}".format(slv(stacks.copy(), lines, False)))