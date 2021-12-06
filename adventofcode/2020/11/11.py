def occupied(a, i, j, di, dj, direct_neighbour):
    if di == 0 and dj == 0: 
        return False 
    i+=di
    j+=dj
    while i>=0 and j>=0 and i<n and j<m:
        if direct_neighbour or a[i][j] != '.':
            return a[i][j] == '#'
        i+=di
        j+=dj
    return False

def slv(a, neighbours, direct_neighbour=False):
    while True:
        changes = []
        for i in range(0, n):
            for j in range(0, m):
                if a[i][j] == '.':
                    continue
                c = 0
                for di in range(-1, 2):
                    for dj in range(-1, 2):
                        c += occupied(a, i, j, di, dj, direct_neighbour)
                if (a[i][j] == 'L' and c == 0) or (a[i][j] == '#' and c >= neighbours):
                    changes.append([i,j])
        if len(changes) == 0:
            break
        for change in changes:
            if a[change[0]][change[1]] == '#':
                a[change[0]] = a[change[0]][:change[1]]+'L'+a[change[0]][change[1]+1:] 
            else:
                a[change[0]] = a[change[0]][:change[1]]+'#'+a[change[0]][change[1]+1:] 
        changes = []    
    sol = 0
    for i in range(0, n):
        for j in range(0, m):
            if a[i][j] == '#':
                sol+=1
    return sol

n, m = [int(_) for _ in input().rstrip().split(' ')]
a = [input().rstrip() for _ in range(0, n)]
print("Problem1: {}\nProblem2: {}".format(slv(a.copy(), 4, True), slv(a.copy(), 5)))