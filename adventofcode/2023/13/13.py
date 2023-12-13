import sys

def transpose(pattern):
    return [*zip(*pattern)]

def find_mirror(pattern, expected_number_of_differences):
    for row in range(0, len(pattern)-1):
        rows_above = pattern[row::-1]
        rows_below = pattern[row+1:]
        number_of_differences = 0
        for row1, row2 in zip(rows_above, rows_below):
            for r1,r2 in zip(row1, row2):
                if r1 != r2: number_of_differences+=1
        if number_of_differences == expected_number_of_differences:
            return row+1
    return 0

def slv(patterns, expected_number_of_differences):
    return sum(100*find_mirror(pattern, expected_number_of_differences) + find_mirror(transpose(pattern), expected_number_of_differences) for pattern in patterns)

patterns = [[line for line in pattern.splitlines()] for pattern in sys.stdin.read().split("\n\n")]

print("Problem1: {}".format(slv(patterns, 0)))
print("Problem2: {}".format(slv(patterns, 1)))