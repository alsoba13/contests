def slv(nums):
    return max(nums)
def slv2(nums):
    return sum(sorted(nums)[-3:])

nums = []
try:
    while True:
        c = []
        while True:
            n = input()
            if n == '':
                break
            c.append(int(n))
        nums.append(sum(c))
except EOFError: pass

print("Problem1: {}".format(slv(nums)))
print("Problem2: {}".format(slv2(nums)))