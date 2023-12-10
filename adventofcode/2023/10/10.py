def find_loop(grid):
    pipes = {
        '|': {(1,0), (-1,0)},
        '-': {(0,1), (0,-1)},
        'L': {(-1,0), (0,1)},
        'J': {(-1,0), (0,-1)},
        '7': {(1,0), (0,-1)},
        'F': {(1,0), (0,1)},
        '.': {},
    }
    N, M = len(grid), len(grid[0])
    
    (Sx, Sy) = next((x,y) for x, line in enumerate(grid) for y, node in enumerate(line) if node == 'S')
    valid_dirs = {(dx, dy) for dx, dy in {(-1,0), (1,0), (0,-1), (0,1)} if (-dx, -dy) in pipes[grid[Sx+dx][Sy+dy]]}
    grid[Sx][Sy] = next(pipe for pipe, dirs in pipes.items() if dirs == valid_dirs)
    
    seen = [[False for x in range(M)] for y in range(N)]
    nodes = [[(Sx, Sy), 0]]
    while len(nodes):
        (x, y), steps = nodes.pop(0)
        seen[x][y] = True
        next_nodes = [(x+dx, y+dy) for dx, dy in pipes[grid[x][y]] if not seen[x+dx][y+dy]]
        nodes.extend([(node, steps+1) for node in next_nodes])
    grid = [[grid[x][y] if seen[x][y] else '.' for y in range(M)] for x in range(N)]
    return grid

def zoom_grid(grid):
    zooms = {
        '|': [['.','#','.'],
             ['.','#','.'],
             ['.','#','.']],

        '-': [['.','.','.'],
             ['#','#','#'],
             ['.','.','.']],

        'L': [['.','#','.'],
             ['.','#','#'],
             ['.','.','.']],

        'J': [['.','#','.'],
             ['#','#','.'],
             ['.','.','.']],

        '7': [['.','.','.'],
             ['#','#','.'],
             ['.','#','.']],

        'F': [['.','.','.'],
             ['.','#','#'],
             ['.','#','.']],

        '.': [['.','.','.'],
             ['.','.','.'],
             ['.','.','.']],
    }
    N, M = len(grid), len(grid[0])
    new_grid = [['' for y in range(3*M)] for x in range(3*N)]
    for x in range(N):
        for y in range(M):
            for xx in range(3):
                for yy in range(3):
                    new_grid[3*x+xx][3*y+yy] = zooms[grid[x][y]][xx][yy]
    return new_grid

def slv1(grid):
    total_free_cells = sum([line.count('.') for line in grid])
    return (len(grid)*len(grid[0])-total_free_cells)//2
    
def slv2(grid):
    grid = zoom_grid(grid)
    N, M = len(grid), len(grid[0])
    nodes = [[0,0]]
    seen = [[False for x in range(M)] for y in range(N)]
    seen[0][0] = True
    while len(nodes):
        (x, y) = nodes.pop(0)
        grid[x][y] = '#'
        for dx, dy in {(-1,0), (1,0), (0,-1), (0,1)}:
            if not seen[x+dx][y+dy] and grid[x+dx][y+dy] == '.':
                seen[x+dx][y+dy] = True
                nodes.append([x+dx, y+dy])
    return sum(1 for x in range(N//3) for y in range(M//3) if grid[3*x+1][3*y+1] == '.')

grid = []
while True:
    try: grid.append(['.'] + [c for c in input().rstrip()] + ['.'])
    except EOFError: break
grid = find_loop([['.' for x in range(len(grid[0]))]] + grid + [['.' for x in range(len(grid[0]))]])

print("Problem1: {}".format(slv1(grid)))
print("Problem2: {}".format(slv2(grid)))