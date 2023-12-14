import sys

def rotate(rocks, stoppers, N, M):
    return set((y, N-x-1) for x,y in rocks), set((y, N-x-1) for x,y in stoppers), M, N

def tilt(rocks, stoppers, N, M):
    new_rocks = set()
    rocks = sorted(rocks)
    while len(rocks):
        x,y = rocks.pop(0)
        if x == 0 or (x-1, y) in stoppers or (x-1, y) in new_rocks: new_rocks.add((x,y))
        else: rocks.append((x-1, y))
    return (new_rocks, stoppers, N, M)

def score(rocks, stoppers, N, M):
    return sum(N-x for x,_ in rocks)

def cycle(grid):
    for i in range(4):
        grid = rotate(*tilt(*grid))
    return grid[0]

def slv1(rocks, stoppers, N, M):
    return score(*tilt(rocks, stoppers, N, M))

def slv2(rocks, stoppers, N, M, cycles):
    states = [rocks]
    while True:
        rocks = cycle((rocks, stoppers, N, M))
        cycles-=1
        if rocks in states: break
        states.append(rocks)
    states = states[states.index(rocks):]
    return score(states[cycles%len(states)], stoppers, N, M)
    
grid = tuple(tuple(c for c in line) for line in sys.stdin.read().split('\n'))
N, M = len(grid), len(grid[0])
rocks, stoppers = [set([(x, y) for x in range(N) for y in range(M) if grid[x][y] == c]) for c in 'O#']

print("Problem1: {}".format(slv1(rocks, stoppers, N, M)))
print("Problem2: {}".format(slv2(rocks, stoppers, N, M, 1000000000)))