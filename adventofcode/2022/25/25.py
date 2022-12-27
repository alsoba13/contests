from math import floor

def slv(lines):
    values = ['=', '-', '0', '1', '2']
    ans, carry = '', 0
    for _ in range(max([len(line) for line in lines])):
        for line in lines:
            if len(line) == 0: continue
            digit = line.pop()
            carry += values.index(digit)-2
        ans = values[(carry+2)%5] + ans
        carry = floor((carry+2)/5)
    return ans

lines = []
while True:
    try: lines.append([c for c in input().rstrip()])
    except EOFError: break

print("Problem1: {}".format(slv(lines)))