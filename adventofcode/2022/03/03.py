def slv(rucksacks, n):
    ans = 0
    for rucksacks_group in zip(*[iter(rucksacks)]*n):
        for c in rucksacks_group[0]:
            if all(c in rucksack for rucksack in rucksacks_group[1:]):
                ans += ord(c) - ord('a') + 1 if ord(c) in range(ord('a'), ord('z')+1) else ord(c) - ord('A') + 27
                break
    return ans 
    
rucksacks = []
while True:
    try:
        rucksacks.append(input().rstrip())
    except EOFError: break

print("Problem1: {}".format(slv( [rucksack_half for rucksack_pair in [[i[0:len(i)//2], i[len(i)//2:]] for i in rucksacks] for rucksack_half in rucksack_pair], 2)))
print("Problem2: {}".format(slv(rucksacks, 3)))