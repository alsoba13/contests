import sys
from functools import reduce
INF = 5000

def accepted(part, workflows):
    workflow = 'in'
    while workflow not in 'RA':
        for rule, destination in workflows[workflow]:
            if eval(str(part[rule[0]]) + rule[1:]):
                workflow = destination
                break
    return workflow == 'A'

def slv1(workflows, parts):
    return sum(sum(part.values()) for part in parts if accepted(part,workflows))

def intersect(x,y):
    return range(max(x[0], y[0]), min(x[-1], y[-1])+1)
def oposite(x):
    return range(x[-1]+1, INF) if x[0] == -INF else range(-INF, x[0])

def dfs(workflows, remaining_parts, workflow):
    if workflow == 'A': return reduce(lambda x,y: x*y, [len(i) for i in remaining_parts.values()])
    if workflow == 'R': return 0
    sol = 0
    for rule, destination in workflows[workflow]:
        category, comp, value = rule[0], rule[1], int(rule[2:])
        interval_ok = range(-INF,value) if comp == '<' else range(value+1, INF)
        sol += dfs(workflows, remaining_parts | {category:intersect(remaining_parts[category], interval_ok)}, destination)
        remaining_parts[category] = intersect(remaining_parts[category], oposite(interval_ok))
    return sol

def slv2(workflows):
    parts = {category_name:range(1,4001) for category_name in 'xmas'}
    return dfs(workflows, parts, 'in')

workflows, parts = [block.split('\n') for block in sys.stdin.read().split('\n\n')]
workflows = {workflow_name: [rule.split(':') if ':' in rule else ['s<'+str(INF-1),rule] for rule in rules.split(',')] for workflow_name, rules in [workflow[:-1].split('{') for workflow in workflows]}
parts = [{category_name:int(value) for category_name, value in [category.split('=') for category in part]} for part in [part[1:-1].split(',') for part in parts]]
print("Problem1: {}".format(slv1(workflows, parts)))
print("Problem2: {}".format(slv2(workflows)))