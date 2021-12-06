min_sol = n = int(input())
a = [int(i) if i != 'x' else i for i in input().rstrip().split(',')]
N = []
A = []
for i in range(len(a)):
    if (a[i] != 'x'):
        if a[i]-n%a[i] < min_sol:
            min_sol = a[i] - n%a[i]
            sol = min_sol * a[i]
        N.append(a[i])
        A.append((a[i]-i)%a[i])

def inv(a, b):
    b0 = b
    x0, x1 = 0, 1
    if b == 1: return 1
    while a > 1:
        q = a // b
        a, b = b, a%b
        x0, x1 = x1 - q * x0, x0
    if x1 < 0: x1 += b0
    return x1

def chinese_remainder(n, a):
    N = 1
    for ni in n:
        N *= ni
    s = 0
    for ai, ni in zip(a, n):
        s += ai * N//ni * inv(N//ni, ni)
    return s % N

print("Problem1: {}\nProblem2: {}".format(sol, chinese_remainder(N, A)))