# Self timed: * 00:38:53 | ** 01:32:45
compute_max_height = lambda cave: max([point[0]+1 for point in cave], default=0)
rocks = [[(0,2), (0,3), (0,4), (0,5)], 
            [(0,3), (1,2), (1,3), (1,4), (2,3)], 
            [(0,2), (0,3), (0,4), (1,4), (2,4)], 
            [(0,2), (1,2), (2,2), (3,2)],
            [(0,2), (0,3), (1,2), (1,3)],]

def place_rock(cave, dirs, time, rocks, rocks_placed):
    max_height = compute_max_height(cave)
    rock = [(i[0]+max_height+3, i[1]) for i in rocks[rocks_placed%5]]
    while True:
        dir, time = (-1 if dirs[time%len(dirs)] == '<' else 1), time+1
        move_horizontally = lambda point: (point[0], point[1]+dir)
        if all([point not in cave and point[1] in range(7) for point in map(move_horizontally, rock)]):
            rock = list(map(move_horizontally, rock))
        move_down = lambda point: (point[0]-1, point[1])
        if all([point not in cave and point[0]>=0 for point in map(move_down, rock)]):
            rock = list(map(move_down, rock))
        else:
            for point in rock: cave.add(point)
            break
    max_height = compute_max_height(cave)
    return {point for point in cave if point[0]>max_height-40}, time

def slv(dirs, num_rocks):
    cave = set()
    time = 0
    rocks_placed = 0
    states = {}
    while rocks_placed < num_rocks:
        cave, time = place_rock(cave, dirs, time, rocks, rocks_placed)
        state = (rocks_placed%5, time%len(dirs))
        max_height = compute_max_height(cave)
        rocks_placed+=1
        if state not in states: states[state] = (rocks_placed, max_height)
        else:
            old_rocks_placeed, old_height = states[state]
            d_rocks = rocks_placed - old_rocks_placeed
            d_height = max_height - old_height
            if rocks_placed % d_rocks == num_rocks % d_rocks:
                cycles_remaining = (num_rocks - rocks_placed)//d_rocks
                return old_height + (d_height * (cycles_remaining + 1))
    return compute_max_height(cave)

line = input().rstrip()
print("Problem1: {}".format(slv(line, 2022)))
print("Problem1: {}".format(slv(line, 1000000000000)))
