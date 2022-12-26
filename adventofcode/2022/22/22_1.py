def slv1(grid, instructions):
    dirs = [(0,1), (1,0), (0,-1), (-1,0)]
    position, orientation = [0, grid[0].index('.')], 0 
    for instruction in instructions:
        if instruction.isdigit():
            for _ in range(int(instruction)):
                next_position = [position[0], position[1]]
                next_position[0] = (next_position[0]+dirs[orientation][0])%len(grid)
                next_position[1] = (next_position[1]+dirs[orientation][1])%len(grid[0])
                while grid[next_position[0]][next_position[1]] == ' ':
                    next_position[0] = (next_position[0]+dirs[orientation][0])%len(grid)
                    next_position[1] = (next_position[1]+dirs[orientation][1])%len(grid[0])
                if grid[next_position[0]][next_position[1]] == '.':
                    position = next_position
        else:
            if instruction == 'R': orientation = (orientation+1)%4
            else: orientation = (orientation-1)%4
    return 1000*(position[0]+1)+4*(position[1]+1)+orientation
                  
                
                

    

def split_(s):
    sub = []
    char = ""
    num = ""
    for letter in s:
        if letter.isdigit():
            if char:
                sub.append(char)
                char = ""
            num += letter
        else:
            if num:
                sub.append(num)
                num = ""
            char += letter
    sub.append(char) if char else sub.append(num)
    return sub

grid = []
while True:
    try: grid.append([c for c in input()])
    except EOFError: break
grid, instructions = grid[:-2], ''.join(grid[-1])
M = max([len(row) for row in grid])
for i in range(len(grid)):
    grid[i].extend([' ']*(M-len(grid[i])))
instructions = split_(instructions)
print("Problem1: {}".format(slv1(grid, instructions)))