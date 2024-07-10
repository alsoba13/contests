from collections import defaultdict
T = int(input())
for test in range(T):
	N, M = [int(x) for x in input().split()]
	s = input().rstrip()
	a = defaultdict(int)
	for problem in s:
		a[problem] += 1
	sol = 0
	for problem in 'ABCDEFG':
		if a[problem] < M: sol += M-a[problem]
	print(sol)
