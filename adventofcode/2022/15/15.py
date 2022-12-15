# Self timed: * 00:16:52 | ** 00:52:21
def merge_intervals(intervals):
    intervals.sort()
    stack = [intervals[0]]
    for i in intervals[1:]:
        if stack[-1][0] <= i[0] <= stack[-1][-1]: stack[-1][-1] = max(stack[-1][-1], i[-1])
        else: stack.append(i)
    return stack

def get_occupied_intervals(points, N = 4000001):
    intervals = [[] for _ in range(N)]
    for sensor, beacon in points:
        distance = abs(beacon[1]-sensor[1])+abs(beacon[0]-sensor[0])
        for y in range(max(0, sensor[1]-distance), min(N, sensor[1]+distance+1)):
            remaining_dist = distance-abs(sensor[1]-y)
            interval = [sensor[0]-remaining_dist, sensor[0]+remaining_dist+1]
            intervals[y] = merge_intervals(intervals[y] + [interval])
    return intervals

def slv1(intervals, points, y=2000000):
    beacons_overlapping = set(beacon for _, beacon in points if beacon[1] == y)
    return intervals[y][0][1]-intervals[y][0][0]-len(beacons_overlapping)

def slv2(intervals):
    for y, line in enumerate(intervals):
        if len(line)>1: return line[0][1]*4000000 + y

points = []
while True:
    try: points.append([(int(part.split(', y=')[0].split('x=')[1]), int(part.split(', y=')[1])) for part in input().rstrip().split(":")])
    except EOFError: break
occupied_intervals=get_occupied_intervals(points)

print("Problem1: {}".format(slv1(occupied_intervals, points)))
print("Problem2: {}".format(slv2(occupied_intervals)))