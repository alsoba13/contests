n = int(input())
entries = []
for i in range(0, n):
    entries.append(int(input()))
for i in range(0, n):
    for j in range(i+1, n):
        if entries[i] + entries[j] == 2020:
            sol1 = entries[i] * entries[j]
        for k in range(j+1, n):
            if entries[i] + entries[j] + entries[k] == 2020:
                sol2 = entries[i] * entries[j] * entries[k]
print("Problem1: {}\nProblem2: {}".format(sol1, sol2))