def rotate_grid(grid):
    return [[grid[j][i] for j in range(len(grid))] for i in range(len(grid[0])-1,-1,-1)]

def slv(grid, N):
    sol = [[True if i in (0, N-1) or j in (0, N-1) else False for i in range(N)] for j in range(N)]
    for rotation in range(4):
        for i in range(1, N):
            max_so_far = grid[i][0]
            for j in range(1, N):
                if grid[i][j] > max_so_far:
                    sol[i][j] = True
                    max_so_far = max(max_so_far, grid[i][j])
        grid = rotate_grid(grid)
        sol = rotate_grid(sol)
    return sum([sum(row) for row in sol])

def slv2(grid, N):
    sol = 0
    for x in range(N):
        for y in range(N):
            scenic_score = 1
            for dx, dy in [[1,0],[-1,0],[0,1],[0,-1]]:
                cnt, i, j = 0, x, y
                while True:
                    i, j = i+dx, j+dy
                    if i<0 or j<0 or i>=N or j>=N: break
                    cnt += 1
                    if grid[i][j] >= grid[x][y]: break
                scenic_score *= cnt
            sol = max(sol, scenic_score)
    return sol

lines = []
while True:
    try: 
        line = [int(i) for i in input().rstrip()]
        lines.append(line)
    except EOFError: break

print("Problem1: {}".format(slv(lines, len(lines))))
print("Problem2: {}".format(slv2(lines, len(lines))))