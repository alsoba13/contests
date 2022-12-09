def sign(a):
    return 1 if a > 0 else (-1 if a < 0 else 0)
def slv(lines, rope):
    visited = {rope[-1]}
    dirs = {'D':(1, 0), 'U':(-1, 0), 'L':(0, 1), 'R':(0, -1)}
    for dir, times in lines:
        d = dirs[dir]
        for _ in range(int(times)):
            rope[0] = (rope[0][0] + d[0], rope[0][1] + d[1])
            for i in range(1, len(rope)):
                if abs(rope[i][0] - rope[i-1][0]) > 1 or abs(rope[i][1] - rope[i-1][1]) > 1:
                    rope[i] = (rope[i][0] + sign(rope[i-1][0]-rope[i][0]), rope[i][1] + sign(rope[i-1][1]-rope[i][1]))
            visited.add(rope[-1])
    return len(visited)

lines = []
while True:
    try: lines.append(input().rstrip().split(' '))
    except EOFError: break

print("Problem1: {}".format(slv(lines, [(0,0) for knot in range(2)])))
print("Problem2: {}".format(slv(lines, [(0,0) for knot in range(10)])))