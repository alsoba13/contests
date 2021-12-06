s = int(input())
slopes = []
for i in range(0, s):
    slopes.append([int(inp) for inp in input().rstrip().split(' ')])
n, m = [int(inp) for inp in input().rstrip().split(' ')]
mp = [input() for i in range(0, n)]
sol = 1
for slope in slopes:
    sol *= [mp[i][j] for i, j in [ [i, i//slope[0]*slope[1]%m] for i in range(0, n, slope[0])]].count('#')
print(sol)