m1 = {}
m2 = {}
for line in [input().rstrip() for _ in range(int(input()))]:
    if line.split(' ')[0] == 'mask':
        mask = line.split(' ')[2]
        zeros, ones, xs = int(mask.replace('X', '1'), 2), int(mask.replace('X', '0'), 2), int(mask.replace('0', '1').replace('X', '0'), 2)
        offsets = [0]
        for i in range(0, 36):
            if mask[i] == 'X':
                for offset in offsets.copy():
                    offsets.append(offset + (1<<(35-i)))
    else:
        pos, value = int(line.split(' ')[0][4:-1]), int(line.split(' ')[2])
        m1[pos] = value & zeros | ones
        for offset in offsets:
            m2[(pos & xs | ones) + offset] = value
print("Problem1: {}\nProblem2: {}".format(sum([m1[i] for i in m1]), sum([m2[i] for i in m2])))