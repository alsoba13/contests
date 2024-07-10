import sys
from collections import defaultdict
NEIGHBOURS = [(0,1), (1,0), (0,-1), (-1,0)]

def intersection(grid, node):
    N, M = len(grid), len(grid[0])
    x,y = node
    cnt = 0
    for dx, dy in NEIGHBOURS:
        if x+dx in range(N) and y+dy in range(M) and grid[x+dx][y+dy] != '#':
            if node == (2, 6): print("!!", x+dx, y+dy)
            cnt += 1
    if cnt > 2:
        return True
    return False

def slv1(grid):
    N, M = len(grid), len(grid[0])
    node = (0, next(y for y in range(M) if grid[0][y] == '.'))
    target = (N-1, next(y for y in range(M) if grid[N-1][y] == '.'))
    for i in range(N):
        for j in range(M):
            if grid[i][j] == '.': cnt_ways((i,j), grid)
    return 0

def traverse_graph(grid):
    N, M = len(grid), len(grid[0])
    starting = (0, next(y for y in range(M) if grid[0][y] == '.'))
    target = (N-1, next(y for y in range(M) if grid[N-1][y] == '.'))
    graph = {starting: [], target: []}
    q = [(starting, (1,0))]
    while len(q):
        (x,y), (dx,dy) = q.pop(0)
        starting_from = (x,y)
        l = 0
        while True:
            nbs = get_neighbours
            x,y = x+dx, y+dy
            l+=1
        new_node = (x+dx, y+dy)
        if new_node not in graph: graph[new_node] = []
        graph[starting_from].append((new_node, l))
    print(graph)


grid = sys.stdin.read().split('\n')
graph = traverse_graph(grid)

print("Problem1: {}".format(slv1(grid)))
#print("Problem2: {}".format(sum(cnt)))
