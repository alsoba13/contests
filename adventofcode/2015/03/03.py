def slv(dirs, players):
    movements = {'<':(-1,0), '^':(0,1), '>': (1,0), 'v': (0,-1)}
    visited = {(0,0)}
    for player in range(players):
        current = (0,0)
        for dir in dirs[player::players]:
            current = (current[0]+movements[dir][0], current[1]+movements[dir][1])
            visited.add(current)
    return len(visited)

dirs = input().rstrip()

print("Problem1: {}".format(slv(dirs, 1)))
print("Problem1: {}".format(slv(dirs, 2)))