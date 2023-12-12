DEP = "DEP"
mem = dict()
def put_first(line, amount):
    line = [c for c in line]
    while len(line) and line[0] == '.':
        line = line[1:]
    while len(line) and amount and line[0] in '?#':
        line = line[1:]
        amount -= 1
    if amount: return DEP
    if len(line) and line[0] == '#': return DEP
    if len(line) and line[0] == '?': line = line[1:]
    return line

def dont_put(line):
    line = [c for c in line]
    while len(line) and line[0] == '.':
        line = line[1:]
    if len(line) and line[0] == '#': return []
    return line[1:]

def f(pattern, line):
    if (pattern,''.join(line)) in mem: return mem[(pattern,''.join(line))]
    if line == DEP: return 0
    if not line: 
        return 1 if not pattern else 0
    if not pattern:
        return 1 if '#' not in line else 0
    left_line = put_first(line, pattern[0])
    left = f(pattern[1:], left_line)
    #print("put_first ", line, pattern, left_line, left, pattern[1:])
    right_line = dont_put(line)
    right = f(pattern, right_line)
    #print("dont_put ", line, pattern, right_line, right)
    sol = left + right
    #print(pattern, ''.join(line), sol)
    mem[(pattern, ''.join(line))] = sol
    return sol

def compute_pattern(line):
    pattern = []
    last, line = 1 if line[0] == '#' else 0, line[1:]
    for c in line:
        if c == '.':
            if last != 0: 
                pattern.append(last)
                last = 0
        else: last +=1
    if last!=0:
        pattern.append(last)
    return pattern

def unfold(line):
    return '?'.join([''.join(line)]*5)

def slv2(lines, times):
    sol = 0
    for line in lines:
        #line, pattern = [c for c in line[0]]*5, [int(x) for x in line[1].split(',')]*5
        line, pattern = (line[0]), tuple([int(x) for x in line[1].split(',')*times])
        if times == 5:
            line = unfold(line)
        #print(['#'*i for i in pattern])
        #print(sum(pattern), sum([len(x) for x in line]))
        sol += f(pattern, line)

        #unknown_locs = [i for i, s in enumerate(line) if s == '?']
        #missing_damaged = sum(pattern) - line.count('#')
        #print(len(unknown_locs), missing_damaged)
        #sol += f(line, unknown_locs, missing_damaged, 0, pattern)
    return sol

def slv(lines):
    sol = 0
    for line in lines:
        line, pattern = [c for c in line[0]], [int(x) for x in line[1].split(',')]
        unknown_locs = [i for i, s in enumerate(line) if s == '?']
        missing_damaged = sum(pattern) - line.count('#')
        #sol += f(line, unknown_locs, missing_damaged, 0, pattern)ç
        sol_lines = []
        for i in range(2**len(unknown_locs)):
            bin_i = bin(i)[2:]
            if bin_i.count('1') != missing_damaged: continue
            bin_i = ''.join(['0']*(len(unknown_locs)-len(bin_i))) + bin_i
            bin_i = bin_i.replace('0', '.').replace('1', '#')
            line_copy = line.copy()
            for i, j in enumerate(unknown_locs):
                line_copy[j] = bin_i[i]
            if compute_pattern(line_copy) == pattern: 
                sol_lines.append(line_copy)
        sol += len(sol_lines)
        print(line)
        for i in unknown_locs:
            if len(set([l[i] for l in sol_lines])) == 1:
                line[i] = sol_lines[0][i]
        print(line)
    return sol


lines = []
while True:
    try: lines.append(input().rstrip().split(' '))
    except EOFError: break

print("Problem1: {}".format(slv2(lines, times = 1)))
print("Problem2: {}".format(slv2(lines, times = 5)))