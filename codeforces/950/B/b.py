T = int(input())

def solve(N, F, K, a):
	if N == K: return "YES"
	F = a[F-1]
	a = sorted(a, reverse=True)
	if a[K-1] < F: return "YES"
	if a[K-1] > F: return "NO"
	if a[K]==F: return "MAYBE"
	return "YES"
	

for test in range(T):
	N, F, K = [int(x) for x in input().split(' ')]
	a = [int(x) for x in input().split(' ')]
	print(solve(N, F, K, a))

