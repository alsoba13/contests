def gaps(grid):
    return [x for x in range(len(grid)) if grid[x].count('#') == 0]

def translate(grid):
    return [[grid[y][x] for y in range(len(grid[0]))] for x in range(len(grid))]

def slv(grid, gap_size):
    galaxies = [(x, y) for x in range(len(grid)) for y in range(len(grid[0])) if grid[x][y] == '#']
    gaps_x = gaps(grid)
    gaps_y = gaps(translate(grid))

    sol = 0
    for i, (x1, y1) in enumerate(galaxies):
        for x2, y2 in galaxies[i+1:]:
            x_gaps_found = sum(1 for gap in gaps_x if gap in range(min(x1, x2), max(x1,x2)))
            y_gaps_found = sum(1 for gap in gaps_y if gap in range(min(y1, y2), max(y1,y2)))
            sol += abs(x1 - x2) + abs(y1 - y2) + x_gaps_found*(gap_size-1) + y_gaps_found*(gap_size-1)
    return sol

grid = []
while True:
    try: grid.append(input().rstrip())
    except EOFError: break

print("Problem1: {}".format(slv(grid, 2)))
print("Problem2: {}".format(slv(grid, 1000000)))