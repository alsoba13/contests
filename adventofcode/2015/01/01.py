def slv(parenthesis):
    return [parenthesis[:i+1].count('(')-parenthesis[:i+1].count(')') for i in range(len(parenthesis))]

balance = slv(input().rstrip())

print("Problem1: {}".format(balance[-1]))
print("Problem2: {}".format(balance.index(-1)+1))