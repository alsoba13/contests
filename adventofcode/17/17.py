from collections import defaultdict
from itertools import product

def getNeighbours(cell):
    dims = []
    for dimension in cell:
        dims.append([dimension-1, dimension, dimension+1])
    return product(*dims)

def game_of_life(n, starting_state, dimensions=3):
    active_cells = set()
    for i in range(n):
        for j in range(n):
            if starting_state[i][j] == '#':
                active_cells.add(tuple([i,j]+[0]*(dimensions-2)))
    for _ in range(6):
        neighbours_in_cell = defaultdict(int)
        to_remove = set()
        to_add = set()
        for cell in active_cells:
            c = 0
            for neighbour in getNeighbours(cell):
                if neighbour == cell: continue
                neighbours_in_cell[neighbour] += 1
                if neighbour in active_cells: c += 1
            if c not in [2, 3]: to_remove.add(cell)
        for cell in neighbours_in_cell:
            if neighbours_in_cell[cell] == 3:
                to_add.add(cell)
        active_cells = active_cells | to_add
        active_cells = active_cells - to_remove
    return len(active_cells)

n = int(input())
starting_state = [input().rstrip() for _ in range(n)]
print("Problem1: {}\nProblem2: {}".format(game_of_life(n, starting_state), game_of_life(n, starting_state, dimensions = 4)))