import sys

def rotate(dx, dy, cell):
    m = (-1 if cell == '/' else 1)
    return dy * m, dx * m

def path(grid, x, y, dx, dy):
    seen = set()
    q = [(x,y,dx,dy)]
    while len(q):
        x, y, dx, dy = q.pop(0)
        if x not in range(len(grid)) or y not in range(len(grid[0])): continue
        if (x,y,dx,dy) in seen: continue
        seen.add((x,y,dx,dy))
        cell = grid[x][y]
        if cell == '.' or (dx and cell == '|') or (dy and cell == '-'): 
            q.append((x+dx, y+dy, dx, dy)) # pass through
        else:
            dx, dy = rotate(dx, dy, cell) # let's rotate
            q.append((x+dx, y+dy, dx, dy))
            if cell in '|-': q.append((x-dx, y-dy, -dx, -dy)) # also split
    return {(x,y) for x,y,_,_ in seen}

def slv(grid, initial_points):
    return max( len(path(grid,*initial_point)) for initial_point in initial_points )

grid = sys.stdin.read().split('\n')

print("Problem1: {}".format(slv(grid, {(0,0,0,1)})))
print("Problem2: {}".format(slv(grid, {(x,y,dx,dy) for x in range(len(grid)) for y in range(len(grid[0])) for dx,dy in ((0,1),(0,-1),(1,0),(-1,0)) if x in (0,len(grid)-1) or y in (0,len(grid[0])-1) })))