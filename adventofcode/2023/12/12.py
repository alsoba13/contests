mem = dict()

def put(conf, amount):
    while conf and amount and conf[0] in '?#':
        conf = conf[1:]
        amount -= 1
    if amount or (conf and conf[0] == '#'): raise("IMPOSSIBLE")
    return conf[1:]

def compute_f(pattern, conf):
    while conf and conf[0] == '.': conf = conf[1:] # remove dots from beginning
    if not pattern: # we are done
        if '#' not in conf: return 1 # we found a solution!
        return 0 # there are '#' in the remaining configuration
    if not conf: return 0 # not enough space for the reminding pattern
    try: sol = f(pattern[1:], put(conf, pattern[0])) # number of sols by trying to put next pattern right now
    except: sol = 0
    if conf[0] == '?': sol += f(pattern, conf[1:]) # number of sols by not putting any pattern right now
    return sol

def f(pattern, conf): # memoization
    if (pattern, conf) not in mem: mem[(pattern, conf)] = compute_f(pattern, conf)
    return mem[(pattern, conf)]

def slv(lines, times):
    sol = 0
    for line in lines:
        conf, pattern = '?'.join([line[0]]*times), tuple(int(x) for x in line[1].split(',')*times)
        sol += f(pattern, conf)
    return sol

lines = []
while True:
    try: lines.append(input().rstrip().split(' '))
    except EOFError: break

print("Problem1: {}".format(slv(lines, times = 1)))
print("Problem2: {}".format(slv(lines, times = 5)))