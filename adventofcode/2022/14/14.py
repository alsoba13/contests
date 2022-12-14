# Self timed: * 00:26:39 | ** 00:37:20

def release_mote(cave, ground_y):
    mote = [0, 500]
    while True:
        mote_moved = False
        for dx in [0, -1, 1]:
            if mote[0]+1 <= ground_y and (mote[0]+1, mote[1]+dx) not in cave:
                mote_moved = True
                mote = [mote[0]+1, mote[1]+dx]
                break
        if mote_moved is False:
            cave.add((mote[0],mote[1]))
            return mote[0]

def slv(cave, ground_y, stop_at_y):
    ans = 0
    while release_mote(cave, ground_y) != stop_at_y:
        ans += 1
    return ans

cave = set()
while True:
    try:
        points = [[int(i) for i in j.split(',')] for j in input().rstrip().split(' -> ')]
        for start, end in zip(points, points[1:]):
            ys = [start[0],end[0]]
            xs = [start[1],end[1]]
            for y in range(min(ys), max(ys)+1):
                for x in range(min(xs), max(xs)+1):
                    cave.add((x,y))
    except EOFError: break
ground_y = 1 + max([rock[0] for rock in cave])

print("Problem1: {}".format(slv(cave.copy(), ground_y, ground_y)-1))
print("Problem2: {}".format(slv(cave.copy(), ground_y, 0)))