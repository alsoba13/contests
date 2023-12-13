def slv(times, distances):
    sol = 1
    for time, distance in zip(times, distances):
        race_sols = 0
        for v in range(0, time+1):
            d = (time-v)*v
            if d > distance: race_sols += 1
        sol *= race_sols
    return sol

times = [int(x) for x in input().split(":")[1].split(" ") if x != '']
distances = [int(x) for x in input().split(":")[1].split(" ") if x != '']

print("Problem1: {}".format(slv(times, distances)))
print("Problem2: {}".format(slv([int(''.join([str(t) for t in times]))], [int(''.join([str(d) for d in distances]))])))