# Self timed: * 00:16:52 | ** 00:52:21
from functools import cmp_to_key
def merge_intervals(intervals):
    intervals.sort()
    stack = [intervals[0]]
    for i in intervals[1:]:
        if stack[-1][0] <= i[0] <= stack[-1][-1]: stack[-1][-1] = max(stack[-1][-1], i[-1])
        else: stack.append(i)
    return stack

def get_occupied_intervals(points, N = 4000001):
    known_beacons = set(beacon for _, beacon in points)
    intervals = [[] for _ in range(N)]
    for sensor, beacon in points:
        distance = abs(beacon[1]-sensor[1])+abs(beacon[0]-sensor[0])
        for x in range(N):
            remaining_dist = distance-abs(sensor[1]-x)
            if remaining_dist<0: continue
            interval = [sensor[0]-remaining_dist, sensor[0]+remaining_dist+1]
            intervals[x] = merge_intervals(intervals[x] + [interval])
    return intervals

def slv1(intervals, points, y=2000000):
    beacons_overlapping = set(beacon for _, beacon in points if beacon[1] == y)
    return intervals[y][0][1]-intervals[y][0][0]-len(beacons_overlapping)

def slv2(intervals):
    for y, line in enumerate(intervals):
        if len(line)>1: return line[0][1]*4000000 + y

lines = []
while True:
    try: lines.append([(int(part.split(', y=')[0].split('x=')[1]), int(part.split(', y=')[1])) for part in input().rstrip().split(":")])
    except EOFError: break
lines_sorted_by_distance = sorted(lines, key=cmp_to_key(lambda a, b: abs(b[0][0]-b[1][0])+abs(b[0][1]-b[1][1])-abs(a[0][0]-a[1][0])-abs(a[0][1]-a[1][1])))
occupied_intervals=get_occupied_intervals(lines_sorted_by_distance)

print("Problem2: {}".format(slv1(occupied_intervals)))
print("Problem2: {}".format(slv2(occupied_intervals)))