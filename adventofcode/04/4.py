from sys import stdin
def check1(field, value):
    return field in ['byr', 'iyr', 'eyr', 'hgt', 'hcl', 'ecl', 'pid']

def check2(field, value):
    if field == 'byr':
        return 1920 <= int(value) <= 2002
    if field == 'iyr':
        return 2010 <= int(value) <= 2020
    if field == 'eyr':
        return 2020 <= int(value) <= 2030
    if field == 'hgt':
        if value[-2:] == 'cm':
            return 150 <= int(value[:-2]) <= 193
        if value[-2:] == 'in':
            return 59 <= int(value[:-2]) <= 76
        return False
    if field == 'hcl':
        return value[0] == '#'
    if field == 'ecl':
        return value in ['amb', 'blu', 'brn', 'gry', 'grn', 'hzl', 'oth']
    if field == 'pid':
        return len(value) == 9 and value.isdigit()
    return False

sol1 = sol2 = valid_fields1 = valid_fields2 = 0
for line in stdin:
    if line.rstrip() == '':
        if valid_fields1 == 7:
            sol1 += 1
        if valid_fields2 == 7:
            sol2 += 1
        valid_fields1 = valid_fields2 = 0
    else:
        for field in line.rstrip().split(' '):
            field, value = field.split(':')
            valid_fields1 += check1(field, value)
            valid_fields2 += check2(field, value)
print("Problem1: {}\nProblem2: {}".format(sol1, sol2))