from math import lcm
from functools import reduce

def find(network, ins, node, is_ending):
    sol = 0
    while not is_ending(node):
        node = network[node][int(ins[sol % len(ins)])]
        sol += 1
    return sol

def slv(network, ins, is_starter, is_ending):
    starters = [node for node in network if is_starter(node)]
    return lcm(*[find(network, ins, node, is_ending) for node in starters])

ins, _, network_lines = input().rstrip().replace('L','0').replace('R','1'), input(), []
while True:
    try: network_lines.append(input().rstrip().split(" = "))
    except EOFError: break
network = {node: ways[1:-1].split(', ') for node, ways in network_lines}

print("Problem1: {}".format(slv(network, ins, lambda a: a == 'AAA', lambda a: a == 'ZZZ')))
print("Problem2: {}".format(slv(network, ins, lambda a: a[-1] == 'A', lambda a: a[-1] == 'Z')))