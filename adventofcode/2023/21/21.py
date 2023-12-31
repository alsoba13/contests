import sys

def bfs(grid, steps, starting):
    N, M = len(grid), len(grid[0])
    nodes = set([starting])
    for i in range(steps-1):
        nodes = set((x+dx,y+dy) for x,y in nodes for dx, dy in [(-1,0), (1,0), (0,1), (0,-1)] if x+dx in range(N) and y+dy in range(M) and grid[x+dx][y+dy]!='#')
    return len(nodes)

def slv1(grid):
    return bfs(grid, 64+1, (65,65))

def slv2(grid):
    N = (26501365-65)//131
    sol = (N**2)*bfs(grid, 131, (65,65))+((N-1)**2)*bfs(grid, 130, (65,65))
    for x, y in [(0,130), (130,130), (130,0), (0,0)]:
        sol += N*bfs(grid, 65, (x,y))
        sol += (N-1)*bfs(grid, 196, (x,y))
    for dx, dy in [(65,130), (65,0), (130,65), (0,65)]:
        sol += bfs(grid, 131, (x,y))
    return sol

grid = [[x for x in line.rstrip()] for line in sys.stdin.read().split('\n')]
print("Problem1: {}".format(slv1(grid)))
print("Problem2: {}".format(slv2(grid)))
