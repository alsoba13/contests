n = int(input())
x = y = dir = x2 = y2 = 0
wx = 10
wy = 1
dirs = ['E', 'S', 'W', 'N']
def move(x, y, l, value):
    if l == 'E':
        x+=value
    if l == 'W':
        x-=value
    if l == 'N':
        y+=value
    if l == 'S':
        y-=value
    return x, y

for ins in [input().rstrip() for _ in range(0, n)]:
    l = ins[0]
    value = int(ins[1:])
    if l == 'R':
        dir += (value//90)
        for i in range(value//90):
            t = wx
            wx = wy
            wy = -t
    if l == 'L':
        dir -= (value//90)
        for i in range(4-value//90):
            t = wx
            wx = wy
            wy = -t
    if l == 'F':
        x, y = move(x, y, dirs[dir%4], value)
        x2 += value*wx
        y2 += value*wy
    x, y = move(x, y, l, value)
    wx, wy = move(wx, wy, l, value)
print("Problem1: {}\nProblem2: {}".format(abs(x)+abs(y), abs(x2)+abs(y2)))