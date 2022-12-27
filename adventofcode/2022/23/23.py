from collections import defaultdict

def slv(elves, rounds):
    turns = [[(-1,-1), (-1,0), (-1,1)], [(1,-1), (1,0), (1,1)], [(-1,-1), (0,-1), (1,-1)], [(-1,1), (0,1), (1,1)]]
    nbs = [(-1,-1), (-1,0), (-1,1), (0,1), (1,1), (1,0), (1,-1), (0,-1)]
    for round in range(rounds):
        proposed = defaultdict(list)
        unmoved = set()
        for elf in elves:
            if all((elf[0]+nb[0], elf[1]+nb[1]) not in elves for nb in nbs):
                unmoved.add(elf)
                continue
            moved = False
            for direction in range(4):
                directions = turns[(round+direction)%4]
                if all([(elf[0]+dx, elf[1]+dy) not in elves for dx, dy in directions]):
                    proposed[(elf[0]+directions[1][0], elf[1]+directions[1][1])].append(elf)
                    moved = True
                    break
            if not moved: unmoved.add(elf)
        if len(unmoved) == len(elves):
            return round+1
        elves = unmoved
        for proposed_cell in proposed:
            if len(proposed[proposed_cell]) == 1: elves.add(proposed_cell)
            else: 
                for elf in proposed[proposed_cell]: elves.add(elf)
    return (1+max([elf[0] for elf in elves])-min([elf[0] for elf in elves])) * (1+max([elf[1] for elf in elves])-min([elf[1] for elf in elves])) - len(elves)

lines = []
while True:
    try: 
        line = input().rstrip()
        lines.append(line)
    except EOFError: break
elves = set((row_index, column_index) for row_index, row in enumerate(lines) for column_index, cell in enumerate(row) if cell == '#')
print("Problem1: {}".format(slv(elves, 10)))
print("Problem2: {}".format(slv(elves, 1000)))