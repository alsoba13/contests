from functools import reduce
def getNum(line, priority):
    if line[0].isdigit(): return int(line[0]), line[1:]
    else: return getExpression(line[1:], priority)

def getExpression(line, priority=False):
    value, line = getNum(line, priority)
    values = [value]
    while True:
        op, line = line[0], line[1:]
        if op == ')': return reduce(lambda a,b: a*b, values), line
        value, line = getNum(line, priority)
        if op == '+': values[-1] += value
        else: 
            if priority: values.append(value)
            else: values[-1] *= value
    
sol1 = sol2 = 0
for line in ['('+''.join(input().rstrip().split(' '))+')' for _ in range(int(input()))]:
    sol1 += getExpression(line[1:])[0]
    sol2 += getExpression(line[1:], priority=True)[0]
print("Problem1: {}\nProblem2: {}".format(sol1, sol2))