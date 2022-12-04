def slv(pairs, min_overlaps):
    num_overlaps = map(lambda p: max((p[0] in range(p[2], p[3]+1)) + (p[1] in range(p[2], p[3]+1)), (p[2] in range(p[0], p[1]+1)) + (p[3] in range(p[0], p[1]+1))), pairs)
    return sum([overlaps >= min_overlaps for overlaps in num_overlaps])
    
pairs = []
while True:
    try: pairs.append([int(i) for pair in input().rstrip().split(',') for i in pair.split('-')])
    except EOFError: break

print("Problem1: {}".format(slv(pairs, 2)))
print("Problem2: {}".format(slv(pairs, 1)))