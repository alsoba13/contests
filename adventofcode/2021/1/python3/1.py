def slv(nums, window_width):
    ans = 0
    for i in range(len(nums)-window_width):
        if nums[i] < nums[i+window_width]: ans += 1
    return ans

nums = []
while True:
    try: nums.append(int(input()))
    except EOFError: break
print("Problem1: {}".format(slv(nums, 1)))
print("Problem2: {}".format(slv(nums, 3)))