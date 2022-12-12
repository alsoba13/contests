# Self timed: * 00:24:24 | ** 00:26:50
def bfs(grid, start):
    n, m, inf = len(grid), len(grid[0]), len(grid)*len(grid[0])+1
    distances = [[inf for i in range(m)] for j in range(n)]
    q = [[start, 0]]
    distances[start[0]][start[1]] = 0
    while len(q)>0:
        node, distance = q.pop(0)
        for (dx, dy) in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nb = [node[0]+dx,node[1]+dy]
            if nb[0] not in range(n) or not nb[1] in range(m): continue
            if grid[node[0]][node[1]]-grid[nb[0]][nb[1]] > 1: continue
            if distances[nb[0]][nb[1]] is inf:
                q.append([(nb[0], nb[1]), distance+1])
                distances[nb[0]][nb[1]] = distance+1
    return distances

def find_min(distances, grid, end):
    return min([distances[i][j] for i in range(len(grid)) for j in range(len(grid[0])) if grid[i][j] == end])

grid = []
while True:
    try: grid.append([ord(i)-ord('a') if i.islower() else (-1 if i == 'S' else 26) for i in input().rstrip()])
    except EOFError: break

end_position = [(i, j) for i in range(len(grid)) for j in range(len(grid[0])) if grid[i][j] == 26][0]
distances = bfs(grid, end_position)
print("Problem1: {}".format(find_min(distances, grid, -1)))
print("Problem2: {}".format(find_min(distances, grid, 0)))