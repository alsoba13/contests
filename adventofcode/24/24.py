m = set()
for line in [input().rstrip() for i in range(int(input()))]:
    ne = e = se = 0
    while line:
        d, line = (line[:1], line[1:]) if line[0] in ['e', 'w'] else (line[:2], line[2:])
        ne, e, se = ne + (1 if d == 'ne' else -1 if d == 'sw' else 0), e + (1 if d == 'e' else -1 if d == 'w' else 0), se + (1 if d == 'se' else -1 if d == 'nw' else 0)
    x, y = e+ne, se-ne
    if (x, y) in m: m.remove((x,y))
    else: m.add((x,y))
sol1 = len(m)
for _ in range(100):
    neighbours = [(0,1), (0,-1), (1,0), (-1,0), (1,-1), (-1, 1)]
    to_remove, to_add, black_neighbours = set(), set(), dict()
    for (x, y) in m:
        if sum([1 for (nx, ny) in neighbours if (x+nx, y+ny) in m]) in [0, 3, 4, 5, 6]: to_remove.add((x, y))
        for (nx, ny) in neighbours:
            black_neighbours[(x+nx, y+ny)] = black_neighbours[(x+nx, y+ny)] + 1 if (x+nx, y+ny) in black_neighbours else 1
    for cell in black_neighbours:
        if cell not in m and black_neighbours[cell] == 2: to_add.add(cell)
    for cell in to_remove: m.remove(cell)
    for cell in to_add: m.add(cell)
print("Problem1: {}\nProblem2: {}".format(sol1, len(m)))