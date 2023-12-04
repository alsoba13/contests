def slv1(numbers, gears):
    sol = 0
    for number, row, start in numbers:
        if sum([j in range(start-1, start + len(str(number)) + 1) and i in range(row-1, row+2) for _, i, j in gears]): 
            sol += number
    return sol

def slv2(numbers, gears):
    sol = 0
    for i, j in [(i, j) for gear_type, i, j in gears if gear_type == '*']:
        nums = [number for number, row, start in numbers if j in range(start-1, start + len(str(number)) + 1) and i in range(row-1, row+2)]
        if len(nums) == 2: 
            sol += nums[0]*nums[1]
    return sol

data = []
while True:
    try: data.append(input().rstrip())
    except EOFError: break

gears = [(data[i][j], i, j) for i in range(len(data)) for j in range(len(data[0])) if data[i][j] != '.' and not data[i][j].isdigit()]
numbers = []
for row, line in enumerate(data):
    total_length_of_numbers = 0
    for numbers_so_far, number in enumerate(''.join(map(lambda x: x if x.isdigit() else '.', line)).split('.')):
        if number != '':
            numbers.append((int(number), row, numbers_so_far+total_length_of_numbers))
            total_length_of_numbers += len(number)

print("Problem1: {}".format(slv1(numbers, gears)))
print("Problem2: {}".format(slv2(numbers, gears)))