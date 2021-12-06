from collections import defaultdict
n = int(input())
rules = defaultdict(list)
rules_end = defaultdict(set)
for rule in [input().rstrip() for _ in range(n)]:
    rule = rule.split(':')
    n_rule = int(rule[0])
    rule = rule[1][1:]
    if rule[0] == '"':
        rules_end[n_rule].add(rule[1:-1])
    else:
        for r in rule.split(' | '):
            rules[n_rule].append([int(_) for _ in r.split(' ')])

def rules_for(which):
    if which in rules_end:
        return rules_end[which]
    my_rules = set()
    for rule in rules[which]:
        if len(rule) == 1:
            r0 = rules_for(rule[0])
            for i in r0:
                my_rules.add(i)
        else:
            r0 = rules_for(rule[0])
            r1 = rules_for(rule[1])
            for i in r0:
                for j in r1:
                    my_rules.add(i+j)
    rules_end[which] = my_rules
    return my_rules

def hack_sol2(word):
    if len(word) % 8 != 0: return 0
    c42, c31 = 0, 0
    for i in range(0, len(word), 8):
        if word[i:i+8] not in rules_for(42) and word[i:i+8] not in rules_for(31): return 0
        if word[i:i+8] in rules_for(42):
            if c31 > 0: return 0
            c42 += 1
        if word[i:i+8] in rules_for(31):
            c31 += 1
    if c31 > 0 and c42 > 0 and c42-c31>0: return 1
    return 0

sol1, sol2 = 0, 0
m = int(input())
for word in [input().rstrip() for _ in range(m)]:
    if word in rules_for(0):
        sol1 += 1
    sol2 += hack_sol2(word)
print("Problem1: {}\nProblem2: {}".format(sol1, sol2))