def process_instructions(line):
    instructions,last_token = [],line[0]
    for c in line[1:]+['']:
        if last_token.isdigit() != c.isdigit():
            instructions.append(int(last_token) if last_token.isdigit() else last_token)
            last_token = c
        else: last_token += c
    return instructions

def slv(cube, instructions, cube_transitions, cube_rotations, unfold_cube):
    dirs = [(0,1), (1,0), (0,-1), (-1,0)]
    face, position, orientation = 0, [0,0], 0 
    for instruction in instructions:
        if type(instruction) == int:
            for _ in range(instruction):
                next_position = [position[0]+dirs[orientation][0], position[1]+dirs[orientation][1]]
                next_face = face
                next_orientation = orientation
                if next_position[0] not in range(N) or next_position[1] not in range(N):
                    next_face, entering_edge = cube_transitions[face][orientation]
                    next_orientation = (entering_edge+2)%4
                    next_position = cube_rotations[orientation][entering_edge](next_position[0], next_position[1])
                if cube[next_face][next_position[0]][next_position[1]] == '.':
                    face, position, orientation = next_face, next_position, next_orientation
        else:
            if instruction == 'R': orientation = (orientation+1)%4
            else: orientation = (orientation-1)%4
    return 1000*(position[0]+1+unfold_cube[face][0]*N)+4*(position[1]+1+unfold_cube[face][1]*N)+orientation

grid = []
while True:
    try: grid.append([c for c in input()])
    except EOFError: break
instructions = process_instructions(grid[-1])
grid = grid[:-2]

num_cells = sum([1 for row in grid for cell in row if cell != ' '])
N = next(i for i in range(num_cells) if i*i*6 == num_cells)
unfold_cube = [
       [0,1], [0,2],
       [1,1],
[2,0], [2,1],
[3,0],
]
cube = [[row[face[1]*N:(face[1]+1)*N] for row in grid[face[0]*N:(face[0]+1)*N]] for face in unfold_cube]

PROBLEM1_TRANSITIONS = [
    [(1,2), (2,3), (1,0), (4,1)],
    [(0,2), (1,3), (0,0), (1,1)],
    [(2,2), (4,3), (2,0), (0,1)],
    [(4,2), (5,3), (4,0), (5,1)],
    [(3,2), (0,3), (3,0), (2,1)],
    [(5,2), (3,3), (5,0), (3,1)],
]
PROBLEM2_TRANSITIONS = [
    [(1,2), (2,3), (3,2), (5,2)],
    [(4,0), (2,0), (0,0), (5,1)],
    [(1,1), (4,3), (3,3), (0,1)],
    [(4,2), (5,3), (0,2), (2,2)],
    [(1,0), (5,0), (3,0), (2,1)],
    [(4,1), (1,3), (0,3), (3,1)],
]
cube_rotations = [
    [lambda x,y: [N-1-x, N-1], lambda x,y: [N-1, x], lambda x,y: [x, 0], lambda x,y: [0, N-1-x]],
    [lambda x,y: [y, N-1], lambda x,y: [N-1, N-1-y], lambda x,y: [N-1-y, 0], lambda x,y: [0, y]],
    [lambda x,y: [x, N-1], lambda x,y: [N-1, N-1-x], lambda x,y: [N-1-x, 0], lambda x,y: [0, x]],
    [lambda x,y: [N-1-y, N-1], lambda x,y: [N-1, y], lambda x,y: [y, 0], lambda x,y: [0, N-1-y]],
]

print("Problem1: {}".format(slv(cube, instructions, PROBLEM1_TRANSITIONS, cube_rotations, unfold_cube)))
print("Problem2: {}".format(slv(cube, instructions, PROBLEM2_TRANSITIONS, cube_rotations, unfold_cube)))