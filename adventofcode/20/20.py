import numpy as np
from collections import defaultdict
def borderToString(border): return ''.join([str(c) for c in border])
def normalize(s): return min(borderToString(s), borderToString(s)[::-1])
def getBorders(tile): return tile[0], tile[:,-1], tile[-1][::-1], tile[:,0][::-1]
def readTile(n_pixels):
    tile = np.zeros((n_pixels, n_pixels), dtype=int)
    tile_text = [input().rstrip() for _ in range(n_pixels)]
    for i in range(n_pixels):
        for j in range(n_pixels):
            if tile_text[i][j] == '#': tile[i][j]=1
    return tile
def newTile(tile, rotation, mirror): return {'tile': tile, 'rotation': rotation, 'mirror': mirror}
def mirrorBorders(borders): return [borders[0][::-1], borders[3][::-1], borders[2][::-1], borders[1][::-1]]
def rotateBorders(borders): return [borders[3], borders[0], borders[1], borders[2]]
def getTileWithBorderInIndex(border, tile_name, index):
    for tile in tiles:
        if tile_name == tile: continue
        borders = getBorders(tiles[tile])
        for b in borders:
            if normalize(b) == normalize(border):
                mirror = False
                if borderToString(b) != borderToString(border):
                    mirror = True
                    borders = mirrorBorders(borders)
                rotation = 0
                while borderToString(borders[index]) != borderToString(border):
                    rotation += 1
                    borders = rotateBorders(borders)
                return tile, rotation, mirror
def fill(x, y, dir):
    tile_name, rotation, mirror = sol[x][y]['tile'], sol[x][y]['rotation'], sol[x][y]['mirror']
    from_index, to_index = [[1,3],[2,0]][dir]
    for i in range(11):
        borders = getBorders(tiles[tile_name])
        if mirror: borders = mirrorBorders(borders)
        for r in range(rotation): borders = rotateBorders(borders)
        tile_name, rotation, mirror = getTileWithBorderInIndex(borders[from_index][::-1], tile_name, to_index)
        sol[x+dir*(i+1)][y+(1-dir)*(i+1)] = newTile(tile_name, rotation, mirror)
def compare(monster, image, x, y):
    for i in range(0,len(monster)):
        for j in range(0,len(monster[0])):
            if monster[i][j] == 1 and image[x+i][y+j] == 0: return
    for i in range(0,len(monster)):
        for j in range(0,len(monster[0])):
            if monster[i][j] == 1: image[x+i][y+j] = 2
n_pixels, n_tiles = int(input()), int(input())
tiles_with_border, tiles = defaultdict(list), {}
sol1, sol2, sol = 1, 0, []
for i in range(n_tiles):
    name = int(input().rstrip().split(' ')[1][:-1])
    tile = readTile(n_pixels)
    for border in getBorders(tile):
        tiles_with_border[normalize(border)].append(name)
    tiles[name] = tile
num_neighbours_by_name = defaultdict(int)
for tile in tiles_with_border:
    if len(tiles_with_border[tile])==1:
        for name in tiles_with_border[tile]:
            num_neighbours_by_name[name] += 1
for name in num_neighbours_by_name:
    if num_neighbours_by_name[name] == 2:
        sol1 *= name
        corner = name
for i in range(12):
    sol.append([0]*12)
sol[0][0] = newTile(corner, 0, False)
fill(0, 0, 0)
for i in range(12):
    fill(0, i, 1)
image = None
for i in range(12):
    line = None
    for j in range(12):
        tile = tiles[sol[i][j]['tile']][1:-1,1:-1]
        if sol[i][j]['mirror']:
            tile = np.flip(tile, axis=1)
        tile = np.rot90(tile, k=sol[i][j]['rotation'], axes=(1,0))
        if line is None: line = tile
        else: line = np.hstack((line, tile))
    if image is None: image = line
    else: image = np.vstack((image, line))
monster=np.array([[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0],
                  [1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,1],
                  [0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0]], dtype=int)
for monster in [monster, np.rot90(monster, k = 1), np.rot90(monster, k = 2), np.rot90(monster, k = 3), np.flip(monster,axis=1), np.flip(np.rot90(monster, k = 1), axis=1), np.flip(np.rot90(monster, k = 2), axis=1), np.flip(np.rot90(monster, k = 3), axis=1)]:
    for i in range(0, len(image)-len(monster)):
        for j in range(0, len(image[0])-len(monster[0])):
            compare(monster,image,i,j)
for line in image:
    sol2 += sum([int(a) for a in line if int(a) == 1])
print("Problem1: {}\nProblem2: {}".format(sol1, sol2))
