def slv(line, n):
    for i in range(len(line)-n):
        if len(set(line[i:i+n]))==n:
            return i+n

line = input().rstrip()
print("Problem1: {}".format(slv(line, 4)))
print("Problem2: {}".format(slv(line, 14)))