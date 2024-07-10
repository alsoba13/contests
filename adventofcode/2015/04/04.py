import hashlib

def slv(seed, zeros):
    sol = 0
    while set(hashlib.md5((seed + str(sol)).encode()).hexdigest()[:zeros]) != {'0'}: sol += 1
    return sol

seed = input().rstrip()

print("Problem1: {}".format(slv(seed,5)))
print("Problem1: {}".format(slv(seed,6)))
