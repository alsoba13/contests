import sys
from collections import defaultdict
import heapq as hq

def f(x, y):
    return 5*(N-1-x+M-1-y)

def slv(grid, mm, MM):
    sols = defaultdict(lambda: 10*sum(sum(line) for line in grid))
    q = [(f(0,1),0, 1, 0, 1, 1, 0), (f(1,0),1, 0, 1, 0, 1, 0)]
    hq.heapify(q)
    while len(q):
        _, x, y, dx, dy, s, sol = hq.heappop(q)
        if x not in range(N) or y not in range(M): continue
        sol += grid[x][y]
        if sol >= sols[(x, y, dx, dy, s)]: continue
        if (x, y) == (N-1, M-1) and s<mm: continue
        sols[(x, y, dx, dy, s)] = min(sol,sols[(x, y, dx, dy, s)])
        if s in range(mm, MM+1):
            for ss in range(s, MM+1):
                sols[(x, y, dx, dy, ss)] = sol
        if s < MM:
            hq.heappush(q, (f(x+dx, y+dy), x+dx, y+dy, dx, dy, s+1, sol))
        if s >= mm:
            hq.heappush(q, (f(x+dy,y+dx),x+dy, y+dx, dy, dx, 1, sol))
            hq.heappush(q, (f(x-dy, y-dx),x-dy, y-dx, -dy, -dx, 1, sol))
    return min(sols[x] for x in sols if (x[0], x[1]) == (N-1, M-1))


grid = [[int(x) for x in line] for line in sys.stdin.read().split('\n')]
N, M = len(grid), len(grid[0])

print("Problem1: {}".format(slv(grid, 0, 3)))
print("Problem2: {}".format(slv(grid, 4, 10)))