def intersect(x, y):
    intersection = [max(x[0], y[0]), min(x[-1], y[-1])+1]
    left = [min(x[0], y[0]), min(intersection)]
    right = [max(intersection), max(x[-1], y[-1])+1]
    return range(*intersection), (range(*left), range(*right))

def slv(seeds, category_mappings):
    current_category_ranges = [range(seeds[i], seeds[i]+seeds[i+1]) for i in range(0,len(seeds),2)]
    for category_mapping in category_mappings:
        next_category_ranges = []
        for offset_range, offset in category_mapping:
            non_matched_ranges = []
            for current_category_range in current_category_ranges:
                intersection, leftovers = intersect(current_category_range, offset_range)
                if intersection: next_category_ranges.append(range(intersection[0]+offset, intersection[-1]+offset+1))
                for leftover_range in leftovers:
                    if leftover_range and intersect(leftover_range, current_category_range)[0] == leftover_range:
                        non_matched_ranges.append(leftover_range)
            current_category_ranges = non_matched_ranges
        next_category_ranges.extend(current_category_ranges)
        current_category_ranges = next_category_ranges
    return min([x[0] for x in current_category_ranges])

seeds = [int(x) for x in input().split(": ")[1].split(" ")]
category_mappings = []
input()
while True:
    try:
        input()
        category_mapping = []
        while True:
            line = input().rstrip()
            if line == '': break
            destination_start, source_start, length = [int(x) for x in line.split(' ')]
            category_mapping.append((range(source_start, source_start+length), destination_start-source_start))
        category_mappings.append(category_mapping)
    except EOFError: break

print("Problem1: {}".format(slv([rep_seed for seed in seeds for rep_seed in [seed, 1]], category_mappings)))
print("Problem2: {}".format(slv(seeds, category_mappings)))