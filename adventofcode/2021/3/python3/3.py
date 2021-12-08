def commonty(l, most_common=True, untie='0'):
    c0 = l.count('0')
    c1 = l.count('1')
    if c0 > c1: return '0' if most_common else '1'
    if c0 < c1: return '1' if most_common else '0'
    return untie

def slv(binaries):
    a = "".join([commonty([binary[i] for binary in binaries]) for i in range(len(binaries[0]))])
    b = a.replace('0', '2').replace('1', '0').replace('2', '1')
    return int(a, 2) * int(b, 2)

def slv2(binaries, most_common, untie):
    prefix_mask = ''
    while len(binaries) > 1:
        prefix_mask = prefix_mask + commonty([binary[len(prefix_mask)] for binary in binaries], most_common, untie)
        binaries = [binary for binary in binaries if binary.startswith(prefix_mask)]
    return int(binaries[0], 2)

binaries = []
while True:
    try:
        binaries.append(input().rstrip())
    except EOFError: break
print("Problem1: {}".format(slv(binaries)))
print("Problem2: {}".format(slv2(binaries.copy(), most_common=True, untie='1') * slv2(binaries.copy(), most_common=False, untie='0')))