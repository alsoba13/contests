values = [int(_) for _ in input().rstrip().split(',')]
m = {}
c = 1
for i in range(len(values)-1):
    m[values[i]] = c
    c+=1
last_spoken = values[-1]
while c < 30000000:
    if last_spoken not in m:
        m[last_spoken], last_spoken = c, 0
    else:
        m[last_spoken], last_spoken = c, c - m[last_spoken]
    c+=1
    if c == 2020:
        sol1 = last_spoken
print("Problem1: {}\nProblem2: {}".format(sol1, last_spoken))
