import functools

def slv(data, replacements = []):
    for i, replacement in enumerate(replacements): data = list(map(lambda x: x.replace(replacement, replacement + str(i+1) + replacement), data))
    return functools.reduce(lambda x,y: x+y, map(lambda numbers: int(numbers[0]+numbers[-1]), map(lambda line: list(filter(lambda c: c.isdigit(), line)), data)))

data = []
while True:
    try: data.append(input().rstrip())
    except EOFError: break

print("Problem1: {}".format(slv(data, [])))
print("Problem2: {}".format(slv(data, ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine"])))