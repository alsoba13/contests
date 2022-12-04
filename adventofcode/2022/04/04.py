def slv(pairs, min_overlaps):
    return sum([1 if max(int(p1[0] in range(p2[0], p2[1]+1)) + int(p1[1] in range(p2[0], p2[1]+1)), int(p2[0] in range(p1[0], p1[1]+1)) + int(p2[1] in range(p1[0], p1[1]+1))) >= min_overlaps else 0 for  p1, p2 in pairs])
    
pairs = []
while True:
    try: pairs.append([[int(i) for i in p.split('-')] for p in input().rstrip().split(',')])
    except EOFError: break

print("Problem1: {}".format(slv(pairs, 2)))
print("Problem1: {}".format(slv(pairs, 1)))