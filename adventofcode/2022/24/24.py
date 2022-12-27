from collections import defaultdict
import math
dirs = {'^': (-1, 0), '>': (0, 1), 'v': (1, 0), '<': (0,-1)}

def next_state(blizzards, N, M): 
    new_state = defaultdict(list)
    for blizzard_position in blizzards:
        for blizzard in blizzards[blizzard_position]:
            new_state[((blizzard_position[0]+dirs[blizzard][0])%N, (blizzard_position[1]+dirs[blizzard][1])%M)].append(blizzard)
    return new_state

def bfs(blizzards, N, M, start, destination, time):
    q = [(start, time)]
    seen = set(q[0])
    while len(q)>0:
        node, time = q.pop(0)
        time += 1
        for dx, dy in [[0, 1], [1, 0], [0, 0], [0, -1], [-1, 0]]:
            next_pos = (node[0]+dx, node[1]+dy)
            if next_pos == destination: return time
            if next_pos != start and (next_pos[0] not in range(N) or next_pos[1] not in range(M)): continue
            if next_pos not in blizzards[time%len(blizzards)] and (next_pos, time) not in seen:
                seen.add((next_pos, time))
                q.append((next_pos, time))

def slv(blizzards, N, M, path):
    t = 0
    for i in range(len(path)-1): 
        t = bfs(blizzards, N, M, path[i], path[i+1], t)
    return t

lines = []
while True:
    try: lines.append(input().rstrip()[1:-1])
    except EOFError: break
N, M = len(lines)-2, len(lines[0])
all_states = [{(row_i, column_i): [cell] for row_i, row in enumerate(lines[1:-1]) for column_i, cell in enumerate(row) if cell not in '.'}]
for i in range(N*M//math.gcd(N, M) - 1):
    all_states.append(next_state(all_states[-1], N, M))

print("Problem1: {}".format(slv(all_states, N, M, [(-1,0), (N, M-1)])))
print("Problem2: {}".format(slv(all_states, N, M, [(-1,0), (N,M-1), (-1,0), (N,M-1)])))
