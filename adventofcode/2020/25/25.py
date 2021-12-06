pk1 = int(input().rstrip())
pk2 = int(input().rstrip())
M = 20201227
s = 1
for i in range(1, pk1+1):
    s*=7
    s%=M
    if s%M == pk1:
        sl1=i
        break
s = 1
for i in range(sl1):
    s*=pk2
    s%=M
print("Problem1: {}".format(s))
