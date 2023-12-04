def slv(data, numbers_to_replace = []):
    num = 0
    for line in data:
        for i, written_number in enumerate(numbers_to_replace):
            line = line.replace(written_number, written_number+str(i+1)+written_number)
        line = [digit for digit in line if digit.isdigit()]
        num += int(line[0] + line[-1])
    return num

data = []
while True:
    try: data.append(input().rstrip())
    except EOFError: break

print("Problem1: {}".format(slv(data, [])))
print("Problem2: {}".format(slv(data, ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine"])))