def slv(nums, mult, repetitions):
    for _ in range(repetitions):
        for i in range(len(nums)):
            where = next(j for j in range(len(nums)) if nums[j][1] == i)
            num_to_move = nums.pop(where)
            where += num_to_move[0] * mult
            nums = nums[:where%len(nums)] + [num_to_move] + nums[where%len(nums):]
    where_zero = next(i for i in range(len(nums)) if nums[i][0] == 0)
    return sum([nums[(where_zero+(i+1)*1000)%len(nums)][0]*mult for i in range(3)])
            
lines = []
while True:
    try: lines.append([int(input().rstrip()), len(lines)])
    except EOFError: break

print("Problem1: {}".format(slv(lines.copy(), 1, 1)))
print("Problem2: {}".format(slv(lines.copy(), 811589153, 10)))