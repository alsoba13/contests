# Self timed: * 00:19:29 | ** 00:24:56
from functools import reduce
from copy import deepcopy
def slv(monkeys, mod, rounds, relief):
    for _ in range(rounds):
        for items, operation, div, if_true, if_false, cnt in monkeys:
            while len(items)>0:
                item = items.pop(0)
                cnt[0] += 1
                item = (eval(operation.format(item, item)) // relief) % mod
                monkeys[if_true if item % div == 0 else if_false][0].append(item)
    return reduce(lambda x, y: x*y, sorted(list(map(lambda x: x[5][0], monkeys)))[-2:])

monkeys = []
try: 
    while True:
        input()
        monkeys.append([
            [int(i) for i in input().split(': ')[1].split(', ')], 
            input().split('= ')[1].replace('old', "{}"), 
            *[int(input().split(' ')[-1]) for _ in range(3)],
            [0],
        ])
        input()
except EOFError: pass
mod = reduce(lambda x, y: x*y, list(map(lambda x: x[2], monkeys)))

print("Problem1: {}".format(slv(deepcopy(monkeys), mod, 20, 3)))
print("Problem1: {}".format(slv(deepcopy(monkeys), mod, 10000, 1)))