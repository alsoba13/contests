# Self timed: * 00:05:15 | ** 00:54:56
nbs = [(-1,0,0), (1,0,0), (0,-1,0), (0,1,0), (0,0,-1), (0,0,1)]
def slv(points):
    return sum([1 for nb in nbs for point in points if [point[0]+nb[0], point[1]+nb[1], point[2]+nb[2]] not in points])

def slv2(points, N):
    visited = [[0,0,0]]
    q = [[0,0,0]]
    while len(q)>0:
        node = q.pop(0)
        for nb in nbs:
            nb = [node[0]+nb[0], node[1]+nb[1], node[2]+nb[2]]
            if nb[0] not in range(N) or nb[1] not in range(N) or nb[2] not in range(N): continue
            if nb not in points and nb not in visited:
                visited.append(nb)
                q.append(nb)
    return slv(visited) - N*N*6
            
lines = []
while True:
    try:
        line = input().rstrip()
        lines.append([int(i)+1 for i in line.split(',')])
    except EOFError: break
print("Problem1: {}".format(slv(lines)))
print("Problem1: {}".format(slv2(lines, 2+max([max(i) for i in lines]))))