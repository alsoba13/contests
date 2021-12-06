ranges = []
names = []
line = input().rstrip()
while line:
    names.append(line.split(': ')[0])
    line = line.split(': ')[1].split(' ')
    ranges.append([[int(line[0].split('-')[0]), int(line[0].split('-')[1])], [int(line[2].split('-')[0]), int(line[2].split('-')[1])]])
    line = input().rstrip()
line = input().rstrip()
my_ticket = [int(i) for i in input().rstrip().split(',')]
line = input().rstrip()
line = input().rstrip()
line = input().rstrip()
sol1 = 0
tickets = []
while line:
    line_ok = True
    for i in [int(j) for j in line.rstrip().split(',')]:
        ok = False
        for r in ranges:
            if (r[0][0] <= i and i <= r[0][1]) or (r[1][0] <= i and i <= r[1][1]):
                ok = True
        if not ok:
            sol1 += i
            line_ok = False
    if line_ok:
        tickets.append([int(j) for j in line.rstrip().split(',')])
    line = input()
positions_found = {}
while len(positions_found)<len(ranges):
    for i in range(len(ranges)): # ticket position
        if i not in positions_found:
            possible_sols = []
            for j in range(len(ranges)): # ranges position
                if j not in positions_found.values():
                    all_ok = True
                    for ticket in tickets:
                        if not (ranges[j][0][0] <= ticket[i] <= ranges[j][0][1] or ranges[j][1][0] <= ticket[i] <= ranges[j][1][1]):
                            all_ok = False
                    if all_ok:
                        possible_sols.append(j)
            if len(possible_sols) == 1:
                positions_found[i]=possible_sols[0]
sol2 = 1
for i in positions_found:
    if names[positions_found[i]].split(' ')[0] == 'departure':
        sol2 *= my_ticket[i]
print("Problem1: {}\nProblem2: {}".format(sol1, sol2))