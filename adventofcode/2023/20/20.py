import sys
from copy import deepcopy
from functools import reduce

def pulse(graph, sols, track, i):
    LOW, HIGH = False, True
    q = [('button', LOW, 'roadcaster')]
    while len(q):
        source, pulse, node = q.pop(0)
        if source == 'rx': return i
        sols[pulse] += 1
        if node not in graph: continue
        if graph[node][0] == 'b':
            for destination in graph[node][1]:
                q.append((node, LOW, destination))
            continue
        if graph[node][0] == '%':
            if pulse is HIGH: continue
            graph[node][2] = not graph[node][2]
            for destination in graph[node][1]:
                q.append((node, graph[node][2],destination))
            continue
        graph[node][2][source] = pulse
        if node in track and all(graph[node][2].values()):
            track[node].append(i)
        for destination in graph[node][1]:
            q.append((node, not all(graph[node][2].values()), destination))

def slv(graph):
    sols = [0,0]
    track = {node: [] for node in ['gf','vc','db','qx']}
    for i in range(1000):
        pulse(graph, sols, track, i)
    return sols[0]*sols[1]

def slv2(graph):
    track = {node: [] for node in ['gf','vc','db','qx']}
    for i in range(1,5000):
        pulse(graph, [0,0], track, i)
    return reduce(lambda a,b: a*b, [x[-1] for x in track.values()])
        

lines = sys.stdin.read().split('\n')
graph = dict()
for line in lines:
    node, destinations = line.split(' -> ')
    graph[node[1:]] = [node[0], destinations.split(', '), dict() if node[0] == '&' else False]
for node in graph:
    for destination in graph[node][1]:
        if destination in graph:
            if graph[destination][0] == '&': graph[destination][2][node] = False

print("Problem1: {}".format(slv(deepcopy(graph))))
print("Problem2: {}".format(slv2(graph)))