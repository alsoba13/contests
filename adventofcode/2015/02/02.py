import sys

def slv(presents):
    return sum(2*a*b + 2*b*c + 2*a*c + a*b for a, b, c in presents)

def slv2(presents):
    return sum(2*(a+b)+a*b*c for a, b, c in presents)

presents = [sorted([int(x) for x in line.split('x')]) for line in sys.stdin.readlines()]

print("Problem1: {}".format(slv(presents)))
print("Problem2: {}".format(slv2(presents)))