from functools import reduce

def hash_function(s):
    return reduce(lambda hash,character: 17*(hash+ord(character))%256, s, 0)

def slv1(instructions):
    return sum(hash_function(s) for s in instructions)

def unroll(instruction):
    return (instruction[:-1], None) if instruction[-1] == '-' else (instruction[:-2], int(instruction[-1]))

def slv2(instructions):
    boxes = [([],dict()) for i in range(256)]
    for instruction in instructions:
        label, fl = unroll(instruction)
        order, fls = boxes[hash_function(label)]
        if fl:
            if label not in order: order.append(label)
            fls[label] = fl
        else:
            if label in order:
                order.remove(label)
                fls.pop(label)
    return sum( i * j * fls[label] for i, (order,fls) in enumerate(boxes, 1) for j, label in enumerate(order, 1) )

instructions = input().rstrip().split(',')

print("Problem1: {}".format(slv1(instructions)))
print("Problem2: {}".format(slv2(instructions)))