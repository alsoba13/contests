import sys

def slv1(lines):
    return sum(
        1 for line in lines
            if sum(line.count(vowel) for vowel in 'aeiou') >= 3
               and any(a == b for a,b in zip(line, line[1:]))
               and all(not_permmited not in line for not_permmited in ['ab', 'cd', 'pq', 'xy'])
        )

def slv2(lines):
    sol = 0
    for line in lines:
        if any(line[i:i+2] in line[0:i] or line[i:i+2] in line[i+2:] for i in range(0,len(line)-2)) and \
        any(line[i:i+3] == line[i:i+3][::-1] for i in range(0,len(line)-3)): sol +=1
    return sol

lines = sys.stdin.read().splitlines()

print("Problem1: {}".format(slv1(lines)))
print("Problem1: {}".format(slv2(lines)))
