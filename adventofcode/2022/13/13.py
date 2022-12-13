# Self timed: * 00:15:05 | ** 00:25:57
from functools import cmp_to_key
from copy import deepcopy
def cmp_w(a, b):
    return cmp(deepcopy(a), deepcopy(b))

def cmp(a,b):
    if len(a) == 0 and len(b) != 0: return -1
    if len(a) != 0 and len(b) == 0: return 1
    if len(a) == 0 and len(b) == 0: return 0
    x = a.pop(0)
    y = b.pop(0)
    if type(x) == int and type(y) == int:
        if x<y: return -1
        if x>y: return 1
        if x==y: return cmp(a, b)
    if type(x) == int:
        x = [x]
    if type(y) == int:
        y = [y]
    xx = cmp(x, y)
    if xx == 0: return cmp(a, b)
    return xx


def slv1(pairs):
    return sum([i+1 for i, (item1, item2) in enumerate(pairs) if cmp(item1, item2) < 0])

def slv2(packets, extra_packets):
    packets += extra_packets
    sorted_packets = sorted(packets, key=cmp_to_key(cmp_w))
    extra_packets_indices = [i+1 for i, packet in enumerate(sorted_packets) if packet in extra_packets]
    return extra_packets_indices[0] * extra_packets_indices[1]

lines = []
while True:
    try:
        pair = [input().rstrip(), input().rstrip()]
        lines.append([eval(i) for i in pair])
        input()
    except EOFError: break

print("Problem1: {}".format(slv1(deepcopy(lines))))
print("Problem2: {}".format(slv2([i for pair in lines for i in pair], [[[2]], [[6]]])))