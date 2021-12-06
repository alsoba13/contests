n = int(input())
a = sorted([int(input()) for _ in range(0, n)])
a = [0] + a + [max(a) + 3]
diffs = [a[i]-a[i-1] for i in range(1, n+2)]
ways = [1] + [0]*(n+1)
for i in range(0, n+1):
    for j in range(i+1, min(n+2, i+4)):
        if a[j] - a[i] <= 3:
            ways[j] += ways[i]
print("Problem1: {}\nProblem2: {}".format(diffs.count(1)*diffs.count(3), ways[n+1]))