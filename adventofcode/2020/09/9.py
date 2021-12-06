# slower but easier to code
from itertools import product
def find_cont():
    for i in range(2, n+1):
        for j in range(0, n-i):
            if sum(a[j:j+i]) == sol1:
                return max(a[j:j+i]) + min(a[j:j+i])

N = int(input())
O = int(input())
a = [int(input()) for _ in range(0, N)]
for n in range(O, N):
    found = False
    for i, j in product(a[n-O:n], a[n-O:n]):
        if i != j and i + j == a[n]:
            found = True
            break
    if not found:
        sol1 = a[n]
        break
sol2 = find_cont()
print("Problem1: {}\nProblem2: {}".format(sol1, sol2))