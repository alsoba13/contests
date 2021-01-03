from sys import stdin

sol1 = sol2 = 0
s1, s2 = [set(), set({c for c in 'abcdefghijklmnopqrstuvwxyz'})]
for line in stdin:
    if line.rstrip() == '':
        sol1 += len(s1)
        sol2 += len(s2)
        s1, s2 = [set(), set({c for c in 'abcdefghijklmnopqrstuvwxyz'})]
    else:
        s1=s1.union(set([c for c in line.rstrip()]))
        s2=s2.intersection(set([c for c in line.rstrip()]))
print("Problem1: {}\nProblem2: {}".format(sol1, sol2))