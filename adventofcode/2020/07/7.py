from collections import defaultdict
g1 = defaultdict(list)
g2 = defaultdict(list)

def dfs1(a_bag, s = set()):
    for bag in g1[a_bag]:
        s.add(bag)
        dfs1(bag, s)
    return len(s)

def dfs2(a_bag):
    m = 0
    for bag in g2[a_bag]:
        m += bag[0] * (dfs2(bag[1]) + 1)
    return m

for i in range(0, int(input())):
    line = input().rstrip().split(' ')
    bag1 = ' '.join(line[0:2])
    if line[4] == 'no':
        continue
    line = line[4:]
    while line:
        n = int(line[0])
        bag2 = ' '.join(line[1:3])
        g1[bag2].append(bag1)
        g2[bag1].append([n, bag2])
        line = line[4:]
print("Problem1: {}\nProblem2: {}".format(dfs1('shiny gold'), dfs2('shiny gold')))