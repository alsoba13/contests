def intersect(x, y):
    intersection = range(max(x[0], y[0]), min(x[-1], y[-1])+1)
    if intersection:
        leftovers = (range(min(x[0], y[0]), intersection[0]), range(intersection[-1]+1, max(x[-1], y[-1])+1))
        return intersection, leftovers
    return intersection, None

def slv(seeds, maps):
    seed_ranges = [range(seeds[i], seeds[i]+seeds[i+1]) for i in range(0,len(seeds),2)]
    for map in maps:
        new_ranges = []
        for seed_range in seed_ranges:
            q = [seed_range]
            while len(q):
                seed_range = q.pop(0)
                changed = False
                for map_range, offset in map:
                    intersection, leftovers = intersect(seed_range, map_range)
                    if not intersection: continue
                    changed = True
                    new_ranges.append(range(intersection[0]+offset, intersection[-1]+offset+1))
                    for leftover_range in leftovers:
                        if leftover_range and leftover_range[0] in seed_range and leftover_range[-1] in seed_range:
                            q.append(leftover_range)
                    break
                if not changed: 
                    new_ranges.append(seed_range)
        seed_ranges = new_ranges
    return sorted([x[0] for x in seed_ranges])[0]

seeds = [int(x) for x in input().split(": ")[1].split(" ")]
maps = []
input()
while True:
    try:
        source, destination = input().split(' ')[0].split('-to-')
        lists = []
        while True:
            line = input().rstrip()
            if line == '': break
            values = [int(x) for x in line.split(' ')]
            lists.append((range(values[1], values[1]+values[2]), values[0]-values[1]))
        maps.append(lists)
    except EOFError: break

print("Problem1: {}".format(slv([rep_seed for seed in seeds for rep_seed in [seed, 1]], maps)))
print("Problem2: {}".format(slv(seeds, maps)))