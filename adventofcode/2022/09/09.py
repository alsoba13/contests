def sign(a):
    return 1 if a > 0 else (-1 if a < 0 else 0)
def slv(lines, rope):
    ts = {rope[-1]}
    for dir, times in lines:
        if dir == 'D': d = (1, 0)
        if dir == 'U': d = (-1, 0)
        if dir == 'L': d = (0, 1)
        if dir == 'R': d = (0, -1)
        for _ in range(int(times)):
            rope[0] = (rope[0][0] + d[0], rope[0][1] + d[1])
            for i in range(1, len(rope)):
                if abs(rope[i][0] - rope[i-1][0]) > 1 or abs(rope[i][1] - rope[i-1][1]) > 1:
                    rope[i] = (rope[i][0] + sign(rope[i-1][0]-rope[i][0]), rope[i][1] + sign(rope[i-1][1]-rope[i][1]))
            ts.add(rope[-1])
    return len(ts)

lines = []
while True:
    try: lines.append(input().rstrip().split(' '))
    except EOFError: break

print("Problem1: {}".format(slv(lines, [(0,0) for k in range(2)])))
print("Problem2: {}".format(slv(lines, [(0,0) for k in range(10)])))