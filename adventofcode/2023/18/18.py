import sys

def slv(lines):
    loop = [(0,0)]
    for direction, amount in lines:
        dx,dy = ((0,1),(1,0),(0,-1),(-1,0))[direction]
        loop.append((loop[-1][0] + dx * amount, loop[-1][1] + dy * amount))
    boundary = sum(abs(x2-x1)+abs(y2-y1) for (x1,y1),(x2,y2) in zip(loop, loop[1:]))
    area = abs(sum(x1*y2 - x2*y1 for (x1,y1),(x2,y2) in zip(loop, loop[1:])))//2 # gauss_area
    return area + boundary//2 + 1 # pick's theorem

lines = [[("RDLU".index(dir),int(amount)),(int(color[-2]), int(color[2:-2],16))] for dir,amount,color in [line.split(' ') for line in sys.stdin.read().split('\n')]]

print("Problem1: {}".format(slv([line[0] for line in lines])))
print("Problem2: {}".format(slv([line[1] for line in lines])))