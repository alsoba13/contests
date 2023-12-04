def slv(games):
    sol = 0
    total = {'r':12, 'g':13, 'b':14}
    for i, game in enumerate(games):
        ok = True
        for step in game:
            for color, cubes_shown in step.items():
                if cubes_shown > total[color]:
                    ok = False
        if ok: sol += i+1
    return sol

def slv2(games):
    sol = 0
    for game in games:
        maxs = {'r':0, 'g':0, 'b': 0}
        for step in game:
            for color, cubes_shown in step.items():
                maxs[color] = max(maxs[color], cubes_shown)
        sol += maxs['r']*maxs['g']*maxs['b']
    return sol

games = []
while True:
    try: games.append([{cubes.split(' ')[1][0]: int(cubes.split(' ')[0]) for cubes in step.split(", ")} for step in input().rstrip().split(": ")[1].split("; ")])
    except EOFError: break

print("Problem1: {}".format(slv(games)))
print("Problem2: {}".format(slv2(games)))